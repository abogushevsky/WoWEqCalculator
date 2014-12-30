//
//  BNetApiDataLoader.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 29.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#include <iostream>
#include <boost/asio.hpp>
#include "BNetApiDataLoader.h"

using namespace boost;
using namespace boost::asio;
using namespace std;

IDataLoader::~IDataLoader() {};

vector<Realm> IDataLoader::loadRealms() {
    cout << "This is BNetApiDataLoader" << endl;
    
    return vector<Realm>(0);
}
