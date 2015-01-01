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

vector<Realm> IDataLoader::loadRealms() {
    string *realmsJson = this->_webClient->get(REALMS_LIST_URL);
    
    if (realmsJson) {
        //parse & save to mongo
        delete (realmsJson);
    }
    
    return vector<Realm>(0);
}

BNetApiDataLoader::BNetApiDataLoader(IWebClient *webClient) {
    if (!webClient) {
        throw std::invalid_argument("webClient");
    }
    
    this->_webClient = webClient;
}
