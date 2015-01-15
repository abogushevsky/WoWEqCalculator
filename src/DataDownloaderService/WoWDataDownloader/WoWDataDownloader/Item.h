//
//  Item.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 24.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__Item__
#define __WoWDataDownloader__Item__

#include <string>
#include "Dictionaries.h"

struct WeaponInfo {
    float damageExactMax;
    float damageExactMin;
    float damageMax;
    float damageMin;
    float dps;
    float speed;
};

struct Item {
    int id;
    DictionaryItem* bonusStats;
    float buyPrice;
    int containerSlots;
    std::string name;
    std::string description;
    bool equippable;
    bool hasSockets;
    bool isAuctionable;
    int itemBind; //maybe enum?
    ItemClass itemClass;
    ItemClass itemSubclass;
    int itemLevel;
    //Spell itemSpell;
    int maxDurability;
    int nameDescriptionColor;
    int requiredLevel;
    int requiredScill;
    bool stackable;
    bool upgradable;
    WeaponInfo weaponInfo;
};

#endif /* defined(__WoWDataDownloader__Item__) */
