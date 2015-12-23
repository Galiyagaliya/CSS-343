//
//  InventoryManager.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#include "inventorymanager.h"
//----------------------InventoryManager()---------------------------------------------------

// Proccess file  line by line. Send each line to the moviefactory
// where creates different objects of Movie after, the objects will be insreted to a specific
// BSTree
// if object are unkonw types, add it to error history

void InventoryManager::processInventory(ifstream& infile) {
    
    count = 0;                                    // counts unkown movies
    string s;                                     // hold movie information
    
    for (;;) {
        
        getline(infile, s);                       // insert info into string
        if (infile.eof()) break;                  // no more lines of data
        
        Movie* a = MovieFactory::createMovie(s);  // pointer to the object movie
        
        switch (s[0])                             // check what object type to insert curent movie
        {
            case Drama::MyType:
                dramaBST.insertBinary(a);             // insert Drama movie
                break;
            case Comedy::MyType:
                comedyBST.insertBinary(a);            // insert Comedy movie
                break;
            case  Classics::MyType:
                classicsBST.insertBinary(a);          // insert Classics movie
                break;
            default:
                addError(s);                          // add unkown movie
                break;
        }
    }
    displayErrors();                              // display errors
}
//---------------------------------retrieveMovie()----------------------------------------


// retrieve Movie from appropriate BSTree using its type.

Movie* InventoryManager::retriveMovie(Movie* temp, char type)  {
    // use swith case to find appropriate Tree
    switch (type)
    {
        case 'D':
            return dramaBST.retrieve(temp);
            break;
        case 'F':
            return comedyBST.retrieve(temp);
            break;
        case 'C':
            return classicsBST.retrieve(temp);
            break;
        default:
            break;
    }
    return NULL;
}

//-----------------------------------displayAll()--------------------------------------

// display all BSTree (Comedy,Drama,Classics).
void InventoryManager::displayAll()
{
    cout << endl;
    cout << "=============================================================================" << endl;
    cout << "                                Display Comedies " << endl;
    cout << "=============================================================================" << endl;
    cout << " Title                           Year Director          Stock" << endl;
    comedyBST.displayAll();
    cout << "============================================================================" << endl;
    cout << "                                Display Dramas " << endl;
    cout << "============================================================================" << endl;
    cout << " Director             Title                    Year     Stock" << endl;
    dramaBST.displayAll();
    cout << "============================================================================" << endl;
    cout << "                                Display Classics " << endl;
    cout << "============================================================================" << endl;
    cout << " Month  Year  Major actor        Title                  Director       Stock" << endl;
    classicsBST.displayAll();
    cout << "============================================================================" << endl;
    cout << endl << endl;
}

//---------------------------------------addError()----------------------------------

// collects errors that has been detected during movie creating
//store error into string errorCollegector

void InventoryManager::addError(string error)
{
    count++;
    ostringstream temp;
    temp << count;
    errorCollector += temp.str() + ") ";
    errorCollector += error;
    errorCollector += "\n";
}

//-------------------------------------displayErrors()------------------------------------


// displays all errors that appears during the movies file reading
void InventoryManager::displayErrors() const {
    cout << endl;
    cout << "=============================================================================" << endl;
    cout << "                                Invalid movie report" << endl << endl;
    cout << errorCollector;
    cout << endl;
    cout << "=============================================================================" << endl;
    
}