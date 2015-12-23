//
//  storemanager.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "storemanager.h"
//-----------------------------------buildStore()---------------------------------------

// invokes inventory and customer manager to build data base for movie and customers
// takes two parameters: ifstream refrences movie_DB,
//  ifstream refrences customer_DB.
void StoreManager::buildStore(ifstream& movie_DB, ifstream& customer_DB) {
    inventory_object.processInventory(movie_DB);
    customer_object.proccessCustomer(customer_DB);
}

//----------------------------------commnadsReader()----------------------------------------

// invokes ComandLoader  (command_object) to read commands
// takes one parameter: ifstream refrences commands
void StoreManager::commandsReader(ifstream& commands) {
    command_object.commandsReader(commands,customer_object,inventory_object);
}

