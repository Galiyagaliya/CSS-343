//
//  BSTree.cpp
//  VideoStore
//
//  Created by Galiya Shakenova on 13.12.15.
//  Copyright © 2015 Galiya Shakenova. All rights reserved.
// --------------------------------------------------------------------------------------------------------------------
// Constructs a binary search tree along with some additional functions
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// -- BinTree is not tied to any particular data type

//
// --------------------------------------------------------------------------------------------------------------------
//

#include "BSTree.h"

// ---------------------------------------------Constructor------------------------------------------------------------//
// default constructor
// sets root to NULL
BinTree::BinTree()
{
    root = NULL;
    movieID = 0;
}


// ---------------------------------------------Destructor------------------------------------------------------------
BinTree::~BinTree()
{
    // check if BinTree is already empty
    if (isEmpty())
    {
        return;
    }
    // call method makeEmpty()
    makeEmpty();
}

// ---------------------------------------------makeEmpty()------------------------------------------------------------

// Empties the BST
void BinTree::makeEmpty()
{
    
    makeEmptyHelper(root);
}

// ---------------------------------------------makeEmptyHelper()-----------------------------------------------------

// recursivly deletes data and nodes of Bintree
// one parameter: pointer (*) refrences (&) to a node
void BinTree::makeEmptyHelper(Node* & node) {
    
    if (node == NULL)
    {
        return;
    }       // return if node == NULL
    // make recursive calls
    makeEmptyHelper(node->left);        // left node
    makeEmptyHelper(node->right);       // right node
    delete node->data;                  // delete data
    node->data = NULL;                  // set data to NULL
    delete node;                        // delte root
    node = NULL;                        // set root to NULL
}


// ---------------------------------------------isEmpty()------------------------------------------------------------
// Returns true if the BST is empty; otherwise, false
bool  BinTree::isEmpty() const
{
    return (root == NULL);
}

//---------------------------------------------- operator<<----------------------------------------------------------

// overloaded <<: outputs contents of BST inorder
void BinTree::displayAll() {
    inorderDisplay(root);
    cout << endl;
}

//----------------------------------------------inorderDisplay()---------------------------------------------------------

// helper method for operator<<()
// displays the BinTree in inorder traversal

void BinTree::inorderDisplay(Node* node) const
{
    //base case:

    if (node == NULL)
    {
        return;
    }
    // recurisve call on the left and right sides of the tree
    inorderDisplay(node->left);  // left
    cout << node->data->printInfo();
    inorderDisplay(node->right); // right
}
//---------------------------------------------- retrieve()---------------------------------------------------------------
// gets the NodeData* of a given object in the tree (via pass-by-reference parameter), reports whether the object is
// found (tree or false).
Movie* BinTree::retrieve(const Movie* find_data)
{
    // call helper method retriveBSTreeElemenet()
    return retriveBSTreeElement(root, find_data);
}

//-----------------------------------------------retriveBSTreeElement()--------------------------------------------------

// helper method for retrive()

Movie* BinTree::retriveBSTreeElement(Node*& node, const Movie* find_data) const {
    // base case 01:
    //check if root is null
    if (node == NULL) {
        return  NULL;        // refrenses input_data
    }
    // base case 02:
    // check if root contains the same data
    if (node->data->isEqual( find_data)) {
        return node->data;  // refrenses input_data
    }
    // do binary search:
    // if find_data is more than node->data go left
    else if (node->data->isGreater(find_data)){
        return retriveBSTreeElement(node->left, find_data);
    }
    // if find data is less than node->data go right
    else {
        return retriveBSTreeElement(node->right, find_data);
    }
}


//-----------------------------------------------insertBinary()-----------------------------------------------------

// insert data into tree resusively
// one parameter: pointer to the object Nodedata *
bool BinTree::insertBinary(Movie* data) {
    return insertBinaryHelper(root, data);
}

//------------------------------------------------insertBinaryHelper()----------------------------------------------

// helper method for insertBinary
// resursivly insert data into tree
bool BinTree::insertBinaryHelper(Node*& new_node, Movie* data) {
    // base case 1:
    // found  right spot for a node
    if (new_node == NULL) {
        new_node = new Node();
        new_node->data = data;
        new_node->left = new_node->right = NULL;
        return true;
    }
    // base case 2:
    // attempt to inser duplicate
    // no dublicates allowed
    if (new_node->data->isEqual(data)) {
        
        bool new_stock = new_node->data->increaseStock(data->getStock()); // increase the stock
        delete data;                                                      // delete diplicate
        data = NULL;
        return new_stock;
    }
    if (new_node->data->isGreater(data)) {
        return insertBinaryHelper(new_node->left, data);
    }
    else {
        return insertBinaryHelper(new_node->right, data);
    }
}

////--------------------------------------------------------------------------