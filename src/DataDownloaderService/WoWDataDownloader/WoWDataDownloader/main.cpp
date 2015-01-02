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
#include "IDataLoader.h"
#include "BNetApiDataLoader.h"
#include "RestClient.h"

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
    
    IWebClient *client = new RestClient();
    std::string *requestResult = client->get("eu.battle.net/api/wow/realm/status");
    if (requestResult) {
        std::cout << "RESULT: " << *requestResult;
    }
    
    delete requestResult;
    delete client;
    
    //IDataLoader *loader = new BNetApiDataLoader(new RestClient());
    //loader->loadRealms();
    
    return 0;
}