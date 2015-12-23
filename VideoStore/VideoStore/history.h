//
//  history.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef history_h
#define history_h

#include <stdio.h>
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
#include "transaction.h"
using namespace std;
//--------------------------  class History -----------------------------------------
// ADT Histroy: child class of Transaction.  Displays histroy for a given
//    cusomter. In other words, displays all customer transactions.
//
// Implementation and assumptions:
//   -- Implement as a child class of Transaction
//   -- Implement with following futures:
//      proccessTransaction()
//----------------------------------------------------------------------------------

class History : public Transaction {
public:
    History();                       // constructor
    ~History();                      // destructor
    virtual void proccessTransaction(string, CustomerManager&, InventoryManager&);
    // proccess transaction
    static const char MyType = 'H';  // static indentifier for a class
};
#endif /* history_h */
