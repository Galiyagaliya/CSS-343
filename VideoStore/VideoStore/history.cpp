//
//  history.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.

/*  history.cpp purpose is to display all of the customers history if it is passed
 * a non-null customer object
 */

#include "history.h"
//---------------------------------Constructor-----------------------------------------

History::History() {
    errorCollector = "";
}

//-----------------------------------Destructor---------------------------------------

History::~History() {
    
}

//-----------------------------------proccessTransaction-------------------------------

// read the line. From the line gets customer ID tries to retrieve the customer, if
// customer exist - prints customer hsitory

void History::proccessTransaction(string line, CustomerManager& cus_mang,
                                  InventoryManager& inv_mang)
{
    
    int customer_id;            // hold customer id
    Customer * customer = NULL; // hold pointer to the object customer
    
    stringstream ss;            // string reader
    ss << line;                 // insert string into reader
    
    ss >> customer_id;
    customer = cus_mang.getCustomer(customer_id);     // get pointer to the customer
    if (checkValidCustomer(customer, customer_id)) {  // check if customer exist
        customer->movieHistory();                     // print customer history
    }
}