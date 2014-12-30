//
//  BNetApiDataLoader.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 29.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__BNetApiDataLoader__
#define __WoWDataDownloader__BNetApiDataLoader__

#include <vector>
#include "IDataLoader.h"
#include "RestClient.h"

class BNetApiDataLoader : public IDataLoader {
private:
    RestClient _restClient;
    
public:
    ~BNetApiDataLoader() {};
    BNetApiDataLoader() {};
};

#endif /* defined(__WoWDataDownloader__BNetApiDataLoader__) */
