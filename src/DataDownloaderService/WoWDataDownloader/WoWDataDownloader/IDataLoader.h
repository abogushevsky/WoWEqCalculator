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
#include "Item.h"
#include "Realm.h"
#include "BatchLoadResult.h"

class IDataLoader {
public:
    virtual ~IDataLoader();
    virtual void loadRealms() = 0;
    virtual BatchLoadResult loadItems(int fromId, int toId) = 0;
    virtual BatchLoadResult loadItemClasses() = 0;
};

#endif
