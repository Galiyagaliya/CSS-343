//
//  transactionfactory.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#include "transactionfactory.h"
#include <stdio.h>
//-------------------------------------creatTransaction()------------------------------------
// static method returns the pointer to a trasaction object
// takes one parameter: const cahr refrences type
Transaction* Transactionactory::creatTransaction(const char& type) {
    Transaction  * tran = NULL;  // pointer to Transaction
    switch (type)                // get first character of  string array
    {
        case Borrow::MyType:
            tran = new Borrow();     // allocate Borrow
            break;
        case Return::MyType:
            tran = new Return();     // allocate Return
            break;
        case History::MyType:
            tran = new History();    // allocate History
            break;
        case Inventory::MyType:
            tran = new Inventory();  // allocate Inventory
            break;
        default:
            tran = NULL;             // allocate NULL
            break;
    }
    return tran;                 // return tran
}
