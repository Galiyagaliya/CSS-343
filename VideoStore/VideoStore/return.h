//
//  return.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef return_h
#define return_h

#include <stdio.h>
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
#include "transaction.h"
using namespace std;
//--------------------------  class Return ----------------------------------
// child class of Transaction. Rerurns movie from customer
// and update the inventoryManager
//
// Implementation and assumptions:
//   -- Implement as a child class of Transaction
//   -- Implement with following futures:
//      proccessTransaction(), proccessReturn(), readTransaction()
//---------------------------------------------------------------------------
class Return : public Transaction {
public:
    Return();                 // constractor
    ~Return();                // destructor
    static const char MyType = 'R';  // static indentifier for a class
    virtual void proccessTransaction(string, CustomerManager&, InventoryManager&); // proccess Transaction
protected:
    void proccessReturn(Customer*, Movie*, Movie*);   // helper method for proccessTransaction
    void readTransaction(string info, Customer* customer, InventoryManager& inv_mang); // helper method for proccesTranscation
};
#endif /* return_hp*/
