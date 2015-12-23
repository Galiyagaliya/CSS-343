//
//  customer.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//
/* customer.cpp holds all relavent information for the customer. This includes
* information used to identify a customer, handle rental information, handle
* transaction information, and handle history information. */

#include "customer.h"
//-----------------------------------Constructor---------------------------------------

Customer::Customer(){
    plus_One = 1;
}

//-----------------------------------Constructor---------------------------------------

// copy constructor
Customer::Customer(int id, string last, string first) {
    plus_One = 1;
    customer_ID = id;
    FirstName = first;
    lastName = last;
    head = NULL;
    logHead = NULL;
}

//-----------------------------------Destructor---------------------------------------


Customer::~Customer() {
    // delete history
    List * del = head;
    while (del != NULL) {
        head = head->next;
        del->info = NULL;
        delete del;
        del = head;
    }
    // delete transaction log
    TransactionLog * delLog = logHead;
    while (delLog != NULL) {
        logHead = logHead->next;
        delLog->movie = NULL;
        delete delLog;
        delLog = logHead;
    }
    // emprty vector
    print_array.clear();
}

//----------------------------------------getMyID()------------------------------------
// return id of  current customer
int Customer::getMyID() const {
    return customer_ID;
}

//---------------------------------------addTransaction()-----------------------------------

// add tranactions into history log (string)

bool Customer::addTransaction(const char type, Movie* movie ) {
    
    List * ptr = new List;        // allocate new ptr
    ptr->transaction = type;      // point to transaction type
    ptr->info = movie;            // point to the movie
    ptr->next = NULL;             // next is null
    
    // first transaction,
    // first pointer in the list
    if (head == NULL) {
        ptr->next = head;
        head = ptr;
    }
    else {
        List * current = head;
        // loop until the las elemenet in the list
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = ptr;  //  add ptr to a list
    }
    return true;
}

//-----------------------------------movieBorrow()---------------------------------------

// borrow movie and save tranaction into customer history
// checks if movie has empty stock and borowing has been recored

bool Customer::movieBorrow( Movie* movie) {
    // check if stock is not empty
    // then  call borrowMovie to add to transaction log
    if (movie->getStock() != 0 && borrowMovie(movie)) {
        movie->dicreaseStock();             // dicrease stock by 1
        return addTransaction('B', movie);  // add movie to customer history
    }
    return false;
}

//----------------------------------- movieReturn()---------------------------------------

// check if movie has been borrowed and than saves it into customer history
bool Customer::movieReturn(Movie* movie) {
    // check if movie has been borrowed
    if (returnMovie(movie)) {
        movie->increaseStock(plus_One);    // increase stock
        return addTransaction('R', movie); // add movie to customer history
    }
    return false;
}

//--------------------------------------pritnHistory()------------------------------------

//// void type method:
//// Prints customer history of borrowing and returning movies.
void Customer::movieHistory() {
    cout << endl;
    cout << "=============================================================================" << endl;
    cout << getCustomerInfo() << endl << "History:" << endl;
    List * current = head;
    // traverse linkd list
    while (current != NULL)
    {   // insert info into vector
        if (current->transaction == 'B') {
            print_array.push_back("Borrow" + current->info->printInfoForCustomer());
        }
        else {
            print_array.push_back("Return" + current->info->printInfoForCustomer());
        }
        current = current->next;
    }
    
    vector<string>::reverse_iterator it; // print the history from the earliest to oldest
    for (it = print_array.rbegin(); it != print_array.rend(); ++it) {
        cout << *it << endl;          // print history
    }
    cout << "=============================================================================" << endl;
    cout << endl;
}

//------------------------------------getCustomerInfo()--------------------------------------


// return string with information about customer
string Customer::getCustomerInfo() {
    ostringstream stringStream;
    stringStream << "Customer ID " << customer_ID << ": " << lastName << " " << FirstName;
    return  stringStream.str();
}

//------------------------------------- borrowMovie()-------------------------------------

// insert transaction into transaction log

bool Customer::borrowMovie(Movie* borrowed_movie) {
    
    TransactionLog * ptr = new TransactionLog;
    ptr->movie = borrowed_movie;
    ptr->next = NULL;
    
    // first transaction,
    // first pointer in the list
    if (logHead == NULL) {
        ptr->next = logHead;
        logHead = ptr;
    }
    else {
        TransactionLog * current = logHead;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = ptr;
    }
    return true;
}

//-----------------------------------returnMovie()-----------------------------------------

// check if passed movie contains in current log
// if movies exist, deletes information that  movie has been borrowed
bool Customer::returnMovie(Movie * dataptr) {
    
    //check if head is null
    if (logHead == NULL){
        return false;
    }
    

    TransactionLog * current = logHead->next;
    TransactionLog * priv = logHead;
    //check first node
    if (priv->movie->isEqual(dataptr))
    {
        //lose found node and recconect
        //LinkiedList with point before and
        //after removed node
        priv->movie = NULL;     // lose pointer
        delete priv;            // delete pointer
        logHead = current;
        return true;
    }
    
    while (current != NULL) {
        
        //same as before
        if (current->movie->isEqual(dataptr))
        {
            priv->next = current->next;
            current->movie = NULL;
            delete  current;
            return true;
        }
        
        //move
        priv = current;
        current = current->next;
    }
    //not found
    return false;
}

