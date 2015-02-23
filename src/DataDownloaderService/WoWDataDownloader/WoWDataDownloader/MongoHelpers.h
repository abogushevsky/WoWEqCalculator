//
//  MongoHelpers.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 23.02.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__MongoHelpers__
#define __WoWDataDownloader__MongoHelpers__

#include <mongo/bson/bson.h>
#include "Dictionaries.h"
#include "Item.h"

using namespace mongo;

inline mongo::BSONObj weaponInfoToBson(const WeaponInfo& wi) {
    BSONObjBuilder builder;
    
    builder.append("damageMin", wi.damageMin);
    builder.append("damageMax", wi.damageMax);
    builder.append("damageExactMin", wi.damageExactMin);
    builder.append("damageExactMax", wi.damageExactMax);
    builder.append("dps", wi.dps);
    builder.append("speed", wi.speed);
    
    return builder.obj();
}

inline mongo::BSONObj DictionaryItemToBson(const DictionaryItem& di) {
    BSONObjBuilder builder;
    
    return builder.obj();
}

inline mongo::BSONObj itemClassToBson(const ItemClass& ic) {
    BSONObjBuilder builder;
    
    return builder.obj();
}

inline mongo::BSONObj itemToBson(const Item& item) {
    BSONObjBuilder builder;
    
    builder.append("_id", item.id);
    builder.append("bonusStats", DictionaryItemToBson(*item.bonusStats));
    builder.append("buyPrice", item.buyPrice);
    builder.append("containerSlots", item.containerSlots);
    builder.append("name", item.name);
    builder.append("description", item.description);
    builder.append("equippable", item.equippable);
    builder.append("hasSockets", item.hasSockets);
    builder.append("isAuctionable", item.isAuctionable);
    builder.append("itemClass", itemClassToBson(item.itemClass));
    builder.append("itemSubclass", itemClassToBson(item.itemSubclass));
    builder.append("itemLevel", item.itemLevel);
    builder.append("maxDurability", item.maxDurability);
    builder.append("nameDescriptionColor", item.nameDescriptionColor);
    builder.append("requiredLevel", item.requiredLevel);
    builder.append("requiredSkill", item.requiredSkill);
    builder.append("stackable", item.stackable);
    builder.append("upgradable", item.upgradable);
    builder.append("icon", item.icon);
    builder.append("weaponInfo", weaponInfoToBson(*item.weaponInfo));
    
    return builder.obj();
}

#endif /* defined(__WoWDataDownloader__MongoHelpers__) */
