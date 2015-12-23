//
//  comandLoader.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#include "comandloader.h"
////---------------------------------------Constructor------------------------------------

ComandLoader::ComandLoader() {
    
}

//--------------------------------------Destructor----------------------------------------

ComandLoader::~ComandLoader() {
    
}
//--------------------------------------commandsReader()-----------------------------------

//  Proccess file  line by line. Send each line to the transactionfactory where creates
// different pointer to the objects of Transaction.
// Then, proccess each transaction and then delete it.

void ComandLoader::commandsReader(ifstream & infile2, CustomerManager& cus_mang,
                                  InventoryManager& inv_mang)
{
    
    string temp;                                                       // temp string that holds variables
    Transaction * transction = NULL;                                   // pointer to transaction
    char type;
    for (;;) {
        infile2 >> type;                                               // insert the type
        transction = Transactionactory::creatTransaction(type);        // allocate new object
        if (infile2.eof()) break;                                      // no more lines of data
        switch (type)
        {
                // case Inventory
            case 'I':
                getline(infile2, temp);                                     // get transaction information
                transction->proccessTransaction(temp, cus_mang, inv_mang);  // proccess transaction
                invalid_transaction += transction->getErrors();             // add errors reports
                delete transction;                                          // delete transaction
                transction = NULL;                                          // NULL
                break;
                // case History
            case 'H':
                getline(infile2, temp);                                      // get transation information
                transction->proccessTransaction(temp, cus_mang, inv_mang);   // proccess transaction
                invalid_transaction += transction->getErrors();              // add errors reports
                delete transction;                                           // delete transaction
                transction = NULL;                                           // NULL
                break;
                // case Borrow
            case 'B':
                getline(infile2, temp);                                      // get transation information
                transction->proccessTransaction(temp, cus_mang, inv_mang);   // proccess transaction
                invalid_transaction += transction->getErrors();              // add errors reports
                delete transction;                                           // delete transaction
                transction = NULL;                                           // NULL
                break;
                // case Return
            case 'R':
                getline(infile2, temp);                                      // get transation information
                transction->proccessTransaction(temp, cus_mang, inv_mang);   // proccess transaction
                invalid_transaction += transction->getErrors();              // add errors reports
                delete transction;                                           // delete transaction
                transction = NULL;                                           // NULL
                break;
                // invalid transaction type
            default:
                getline(infile2, temp);                                      // get invalid movie info
                string a(1, type);
                invalid_transaction += "* Invalid transaction type: " + a +"\n";  // add invalid transaction
                break;
        }
    }
    delete transction;                                                  // delete transaction
    transction = NULL;                                                  // NULL
    displayErrors();                                                    // display all errors
}

//-------------------------------------------displayErrors()----------------------------------------------

// display all errors that appears during reading the transactions
void ComandLoader::displayErrors() const {
    cout << endl;
    cout << "=============================================================================" << endl;
    cout << "                                ERROR Report" << endl << endl;
    cout << invalid_transaction;
    cout << endl;
    cout << "=============================================================================" << endl;
    
}

