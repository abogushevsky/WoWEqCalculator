//
//  main.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 23.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#include <iostream>
#include "Item.h"
#include "Realm.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    Realm r = {
        "1",
        "2",
        "3",
        "4",
        RealmTypes::pve,
        RealmPopulations::low
    };
    
    return 0;
}
