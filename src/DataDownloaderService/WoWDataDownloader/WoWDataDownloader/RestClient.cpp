//
//  RestClient.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 31.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#include <iostream>
#include "RestClient.h"
#include <boost/asio.hpp>

using namespace boost;
using namespace boost::asio;
using namespace std;

IWebClient::~IWebClient() {
    
}

string IWebClient::get(string url) {
    cout << "Requesting: " << url << endl;
    io_service service;
    ip::tcp::resolver resolver(service);
    ip::tcp::resolver::query query(url, "http");
    ip::tcp::resolver::iterator iter = resolver.resolve(query);
    ip::tcp::resolver::iterator end;
    
    cout << "Trace for " << url << endl;
    
    ip::tcp::socket socket(service);
    boost::system::error_code error = boost::asio::error::host_not_found;
    while(error && iter != end) {
        ip::tcp::endpoint ep = *iter++;
        std::cout << ep.address().to_string() << std::endl;
        socket.close();
        socket.connect(ep, error);
    }
    
    if (error) {
        cout << "Error connecting to url!" << endl;
        throw boost::system::system_error(error);
    }
    
    boost::asio::streambuf request;
    ostream request_stream(&request);
    request_stream << "GET " << url << " HTTP/1.1\r\n";
    request_stream << "Host: " << url << "\r\n";
    request_stream << "Accept: */*\r\n";
    request_stream << "Connection: close\r\n\r\n";
    
    // Send the request.
    boost::asio::write(socket, request);
    
    // Read the response status line.
    boost::asio::streambuf response;
    boost::asio::read_until(socket, response, "\r\n");
    cout << &response;
    
    return "";
}


