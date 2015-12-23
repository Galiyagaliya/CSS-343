//
//  moviefactory.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef moviefactory_h
#define moviefactory_h

#include <stdio.h>
#include "movie.h"
#include "drama.h"
#include "comedy.h"
#include "classics.h"
#include <string>
#include "string.h"
#include <iostream>
#include <fstream>
using namespace std;
//-------------------------- MovieFactory -----------------------------------
// ADT MovieFactory: MovieFactory class uses factory method pattern to create
//        new moive form input string
//
// Implementation and assumptions:
//   -- Implement as factory method
//   -- Implement with following futures:
//      static poitner to the Movie createMovie()
//---------------------------------------------------------------------------
class MovieFactory {
public:
    static Movie* createMovie(const string&); // create pointer to the object Movie
};
#endif /* moviefactory_h */
