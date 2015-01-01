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

class BNetApiDataLoader : public IDataLoader {
private:
    const std::string REALMS_LIST_URL = "eu.battle.net/api/wow/realm/status";
    IWebClient *_webClient;
    
public:
    ~BNetApiDataLoader() {};
    BNetApiDataLoader(IWebClient *webClient);
};

#endif /* defined(__WoWDataDownloader__BNetApiDataLoader__) */
