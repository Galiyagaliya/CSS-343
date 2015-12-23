//
//  inventory.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef inventory_h
#define inventory_h

#include <stdio.h>
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
#include "transaction.h"
using namespace std;
//--------------------------  class Inventory -------------------------------
// ADT Inventory: child class of Transaction.  Displays  all
//    comedies, dramas, and classics movies of the store.
//
// Implementation and assumptions:
//   -- Implement as a child class of Transaction
//   -- Implement with following futures:
//      proccessTransaction()
//---------------------------------------------------------------------------

class Inventory : public Transaction {
public:
    Inventory();                     // constractor
    ~Inventory();                    // destructor
    virtual void proccessTransaction(string, CustomerManager&, InventoryManager&);  // proccess tranaction
    static const char MyType = 'I';  // static indentifier for a class
};

#endif /* inventory_h */
