//
//  movie.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef movie_h
#define movie_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;
//--------------------------  Movie --------------------------------------
// Abstract class Movie. Abstact class for child classes Drama,
// Comdedy, Classiscs. Can not be created. Used only for inheretance purpose.
// General movie contains information about title, director, year, and stock.
//
// Implementation and assumptions:
//   -- Implement as a abstract class
//   -- Implement with following futures:
//      printInfo(), printInfoForCustomer(), isEqual(), isGreater()
//---------------------------------------------------------------------------
class Movie {
public:
    
    virtual ~Movie() {};                // destructor
    virtual bool isEqual(const Movie* rhs) const = 0;   // pure virtual isEqual operator
    virtual bool isGreater(const Movie* rhs) const = 0; // pure virtual	isGreater operator
    virtual string printInfo() const = 0;               //  pure virtual printInfo
    virtual string printInfoForCustomer() const = 0;    // pure virtual printInfoForCustomer
    virtual bool increaseStock(int);    // increase stock
    virtual bool dicreaseStock();       // decrease stock
    virtual int getStock();             // return current stock
    
protected:
    
    Movie();                            // constractor (protected) to avoid diclaration of the object
    void loadString(const string&);     // helper mehtod for copy constractor
    
    //movie data
    char type;                          // hold type
    int stock;                          // hold stock
    string director;                    // hold director
    string title;                       // hold title
    int year;                           // hold year
    
};

#endif /* movie_h */
