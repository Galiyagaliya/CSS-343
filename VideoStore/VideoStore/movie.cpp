//
//  movie.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#include "movie.h"
//--------------------------------------------Constructor----------------------------------


Movie::Movie() {
    type = ' ';
    stock = 0;
    director ="";
    title = "";
    year = 0;
}

//---------------------------------------------loadString()--------------------------------


// Parse the string into a smaller pieces. From these pieces  assign inforamtion to a current movie
// takes one parameter: const stirng refrenseces info.
void Movie::loadString( const string& info) {
    stringstream ss;                 // string reader
    ss << info;                      // insert string info into reader
    string temp;                     //  temp string to parse the string
    getline(ss, temp, ',');          // get movie type
    type = temp[0];                  // assign movie type
    getline(ss, temp, ',');          // get stock
    stringstream ( temp ) >> stock;  // assign stock
    getline(ss, director, ',');      // assign director
    getline(ss, title, ',');         // assign title
    getline(ss, temp, ',');          // get year
    stringstream(temp) >> year;      // assign year
}

//-----------------------------------------increaseStock()---------------------------------

// increase stock of current movie
bool Movie::increaseStock(int addToStock) {
    if (addToStock < 0) { return false; }
    stock += addToStock;
    return true;
}

//------------------------------------------getStock()------------------------------------

// returns current stock of the movie
int Movie::getStock() {
    return stock;
}

//------------------------------------------dicreaseStock()--------------------------------

// dicrease current stock of the movie
// if stock is less or equal zero, stock will be the same
bool Movie::dicreaseStock() {
    if (stock <= 0) { return false; }
    stock--;    // dicrease sctock
    return true;
}
