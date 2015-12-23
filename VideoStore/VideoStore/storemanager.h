//
//  storemanager.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef storemanager_h
#define storemanager_h

#include <stdio.h>
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
#include "comandloader.h"
//--------------------------  StoreManager ----------------------------
//  Store Manager class: high leve manager for other manager
//  classes such as: CustomerManager, InventoryManager, ComandLoaderManager.
//
// Implementation and assumptions:
//   -- Implement as a manager class
//   -- Implement with following futures:
//      buildStore(), commadnsReader()
//---------------------------------------------------------------------------
class StoreManager {
public:
    void buildStore(ifstream&, ifstream&);               // build store by  creating movie and customer base
    void commandsReader(ifstream&);                      // proccess commands lines
private:
    CustomerManager customer_object;                     // Customer manager object
    InventoryManager inventory_object;                   // Inventroy manager object
    ComandLoader command_object;                         // comands  manager object
};


#endif /* storemanager_h */
