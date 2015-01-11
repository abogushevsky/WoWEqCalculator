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
#include "Realm.h"

class IJsonParser {
public:
    virtual ~IJsonParser();
    virtual std::vector<Realm> parseRealms(std::stringstream* jsonStream) = 0;
};

#endif
