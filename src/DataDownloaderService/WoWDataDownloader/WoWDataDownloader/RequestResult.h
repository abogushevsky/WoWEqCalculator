//
//  RequestResult.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 11.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#ifndef WoWDataDownloader_RequestResult_h
#define WoWDataDownloader_RequestResult_h

#include <vector>

struct RequestResult {
    unsigned int statusCode;
    std::string statusMessage;
    std::vector<std::string> headers;
    std::string content;
};

#endif
