//
//  WebClient.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 30.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#ifndef WoWDataDownloader_WebClient_h
#define WoWDataDownloader_WebClient_h

#include <string>
#include "RequestResult.h"

class IWebClient {
public:
    virtual ~IWebClient();
    virtual RequestResult* get(std::string url) = 0;
    
};

#endif
