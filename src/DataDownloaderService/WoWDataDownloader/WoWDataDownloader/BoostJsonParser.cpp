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

vector<Realm> BoostJsonParser::parseRealms(std::string* itemJson) {
    vector<Realm> result;
    
    //realms parsing not implemented yet. Maybe it is not needed at all.
    
    return result;
}

Item BoostJsonParser::parseItem(std::string* itemJson) {
    Item result;
    
    istringstream jsonStream(*itemJson);
    boost::property_tree::ptree propTree;
    boost::property_tree::read_json(jsonStream, propTree);
    
    //test code
    auto prop = propTree.get_child("id");
    result.id = prop.get_value<int>();
    
    return result;
}



