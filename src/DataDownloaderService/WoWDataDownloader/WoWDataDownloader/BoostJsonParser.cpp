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

vector<Realm> BoostJsonParser::parseRealms(stringstream* jsonStream) {
    vector<Realm> result;
    boost::property_tree::ptree propTree;
    boost::property_tree::read_json(*jsonStream, propTree);
    
    auto realms = propTree.get_child("realms");
    
    return result;
}