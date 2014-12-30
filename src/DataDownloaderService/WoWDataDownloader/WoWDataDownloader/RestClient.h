//
//  RestClient.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 30.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__RestClient__
#define __WoWDataDownloader__RestClient__

#include <string>

class RestClient {
public:
    std::string get(std::string url);
};

#endif /* defined(__WoWDataDownloader__RestClient__) */
