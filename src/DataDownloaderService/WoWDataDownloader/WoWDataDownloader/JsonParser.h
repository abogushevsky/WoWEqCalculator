//
//  JsonParser.h
//  WoWDataDownloader
//
//  Created by NamelessMobile on 02.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__JsonParser__
#define __WoWDataDownloader__JsonParser__

#include <iostream>

template <typename T>;
class JsonParser {
    T toObject(string *json);
};

#endif /* defined(__WoWDataDownloader__JsonParser__) */
