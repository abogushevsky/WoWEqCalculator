//
//  BNetApiDataLoader.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 29.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#include <iostream>
#include "BNetApiDataLoader.h"

using namespace std;

IDataLoader::~IDataLoader() {};

BNetApiDataLoader::~BNetApiDataLoader() {
    delete(this->_webClient);
    delete(this->_jsonParser);
}

BNetApiDataLoader::BNetApiDataLoader(IWebClient* webClient, IJsonParser* jsonParser) {
    if (!webClient) {
        throw std::invalid_argument("webClient");
    }
    if(!jsonParser) {
        throw std::invalid_argument("jsonParser");
    }
    
    this->_webClient = webClient;
    this->_jsonParser = jsonParser;
}

void BNetApiDataLoader::loadRealms() {
    RequestResult *realmsResult = this->_webClient->get(REALMS_LIST_URL);
    if (realmsResult) {
        //parse & save to mongo
        vector<Realm> realms = this->_jsonParser->parseRealms(*realmsResult->content);
        delete (realmsResult);
    }
}

void BNetApiDataLoader::loadItems(int fromId, int toId) {
    for (int i = fromId; i <= toId; i++) {
        string url = ITEM_INFO_URL + to_string(i);
        RequestResult* itemResult = this->_webClient->get(url);
        if (itemResult) {
            Item item = this->_jsonParser->parseItem(*itemResult->content);
            //save to mongo
            delete(itemResult);
        }
    }
}

void BNetApiDataLoader::loadItemClasses() {
    RequestResult *itemsClassesResult = this->_webClient->get(ITEM_CLASSES_URL);
    if(itemsClassesResult) {
        vector<ItemClass> itemClasses = this->_jsonParser->parseItemClasses(*itemsClassesResult->content);
        if(itemClasses.size() > 0) {
            //save to mongo
        }
        delete (itemsClassesResult);
    }
}
