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
#include <mongo/client/dbclient.h>
#include <mongo/bson/bson.h>

class MongoDbDataRepository : public IWowDataRepository {
private:
    bool _isClientInitialized;
    mutable std::once_flag _initFlag;
    
    std::string _connectionString;
    mongo::DBClientConnection _connection;
    
    void initClient() {
        mongo::Status initResult = mongo::client::initialize();
        if(!initResult.isOK()) {
            throw "Unable to init mongo client";
        } else {
            this->_connection.connect(this->_connectionString);
        }
    }
    
    template<typename TResult>
    inline TResult wrapDbCall(const std::function<TResult(mongo::DBClientConnection &connection)>& dbCall) {
        try {
            std::call_once(this->_initFlag, &MongoDbDataRepository::initClient, this);
            return dbCall(this->_connection);
        } catch(const mongo::DBException &e) {
            throw "Mongo ex";
        }
    }
    
public:
    MongoDbDataRepository(const std::string &connectionString);
    ~MongoDbDataRepository() {};
    void saveItem(Item& item);
    void saveItems(std::vector<Item>& items);
    void saveItemClass(ItemClass& itemClass);
};

#endif /* defined(__WoWDataDownloader__MongoDbDataRepository__) */
