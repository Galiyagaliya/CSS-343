//
//  customermanager.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef customermanager_h
#define customermanager_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include  "hashtable.h"
#include "customer.h"
using namespace std;
//--------------------------  class CusomerManager  -------------------------
// CustomerManager proccess customers: puts customers
//    into HashTble. CustomerManager can also retrieve the customer.
//
// Implementation and assumptions:
//   -- Implement as manager class
//   -- Implement with following futures:
//      proccessCustomer(), getCustomer()
//---------------------------------------------------------------------------
class CustomerManager {
public:
    
    CustomerManager();                   // constractor
    ~CustomerManager();                  // destructor
    void proccessCustomer(ifstream &);   // procees file with customers
    Customer* getCustomer(int id);       // return pointer to the Customer
private:
    
    HashTable table;                     // HashTable
};
#endif /* customermanager_h */
