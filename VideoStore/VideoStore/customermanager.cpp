//
//  customermanager.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#include "customermanager.h"
//----------------------------------Constructor--------------------------------------------


CustomerManager::CustomerManager() {
    
}

//---------------------------------Destructor-----------------------------------------------

CustomerManager::~CustomerManager() {
    
}

//---------------------------------proccessCustomer()-----------------------------------------

// Read the file and parse into a customer information
// then, based on the information insert customer into HashTable.
// takes one parameter: ifstream refrences file
void CustomerManager::proccessCustomer(ifstream& file) {
    

    for (;;) {
        
        int id;                                              // hold id
        string last;                                         // hold last name
        string first;                                        // hold first name
        string temp;                                         // hold space
        
        getline(file, temp, ' ');                            // get id
        stringstream(temp) >> id;                            // convert id to int
        getline(file, last, ' ');                            // get last name
        getline(file, first);                                // get first name
        
        if (file.eof()) break;                               // no more lines of data
        
        Customer *  ptr = new Customer (id, last, first);    // allocate new customer
        bool success = table.putCustomer(id, ptr);           // insert customer into HashTable
        if (!success)
            delete ptr;                                     // invalid case, not inserted
    }
}

//------------------------------------getCustomer()--------------------------------------


// return refrences to a pointer of the object customer, retriveing
// customer from hashtable

Customer*  CustomerManager::getCustomer(int id) {
    Customer *  customer = NULL;
    customer = table.getCustomer(id);              // rertieve customer from hashtable
    return customer;                                // return customer
}

