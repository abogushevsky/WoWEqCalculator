//
//  BatchLoadResult.h
//  WoWDataDownloader
//
//  Created by NamelessMobile on 17.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#ifndef WoWDataDownloader_BatchLoadResult_h
#define WoWDataDownloader_BatchLoadResult_h

#include <vector>

struct BatchLoadResult {
    BatchLoadResult() {
        this->loadedIds = std::vector<int>();
        this->failedIds = std::vector<int>();
    }
    
    int totalLoaded;
    int totalFailed;
    std::vector<int> loadedIds;
    std::vector<int> failedIds;
};

#endif
