//
//  Realm.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 28.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__Realm__
#define __WoWDataDownloader__Realm__

#include <stdio.h>
#include <string>

enum RealmPopulations { low, medium, hight };
enum RealmTypes { pve, rpve, pvp, rpvp };

//Class represent a WoW realm realm info with it's current status
struct Realm {
    std::string id;
    std::string locale;
    std::string name;
    std::string timezone;
    RealmTypes type;
    RealmPopulations population;
};

#endif /* defined(__WoWDataDownloader__Realm__) */
