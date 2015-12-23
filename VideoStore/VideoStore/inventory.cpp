//
//  inventory.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#include "inventory.h"
////-----------------------------------Constructor---------------------------------------


Inventory::Inventory() {
    errorCollector = "";
}

//-----------------------------------Destructor---------------------------------------

Inventory::~Inventory() {
    
}

//-----------------------------------proccessTransaction()---------------------------------------

// invokes the Inventory manager to print the current invetory for all movies in the store

void Inventory::proccessTransaction(string line, CustomerManager& cus_mang, InventoryManager& inv_mang) {
    inv_mang.displayAll();   // print all movies in the store
}

