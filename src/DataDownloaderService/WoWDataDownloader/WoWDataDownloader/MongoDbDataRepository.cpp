//
//  MongoDbDataRepository.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 16.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#include <iostream>

#include "MongoDbDataRepository.h"
#include "MongoHelpers.h"

using namespace std;

IWowDataRepository::~IWowDataRepository() {
    mongo::client::shutdown();
}

MongoDbDataRepository::MongoDbDataRepository(const string &connectionString) {
    if (connectionString.empty()) {
        throw invalid_argument("connectionString");
    }
    
    this->_connectionString = connectionString;
    //mongo::client::initialize();
}

void MongoDbDataRepository::saveItem(Item &item) {
    wrapDbCall<int>([&](mongo::DBClientConnection &connection) -> int {
        int result = 1;
        BSONObj itemBson = itemToBson(item);
        connection.insert("WowDb.items", itemBson);
        cout << "Object inserted";
        return result;
    });
}

void MongoDbDataRepository::saveItems(std::vector<Item> &items) {
    
}

void MongoDbDataRepository::saveItemClass(ItemClass &itemClass) {
    
}
