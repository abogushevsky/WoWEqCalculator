//
//  Dictionaries.h
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 15.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#ifndef WoWDataDownloader_Dictionaries_h
#define WoWDataDownloader_Dictionaries_h

#include <string>

struct DictionaryItem {
    int id;
    std::string name;
};

struct ItemClass : public DictionaryItem {
   ItemClass* subclasses;
 };

#endif
