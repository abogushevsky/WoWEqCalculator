//
//  Realm.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 28.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__Realm__
#define __WoWDataDownloader__Realm__

#include <stdio.h>
#include <string>

struct Realm {
    std::string id;
    std::string locale;
    std::string name;
};

#endif /* defined(__WoWDataDownloader__Realm__) */
