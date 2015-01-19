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
#include "IWowDataRepository.h"

class BNetApiDataLoader : public IDataLoader {
private:
    const std::string REALMS_LIST_URL = "eu.battle.net/api/wow/realm/status";
    const std::string ITEM_INFO_URL = "eu.battle.net/api/wow/item/";
    const std::string ITEM_CLASSES_URL = "eu.battle.net/api/wow/data/item/classes";
    const std::string IMAGE_URL_TEMPLATE = "http://media.blizzard.com/wow/icons/56/%s.jpg";
    
    IWebClient* _webClient;
    IJsonParser* _jsonParser;
    IWowDataRepository* _dataRepository;
    
    inline void writeSucceededToResult(int entityId, BatchLoadResult& result) {
        result.loadedIds.push_back(entityId);
        result.totalLoaded++;
    }
    
    inline void writeFailedToResult(int entityId, BatchLoadResult& result) {
        result.failedIds.push_back(entityId);
        result.totalFailed++;
    }
    
public:
    ~BNetApiDataLoader();
    BNetApiDataLoader(IWebClient* webClient, IJsonParser* jsonParser, IWowDataRepository* dataRepository);
    void loadRealms();
    BatchLoadResult loadItems(int fromId, int toId);
    BatchLoadResult loadItemClasses();
    BatchLoadResult loadBonusStats();
};

#endif /* defined(__WoWDataDownloader__BNetApiDataLoader__) */
