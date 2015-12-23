//
//  drama.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef drama_h
#define drama_h

#include <stdio.h>
#include <string>
#include "movie.h"
#include <iostream>
#include <fstream>
using namespace std;
//--------------------------  class Drama --------------------------------
// child class of Movie. Drama Movie sorts by director and title.
//
// Implementation and assumptions:
//   -- Implement as a child class of Movie
//   -- Implement with following futures:
//      printInfo(), printInfoForCustomer(), isEqual(), isGreater()
//---------------------------------------------------------------------------
class Drama : public Movie {
public:
    
    Drama(const string&);                          // copy constractor
    Drama(const string&, const string&);           // copy constractor
    virtual ~Drama();                              // destructor
    
    static const char MyType = 'D';                // static indentifier for a class
    
    virtual string printInfo() const;              // return string of full movie  info
    virtual string printInfoForCustomer() const;   // return string ifno for customer
protected:
    
    virtual bool isEqual(const Movie* rhs) const;  // operator=
    virtual bool isGreater(const Movie* rhs) const;// operator=>
    
};
#endif /* drama_h */
