//
//  BSTree.hpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
//

#ifndef BSTree_h
#define BSTree_h

#include <stdio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "movie.h"
#include "drama.h"
//--------------------------  class BSTree  --------------------------------
/* bintree.cpp contains all the implementations of functions and data members
* needed to create, modify, compare, and destroy a BST. Also, provded are
* functions to build array of NodeData* from the BST or turn BST into
* an array of NodeData*
*
* It is is not tied to any particular data type. It is assumed the user will
* provide implementation for NodeData which will determine the data to be
* acted upon. NodeData must have proper comparison operators to
* determine order of data in BST. NodeData will also need a member called
  data and a copy constructor. */

// Implementation and assumptions:
//   -- Implement as a binary search tree
//   -- default constructor set root to NULL
//   -- Implement with following futures:
//      retireve, getHight
//      makeEmpty, insert, displaySideways
//   -- BinTree doesn't contain duplicate data
//      duplicate  data deletes whithin insert method
//---------------------------------------------------------------------------
class BinTree {
    
public:
    int movieID;
    
    BinTree();							   // constructor
    ~BinTree();							   // destructor
    void makeEmpty();					   // empty out BinTree
    bool isEmpty() const;                  // true if tree is empty, otherwise false
    Movie * retrieve(const Movie*); // retrive data from BinTree
    bool insertBinary(Movie *);         // recurisve insert
    void displayAll();
    
private:
    struct Node {
        Movie* data;						// pointer to data object
        Node* left;							// left subtree pointer
        Node* right;						// right subtree pointer
    };
    Node* root;								// root of the tree
    
    //helpers
    void makeEmptyHelper(Node*&);            // helper for makeEmpty()
    void inorderDisplay(Node*) const; // helper for operator<<()
    Movie* retriveBSTreeElement(Node*&, const Movie*) const; // helper for retrive()
    bool insertBinaryHelper(Node*&, Movie*);
};


#endif /* BSTree_h */
