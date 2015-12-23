//
//  moviefactory.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#include "moviefactory.h"
//-----------------------------------MovieFactory()--------------------------------------

// static method returns the pointer to a Movie object

Movie * MovieFactory::createMovie(const string& a) {
    Movie *  movie = NULL;               //  pointer to movie
    switch (a[0])    // get first character of  string array
    {
        case Drama::MyType:
            movie =  (Movie*) new Drama(a);  // create Drama
            break;
        case Comedy::MyType:
            movie = (Movie*) new Comedy(a);  // create Comedy
            break;
        case Classics::MyType:
            movie = (Movie*) new Classics(a); // create Classics
            break;
        default:
            movie = NULL;                     // NULL
            
            break;
    }
    return movie;                          // return movie
}
