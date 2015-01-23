//
//  MongoDbDataRepository.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 16.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__MongoDbDataRepository__
#define __WoWDataDownloader__MongoDbDataRepository__

#include "IWowDataRepository.h"
#include "mongo/client/dbclient.h"
#include "mongo/bson/bson.h"


class MongoDbDataRepository : public IWowDataRepository {
public:
    ~MongoDbDataRepository() {};
    void saveItem(Item& item);
    void saveItemClass(ItemClass& itemClass);
};

#endif /* defined(__WoWDataDownloader__MongoDbDataRepository__) */
