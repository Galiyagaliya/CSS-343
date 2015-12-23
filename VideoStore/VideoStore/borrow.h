//
//  borrow.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef borrow_h
#define borrow_h

#include <stdio.h>
#pragma once
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
#include "customermanager.h"
#include "inventorymanager.h"
#include "transaction.h"
using namespace std;
//--------------------------  class Borrow ----------------------------------
// ADT Borrow: borrow.h contains all the declarations of functions and data members needed
// to modify data and display a borrow object.
// borrow inherits from transaction.

//
// Implementation and assumptions:
//   -- Implement as a child class of Transaction
//   -- Implement with following futures:
//      proccessTransaction, borrowMovie, readTransaction
//---------------------------------------------------------------------------
class Borrow : public Transaction {
public:
    
    Borrow();                 // constructor
    ~Borrow();                // destructor
    static const char MyType = 'B';                                                // static indentifier for a class
    virtual void proccessTransaction(string, CustomerManager&, InventoryManager&); // proccess Transaction
protected:
    
    void borrowMovie(Customer*, Movie*, Movie*);   // borrowed movie for customer
    void readTransaction(string info, Customer* customer, InventoryManager& inv_mang); // helper method for proccesTranscation
};
#endif /* borrow_h */
