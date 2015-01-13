//
//  BNetApiDataLoader.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 29.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__BNetApiDataLoader__
#define __WoWDataDownloader__BNetApiDataLoader__

#include <vector>
#include "IDataLoader.h"
#include "IWebClient.h"
#include "IJsonParser.h"

class BNetApiDataLoader : public IDataLoader {
private:
    const std::string REALMS_LIST_URL = "eu.battle.net/api/wow/realm/status";
    const std::string ITEM_INFO_URL = "eu.battle.net/api/wow/item/";
    
    IWebClient* _webClient;
    IJsonParser* _jsonParser;
    
public:
    ~BNetApiDataLoader();
    BNetApiDataLoader(IWebClient* webClient, IJsonParser* jsonParser);
    std::vector<Realm> loadRealms();
    std::vector<Item> loadItems(int fromId, int toId);
};

#endif /* defined(__WoWDataDownloader__BNetApiDataLoader__) */
