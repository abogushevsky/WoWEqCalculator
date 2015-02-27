//
//  BNetApiDataLoader.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 29.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#include <iostream>
#include <future>
#include "BNetApiDataLoader.h"

using namespace std;

IDataLoader::~IDataLoader() {};

BNetApiDataLoader::~BNetApiDataLoader() {
    delete(this->_webClient);
    delete(this->_jsonParser);
}

BNetApiDataLoader::BNetApiDataLoader(IWebClient* webClient, IJsonParser* jsonParser, IWowDataRepository* dataRepository) {
    if (!webClient) {
        throw std::invalid_argument("webClient");
    }
    if(!jsonParser) {
        throw std::invalid_argument("jsonParser");
    }
    if(!dataRepository) {
        throw std::invalid_argument("dataRepository");
    }
    
    this->_webClient = webClient;
    this->_jsonParser = jsonParser;
    this->_dataRepository = dataRepository;
}

void BNetApiDataLoader::loadRealms() {
    RequestResult *realmsResult = this->_webClient->get(REALMS_LIST_URL);
    if (realmsResult) {
        //parse & save to mongo
        vector<Realm> realms = this->_jsonParser->parseRealms(*realmsResult->content);
        delete (realmsResult);
    }
}

BatchLoadResult BNetApiDataLoader::loadItems(int fromId, int toId) {
    BatchLoadResult result;
    vector<future<ItemLoadResult>> futures;
    
    for (int i = fromId; i <= toId; i++) {
        futures.push_back(async([&](int i) -> ItemLoadResult {
            ItemLoadResult loadRes;
            loadRes.id = i;
            string url = ITEM_INFO_URL + to_string(i);
            RequestResult* itemResult = this->_webClient->get(url);
            if (itemResult) {
                try {
                    Item* item = this->_jsonParser->parseItem(*itemResult->content);
                    this->_dataRepository->saveItem(*item);
                    //this->writeSucceededToResult(i, result);
                    loadRes.succeeded = true;
                    delete(item);
                } catch (exception ex) {
                    cerr << &ex;
                    //this->writeFailedToResult(i, result);
                    loadRes.succeeded = false;
                }
            
                delete(itemResult);
            }
            
            return loadRes;
        }, i));
    }
    
    for (int i = 0; i < futures.size(); i++) {
        ItemLoadResult loadRes = futures[i].get();
        if (loadRes.succeeded) {
            this->writeSucceededToResult(loadRes.id, result);
        } else {
            this->writeFailedToResult(loadRes.id, result);
        }
    }
    
    return result;
}

BatchLoadResult BNetApiDataLoader::loadItemClasses() {
    BatchLoadResult result;
    RequestResult *itemsClassesResult = this->_webClient->get(ITEM_CLASSES_URL);
    
    if(itemsClassesResult) {
        vector<ItemClass> itemClasses = this->_jsonParser->parseItemClasses(*itemsClassesResult->content);
        if(itemClasses.size() > 0) {
            for (int i = 0; i < itemClasses.size(); i++) {
                try {
                    this->_dataRepository->saveItemClass(itemClasses[i]);
                    this->writeSucceededToResult(itemClasses[i].id, result);
                } catch (exception ex) {
                    cerr << &ex;
                    this->writeFailedToResult(itemClasses[i].id, result);
                }
            }
        }
        delete (itemsClassesResult);
    }
    
    return result;
}

BatchLoadResult BNetApiDataLoader::loadBonusStats() {
    BatchLoadResult result;
    
    return result;
}
