//
//  main.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 23.12.14.
//  Copyright (c) 2014 Anton Bogushevsky. All rights reserved.
//

#include <iostream>
#include <string>
#include "Item.h"
#include "Realm.h"
#include "IDataLoader.h"
#include "BNetApiDataLoader.h"
#include "RestClient.h"
#include "BoostJsonParser.h"
#include "MongoDbDataRepository.h"
#include "mongo/client/dbclient.h"
#include "mongo/bson/bson.h"

using namespace std;

void run() {
    mongo::DBClientConnection c;
    c.connect("localhost");
}

int main(int argc, const char * argv[]) {
    mongo::client::initialize();
    try {
        run();
        std::cout << "connected ok" << std::endl;
    } catch( const mongo::DBException &e ) {
        std::cout << "caught " << e.what() << std::endl;
    }
    return EXIT_SUCCESS;
    
    // insert code here...
    //std::cout << "Hello, World!\n";

    /*std::stringstream ss("test");
    ss << " 123 ";
    cout << ss.str();*/
    
    Realm r = {
        "1",
        "2",
        "3",
        "4",
        RealmTypes::pve,
        RealmPopulations::low
    };
    
   /* IWebClient *client = new RestClient();
    RequestResult *requestResult = client->get("eu.battle.net/api/wow/realm/status");
    if (requestResult) {
        cout << "Status code: " << requestResult->statusCode << endl;
        cout << "Status message: " << requestResult->statusMessage << endl;
        //TODO: iterate over earch header;
        cout << "Content: " << requestResult->content;
    }
    
    delete requestResult;
    delete client; */
    
    IDataLoader *loader = new BNetApiDataLoader(new RestClient(), new BoostJsonParser(), new MongoDbDataRepository());
    //loader->loadRealms();
    
    try {
        loader->loadItems(10000, 10001);
    }
    catch (exception &ex) {
        cerr << &ex;
    }
    
    return 0;
}
