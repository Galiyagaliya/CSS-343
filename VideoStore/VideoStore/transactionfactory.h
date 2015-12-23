//
//  transactionfactory.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef transactionfactory_h
#define transactionfactory_h

#include <stdio.h>
#include "transaction.h"
#include "borrow.h"
#include "return.h"
#include "history.h"
#include "inventory.h"
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
using namespace std;
//--------------------------  TransactionFactory -----------------------------------------
// TransactionFactory class uses factory method
// pattern to create new transaction
//
// Implementation and assumptions:
//   -- Implement as factory method
//   -- Implement with following futures:
//      static poitner to the Transaction createTransaction()
//-----------------------------------------------------------------------------------------

class Transactionactory {
public:
    static Transaction* creatTransaction(const char&);   // create pointer to the object Movie
};
#endif /* transactionfactory_h */
