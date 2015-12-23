//
//  transaction.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#include "transaction.h"
//-----------------------------------Constructor---------------------------------------

Transaction::Transaction() {
    errorCollector = "";
}
//------------------------------------proccessTransaction()----------------------------


void Transaction::proccessTransaction(string a, CustomerManager& b, InventoryManager& c)
{
    // do nothing
}
//------------------------------------checkValidCustomer()------------------------------

// check  whether customer was found or not
// check the pointer points somewhere

bool Transaction::checkValidCustomer(Customer * customer, int id)
{
    if (customer == NULL) {
        ostringstream stringStream;
        stringStream << id;
        addError("Invalid  Customer ID: " + stringStream.str()); // add invalid customer id
        return false;
    }
    return true;
}

//-------------------------------------addErrors()------------------------------------


// collects all errors that appears during the command reading
void Transaction::addError(string error) {
    errorCollector += "* ";
    errorCollector += error;
    errorCollector += "\n";
}

//-----------------------------------getErrors()--------------------------------------

// return the string of all erros that has been detected during file reading
string Transaction::getErrors() {
    return errorCollector;
}
