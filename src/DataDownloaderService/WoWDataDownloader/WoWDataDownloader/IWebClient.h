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

class IWebClient {
public:
    virtual ~IWebClient();
    virtual std::string get(std::string url);
};


#endif
