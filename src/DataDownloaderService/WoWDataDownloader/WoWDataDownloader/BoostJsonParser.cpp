//
//  BoostJsonParser.cpp
//  WoWDataDownloader
//
//  Created by Anton Bogushevsky on 11.01.15.
//  Copyright (c) 2015 Anton Bogushevsky. All rights reserved.
//

#include "BoostJsonParser.h"
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>

using namespace std;

IJsonParser::~IJsonParser() {};

static void test(istringstream &sss) {
    string shit;
    while(sss >> shit)
        cout << shit;
}

vector<Realm> BoostJsonParser::parseRealms(std::string* itemJson) {
    vector<Realm> result;
    //char test[1000000];
    /*while (jsonStream->read(test, 1) && test[0] != '\r') {
    while ((test = (char)jsonStream->get()) != '\r') {
        cout << test;
    }
    //cout << jsonStream->ignore(128, '\r').read(test, 1024);
    
    jsonStream->ignore(128, '\n').read(test, 1000000);
    //cout << test;
    
    string filePath = "/Users/namelessone//Development/test.txt";
    std::ofstream fileStr;
    fileStr.open(filePath, std::ios::app);
    fileStr << test << endl;
    fileStr.close();*/
    //cout << jsonStream;
    //string str = test;
    istringstream sss(*"{""id"":99994,""disenchantingSkillRank"":575,""description"":"""",""name"":""Tyrannical Gladiator's Treads of Alacrity"",""icon"":""inv_cloth_pvpwarlock_f_01boot"",""stackable"":1,""allowableClasses"":[8,5,9],""allowableRaces"":[2,2,5,5,6,6,8,8,9,10,26],""itemBind"":1,""bonusStats"":[{""stat"":57,""amount"":14},{""stat"":32,""amount"":21},{""stat"":5,""amount"":32},{""stat"":36,""amount"":22},{""stat"":7,""amount"":54}],""itemSpells"":[],""buyPrice"":1278913,""itemClass"":4,""itemSubClass"":1,""containerSlots"":0,""inventoryType"":8,""equippable"":true,""itemLevel"":496,""maxCount"":0,""maxDurability"":80,""minFactionId"":0,""minReputation"":0,""quality"":4,""sellPrice"":255782,""requiredSkill"":0,""requiredLevel"":90,""requiredSkillRank"":0,""socketInfo"":{""sockets"":[{""type"":""YELLOW""}],""socketBonus"":""+4 PvP Power""},""itemSource"":{""sourceId"":71621,""sourceType"":""VENDOR""},""baseArmor"":14,""hasSockets"":true,""isAuctionable"":false,""armor"":14,""displayInfoId"":119291,""nameDescription"":""Season 14"",""nameDescriptionColor"":""00ff00"",""upgradable"":true,""heroicTooltip"":false,""context"":"""",""bonusLists"":[],""availableContexts"":[""""],""bonusSummary"":{""defaultBonusLists"":[],""chanceBonusLists"":[],""bonusChances"":[]}}" + 0);
//    string shit;
    
  //  sss >> shit;
   // test(sss);
    boost::property_tree::ptree propTree;
    boost::property_tree::read_json(sss, propTree);
    
    //auto realms = propTree.get_child("realms");
    
    return result;
}

Item BoostJsonParser::parseItem(std::string* itemJson) {
    istringstream jsonStream(*itemJson);
    boost::property_tree::ptree propTree;
    boost::property_tree::read_json(jsonStream, propTree);
    
    return Item();
}



