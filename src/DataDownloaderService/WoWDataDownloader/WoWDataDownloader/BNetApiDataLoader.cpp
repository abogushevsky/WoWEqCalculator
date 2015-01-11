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

vector<Realm> BNetApiDataLoader::loadRealms() {
    RequestResult *realmsResult = this->_webClient->get(REALMS_LIST_URL);
    
    if (realmsResult) {
        //parse & save to mongo
        vector<Realm> realms = this->_jsonParser->parseRealms(realmsResult->content);
        delete (realmsResult);
    }
    
    return vector<Realm>(0);
}
