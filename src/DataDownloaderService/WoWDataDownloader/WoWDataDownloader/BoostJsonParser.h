//
//  BoostJsonParser.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 11.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__BoostJsonParser__
#define __WoWDataDownloader__BoostJsonParser__

#include "IJsonParser.h"

class BoostJsonParser : public IJsonParser {
public:
    ~BoostJsonParser() {};
    std::vector<Realm> parseRealms(std::stringstream* jsonStream);
};

#endif /* defined(__WoWDataDownloader__BoostJsonParser__) */
