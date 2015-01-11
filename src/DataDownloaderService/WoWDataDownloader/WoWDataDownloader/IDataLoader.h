//
//  IDataLoader.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 29.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#ifndef WoWDataDownloader_IDataLoader_h
#define WoWDataDownloader_IDataLoader_h

#include <vector>
#include <iostream>
#include <vector>
#include "Realm.h"

class IDataLoader {
public:
    virtual ~IDataLoader();
    virtual std::vector<Realm> loadRealms() = 0;
};

#endif
