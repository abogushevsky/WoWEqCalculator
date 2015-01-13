//
//  IJsonParser.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 11.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#ifndef WoWDataDownloader_IJsonParser_h
#define WoWDataDownloader_IJsonParser_h

#include <vector>
#include "Item.h"
#include "Realm.h"

class IJsonParser {
public:
    virtual ~IJsonParser();
    virtual std::vector<Realm> parseRealms(std::string* realmsJson) = 0;
    virtual Item parseItem(std::string* itemJson) = 0;
};

#endif
