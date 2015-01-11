//
//  RestClient.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 31.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#include <iostream>
#include <string>
#include "RestClient.h"
#include <boost/asio.hpp>

using namespace boost;
using namespace boost::asio;
using namespace std;

IWebClient::~IWebClient() {
    
}

RequestResult* RestClient::get(string url) {
    RequestResult *result = new RequestResult();
    
    string path;
    long firstSlashIndex = url.find('/');
    if (firstSlashIndex >= 0) {
        path = url.substr(firstSlashIndex);
        url = url.substr(0, firstSlashIndex);
    }
    
    io_service service;
    ip::tcp::resolver resolver(service);
    ip::tcp::resolver::query query(url, "http");
    ip::tcp::resolver::iterator iter = resolver.resolve(query);
    ip::tcp::resolver::iterator end;
    
    ip::tcp::socket socket(service);
    boost::system::error_code error = boost::asio::error::host_not_found;
    while(error && iter != end) {
        ip::tcp::endpoint ep = *iter++;
        socket.close();
        socket.connect(ep, error);
    }
    
    if (error) {
        cout << "Error connecting to url!" << endl;
        throw boost::system::system_error(error);
    }
    
    boost::asio::streambuf request;
    ostream request_stream(&request);
    request_stream << "GET " << path << " HTTP/1.1\r\n";
    request_stream << "Host: " << url << "\r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Connection: close\r\n\r\n";
    
    // Send the request.
    boost::asio::write(socket, request);
    
    // Read the response status line.
    boost::asio::streambuf response;
    boost::asio::read_until(socket, response, "\r\n");
    // Check that response is OK.
    istream response_stream(&response);
    string http_version;
    response_stream >> http_version;
    //unsigned int status_code;
    response_stream >> result->statusCode;
    string status_message;
    getline(response_stream, result->statusMessage);
    if (!response_stream || http_version.substr(0, 5) != "HTTP/")
    {
        //TODO: throw exception
        cout << "Invalid response\n";
    }
    if (result->statusCode != 200)
    {
        //TODO: throw exception
        cout << "Response returned with status code " << result->statusCode << "\n";
    }
    
    // Read the response headers, which are terminated by a blank line.
    boost::asio::read_until(socket, response, "\r\n\r\n");
    // Process the response headers.
    string header;
    while (getline(response_stream, header) && header != "\r") {
        result->headers.push_back(header);
    }
    
    // Write whatever content we already have to output.
    if (response.size() > 0) {
        (*result->content) << &response;
        //cout << &response;
    }
    
    // Read until EOF, writing data to output as we go.
    while (boost::asio::read(socket, response,
                             boost::asio::transfer_at_least(1), error)) {
        (*result->content) << &response;
    }
    /*if (error != boost::asio::error::eof)
        throw boost::system::system_error(error);*/
    
    return result;
}


