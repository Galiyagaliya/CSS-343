//
//  drama.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.

/*contains all the declarations of functions and data
 members needed to modify and display DramaMovie objects. Contains
 overloaded equality operators to determine sort order.
 Drama inherits from Movie. */

#include "drama.h"
#include <sstream>
//--------------------------------Constructor------------------------------------------

Drama::Drama(const string& str) {
    loadString(str);
}

//--------------------------------Constructor------------------------------------------

// Copy constractor
Drama::Drama(const string& new_title, const string& new_director) {
    title = new_title;
    director = new_director;
}

//-------------------------------Destructor---------------------------------------------

// Destructor
Drama::~Drama() {
    
}

//-------------------------------isEqual()--------------------------------------------

// compare current object Movie with other object Movie

bool Drama::isEqual (const Movie* rhs) const {
    const Drama* ptr_drama = (const Drama*)rhs;
    return ((title == ptr_drama->title) && (director == ptr_drama->director));
}

//---------------------------------isGreater()------------------------------------------

// compare current object Movie with other object Movie

bool Drama::isGreater(const Movie* rhs) const {
    const Drama* ptr_drama = (const Drama*)rhs;
    return ((director > ptr_drama->director) || ((director == ptr_drama->director) &&
                                                 (title > ptr_drama->title)));
}

//----------------------------------printInfo()----------------------------------------

// compose all information about the Movie into a string
string Drama::printInfo() const {
    ostringstream stringStream;
    stringStream << setw(21) << left << director << setw(21) << left << title;
    stringStream << setw(9) << right << year << setw(8) << right << stock << endl;
    return stringStream.str();
}

//---------------------------------printInfoForCustomer()--------------------------------
// compose inforamtion about movie with specific format for a customer history.
string Drama::printInfoForCustomer() const {
    ostringstream stringStream;
    stringStream << " drama: "<< director << " " << title;
    stringStream << " " << year;;
    return stringStream.str();
}

