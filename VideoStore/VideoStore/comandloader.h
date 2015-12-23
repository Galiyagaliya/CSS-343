//
//  comandLoader.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//


#pragma once
#include <stdio.h>

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "movie.h"
#include "inventorymanager.h"
#include  "customermanager.h"
#include "transactionfactory.h"
using namespace std;
//--------------------------  class ComandLoader ----------------------------------------
//  manager class for proccesesing commands (transaction)
//  Uses factory patern method for creating transactions.
//
// Implementation and assumptions:
//   -- Implement as manager class
//   -- Implement with following futures:
//      comandsReader(), displayErrors()
//---------------------------------------------------------------------------------------
class ComandLoader {
public:
    
    ComandLoader();                       // constractor
    virtual ~ComandLoader();              // destractor
    void commandsReader(ifstream&, CustomerManager&, InventoryManager&);  // read commands
    void displayErrors() const;                                           // display errors
private:
    
    string invalid_transaction;                                           // hold erros
};

