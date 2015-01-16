//
//  IWowDataRepository.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 16.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#ifndef __WoWDataDownloader__IWowDataRepository__
#define __WoWDataDownloader__IWowDataRepository__

#include "Item.h"
#include "Dictionaries.h"

class IWowDataRepository {
public:
    virtual ~IWowDataRepository() = 0;
    virtual void saveItem(Item& item) = 0;
    virtual void saveItemClass(ItemClass& itemClass) = 0;
};

#endif /* defined(__WoWDataDownloader__IWowDataRepository__) */
