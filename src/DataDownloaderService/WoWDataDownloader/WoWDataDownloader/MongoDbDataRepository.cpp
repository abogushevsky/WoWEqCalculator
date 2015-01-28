//
//  MongoDbDataRepository.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 16.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#include "MongoDbDataRepository.h"

using namespace std;

IWowDataRepository::~IWowDataRepository() {
    
}

MongoDbDataRepository::MongoDbDataRepository(const string &connectionString) {
    //TODO: check connectionString for null
    this->_connectionString = connectionString;
    mongo::client::initialize();
}

void MongoDbDataRepository::saveItem(Item &item) {
    
}

void MongoDbDataRepository::saveItemClass(ItemClass &itemClass) {
    
}
