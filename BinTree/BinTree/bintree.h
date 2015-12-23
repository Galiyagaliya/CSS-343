// Galiya Shakenova CSS 343 A
// Creation Date: 10/17/2015
// Date of Last Modification: 10/20/15
// --------------------------------------------------------------------------------------------------------------------
// implements Dijkstra's shortest path algorithm
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// -- reads a data file consisting of many lines
// -- displays the cost and path from every node to every other node
// -- the input data file has correctly formatted, valid data
// --------------------------------------------------------------------------------------------------------------------

//

#ifndef ____bintree__
#define ____bintree__

#include "nodedata.h"

class BinTree
{
    //Overloaded << operator: outputs contents of BST inorder
    friend ostream& operator<<(ostream&, const BinTree&);
    
public:
// ---------------------------------------------Constructor------------------------------------------------------------
    BinTree();
    BinTree(const BinTree&);
    
// ---------------------------------------------Destructor------------------------------------------------------------
    ~BinTree();

// ----------------------------------------Functions----------------------------------------------------------------
    void makeEmpty(); // empty the BST
    void displaySideways() const; // provided, displays the tree sideways
    void bstreeToArray(NodeData* []); // fill an array of Nodedata* by using an inorder traversal of the tree
    void arrayToBSTree(NodeData* []); // builds a balanced BinTree from a sorted array of NodeData* leaving
    // тhe array filled with NULLs
    
    bool insert(NodeData*); // insert NodeData to BST
    bool isEmpty() const; // returns true if tree is empty
    bool retrieve(const NodeData &, NodeData*&) const; // get the NodeData* of a given object in the tree
    // (via pass-by-reference parameter) and to report whether the object is found (tree or false)
    
    int getHeight(const NodeData &) const; // find height of data in BST
    

// ----------------------------------------Assignment operators---------------------------------------------------------

    BinTree& operator=(const BinTree&); // set a tree equal to passed tree
// ----------------------------------------Boolean comparison operators-------------------------------------------------
    bool operator==(const BinTree&) const; // returns true if this tree is equal to the passed tree
    bool operator!=(const BinTree&) const; // returns true if this tree is not equal to the passed tree
    
private:
    
//Struct holds pointers to data and left/right ancestors
    struct Node
    {
        NodeData* data; //Pointer to data contained in NodeData
        Node* leftChildPtr, *rightChildPtr; //Left/Right child pointers
    };
    
    Node *root; // root of the tree
    
// -------------------------------------Helper Functions----------------------------------------------------------------
    void retrieveHelper(Node*, const NodeData&, NodeData*&) const;
    void arrayToBSTreeHelper(NodeData* [], const Node*, int, int);
    void copyTree(Node*, Node*&) const; //Make a copy of BST
    void destroyTree(Node*&); //Destroys BST
    int totalHeight(Node*) const; // returns the height of the node
    void findNodePtr(Node*, const NodeData&, Node*&) const; // finds the node
    void inOrderDisplay(Node*) const; //Displays BST inorder
    bool isEqual(Node*, Node*) const; //Checks if two nodes equal
    void sideways(Node*, int) const; // provided, helper for displaySideways()
    int bstreeToArrayHelper(Node*, NodeData* []); // bstToArray helper
   
};

#endif /* defined(____bintree__) */
