//
//  classics.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef classics_h
#define classics_h

#include <stdio.h>
#pragma once
#include <string>
#include "movie.h"
using namespace std;
//--------------------------  class Classics ---------------------------------------------
/* contains all the declarations of functions and data
 members needed to modify and display ClassicMovie objects. Contains
 overloaded equality operators to determine sort order.
 ClassicMovie inherits from Movie.
 Also, classical movie sort by majoractor, month, and year  */


// Implementation and assumptions:
//   -- Implement as a child class of Movie
//   -- Implement with following futures:
//      printInfo(), printInfoForCustomer(), isEqual(), isGreater()
//   -- Assumption: each Classics movie that has same director, same
//      title, same year and month, but has different Major will be
//      considirate as a diffrent  classic movie.
//---------------------------------------------------------------------------------------
class Classics : public Movie {
public:
    
    Classics(const string&);                            // copy constructor
    Classics(const string&, const int&, const int&);    // copy constructor
    virtual ~Classics();                                // destructor
    
    static const char MyType = 'C';                     // static indentifier for a class
    
    virtual string printInfoForCustomer() const;        // return string ifno for customer
    virtual string printInfo() const;                   // return string of full movie  info
    
protected:
    
    void loadString(const string&);                     // helper method for reading info
    virtual bool isEqual(const Movie* rhs) const;       // operator=
    virtual bool isGreater(const Movie* rhs) const;     // operator>=
    
    int month;                                          // hold month
    string majorActor;                                  // hold majorActor
};
#endif /* classics_h */
