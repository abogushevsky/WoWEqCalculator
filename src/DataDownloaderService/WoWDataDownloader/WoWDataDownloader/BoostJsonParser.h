//
//  BoostJsonParser.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 11.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__BoostJsonParser__
#define __WoWDataDownloader__BoostJsonParser__

#include "IJsonParser.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

class BoostJsonParser : public IJsonParser {
private:
    WeaponInfo* parseWeaponInfo(boost::property_tree::ptree& propTree);
    
public:
    ~BoostJsonParser() {};
    std::vector<Realm> parseRealms(const std::string& json);
    Item* parseItem(const std::string& json);
    std::vector<ItemClass> parseItemClasses(const std::string& json);
};

#endif /* defined(__WoWDataDownloader__BoostJsonParser__) */
