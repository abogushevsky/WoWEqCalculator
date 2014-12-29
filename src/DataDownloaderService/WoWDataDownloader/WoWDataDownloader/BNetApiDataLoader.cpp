//
//  BNetApiDataLoader.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 29.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#include <iostream>
#include "BNetApiDataLoader.h"

IDataLoader::~IDataLoader() {};

std::vector<Realm> IDataLoader::loadRealms() {
    std::cout << "This is BNetApiDataLoader" << std::endl;
    return std::vector<Realm>(0);
}
