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
#include <sstream>

struct RequestResult {
    inline RequestResult() { this->content = new std::stringstream(); }
    unsigned int statusCode;
    std::string statusMessage;
    std::vector<std::string> headers;
    std::stringstream* content;
};

#endif
