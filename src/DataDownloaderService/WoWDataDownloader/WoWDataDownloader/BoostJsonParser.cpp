//
//  BoostJsonParser.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 11.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#include "BoostJsonParser.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;

IJsonParser::~IJsonParser() {};

static void test(istringstream &sss) {
    string shit;
    while(sss >> shit)
        cout << shit;
}

vector<Realm> BoostJsonParser::parseRealms(string* jsonStream) {
    vector<Realm> result;
    //char test[1000000];
    /*while (jsonStream->read(test, 1) && test[0] != '\r') {
    while ((test = (char)jsonStream->get()) != '\r') {
        cout << test;
    }
    //cout << jsonStream->ignore(128, '\r').read(test, 1024);
    
    jsonStream->ignore(128, '\n').read(test, 1000000);
    //cout << test;
    
    string filePath = "/Users/namelessone//Development/test.txt";
    std::ofstream fileStr;
    fileStr.open(filePath, std::ios::app);
    fileStr << test << endl;
    fileStr.close();*/
    //cout << jsonStream;
    //string str = test;
    istringstream sss(*jsonStream);
    string shit;
    
    sss >> shit;
    test(sss);
    boost::property_tree::ptree propTree;
    //boost::property_tree::read_json(sss, propTree);
    
    //auto realms = propTree.get_child("realms");
    
    return result;
}



