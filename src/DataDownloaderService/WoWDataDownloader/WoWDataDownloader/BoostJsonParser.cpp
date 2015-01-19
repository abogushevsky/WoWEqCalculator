//
//  BoostJsonParser.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 11.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#include "BoostJsonParser.h"

using namespace std;

IJsonParser::~IJsonParser() {};

vector<Realm> BoostJsonParser::parseRealms(const std::string& json) {
    vector<Realm> result;
    
    //realms parsing not implemented yet. Maybe it is not needed at all.
    
    return result;
}

Item* BoostJsonParser::parseItem(const std::string& json) {
    Item* result = new Item();
    
    istringstream jsonStream(json);
    boost::property_tree::ptree propTree;
    boost::property_tree::read_json(jsonStream, propTree);
 
    if(!propTree.empty()) {
        auto prop = propTree.get_child("id");
        result->id = prop.get_value<int>();
        result->icon = propTree.get<string>("icon");
        result->buyPrice = propTree.get<float>("buyPrice");
        result->containerSlots = propTree.get<int>("containerSlots");
        result->description = propTree.get<string>("description");
        result->equippable = propTree.get<bool>("equippable");
        result->hasSockets = propTree.get<bool>("hasSockets");
        result->isAuctionable = propTree.get<bool>("isAuctionable");
        result->itemBind = propTree.get<int>("itemBind");
        //result.itemClass = propTree.get_value<int>(0, "itemClass");
        result->itemLevel = propTree.get<int>("itemLevel");
        result->maxDurability = propTree.get<int>("maxDurability");
        result->name = propTree.get<string>("name");
        result->nameDescriptionColor = propTree.get<int>("nameDescriptionColor");
        result->requiredLevel = propTree.get<int>("requiredLevel");
        result->requiredScill = propTree.get<int>("requiredSkill");
        result->stackable = propTree.get<bool>("stackable");
        result->upgradable = propTree.get<bool>("upgradable");
        result->weaponInfo = parseWeaponInfo(prop);
    }
    
    return result;
}

vector<ItemClass> BoostJsonParser::parseItemClasses(const std::string& json) {
    vector<ItemClass> result;
    
    return result;
}

WeaponInfo* BoostJsonParser::parseWeaponInfo(boost::property_tree::ptree& propTree) {
    try {
        WeaponInfo* result = new WeaponInfo();
        auto prop = propTree.get_child("weaponInfo");
        if(!prop.empty()) {
            auto damageProp = prop.get_child("damage");
            if(!damageProp.empty()) {
                result->damageExactMax = damageProp.get<float>("exactMax");
                result->damageExactMin = damageProp.get<float>("exactMin");
                result->damageMax = damageProp.get<float>("max");
                result->damageMin = damageProp.get<float>("min");
            }
            result->dps = prop.get<float>("dps");
            result->speed = prop.get<float>("weaponSpeed");
            return result;
        }
    }
    catch(exception ex) {
        cerr << "Error parsing weapon info: " << &ex << endl;
    }
    
    return NULL;
}



