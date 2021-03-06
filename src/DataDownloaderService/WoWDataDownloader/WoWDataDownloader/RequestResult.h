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

struct RequestResultBase {
    unsigned int statusCode;
    std::string statusMessage;
    std::vector<std::string> headers;
};

struct RequestResult : public RequestResultBase {
    //inline RequestResult(); //{ this->content = new std::stringstream(); }
    inline ~RequestResult() { delete(this->content); }
    std::string* content;
};

struct ImageRequestResult : RequestResultBase {
    inline ~ImageRequestResult() { delete(this->image); }
    unsigned char* image;
};

#endif
