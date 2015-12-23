// Galiya Shakenova CSS 343 A
// Creation Date: 10/17/2015
// Date of Last Modification: 10/20/15
// --------------------------------------------------------------------------------------------------------------------
// Constructs a binary search tree along with some additional functions
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// -- BinTree is not tied to any particular data type
// -- Define two trees to be equal if they have the same data and same structure
// -- The NodeData class is responsible for displaying its own data
//
// --------------------------------------------------------------------------------------------------------------------

//

#include "bintree.h"

// ---------------------------------------------Constructor------------------------------------------------------------
// creates empty BST with root as NULL

BinTree::BinTree()
:root(NULL)
{ }

// Receives a reference to a BinTree object as its parameter, then creates an exact (deep) copy.

BinTree::BinTree(const BinTree& tree)
{
    copyTree(tree.root, root);
}

// ---------------------------------------------Destructor------------------------------------------------------------

// Destroys the entire BST

BinTree::~BinTree()
{
    makeEmpty();
}

//----------------------------------------------isEmpty()-------------------------------------------------------------

// Returns true if the BST is empty; otherwise, false

bool BinTree::isEmpty() const
{
    return (root == NULL);
}

//----------------------------------------------makeEmpty()-------------------------------------------------------------

// Empties the BST

void BinTree::makeEmpty()
{
    destroyTree(root); //destroy entire BST
}

// helper function to destroy the BST
void BinTree::destroyTree(Node *& treePtr)
{
    if (treePtr != NULL)
    {
        destroyTree(treePtr->leftChildPtr);
        destroyTree(treePtr->rightChildPtr);
        
        delete treePtr->data;
        treePtr->data = NULL;
        delete treePtr;
        treePtr = NULL;
    }
}



//---------------------------------------------- operator==-------------------------------------------------------------
//
// overloaded =: Make LHS become a deep copy of RHS BinTree object

BinTree& BinTree::operator=(const BinTree& rhs)
{
    if (this != &rhs)
    {
        destroyTree(root);  // deallocate left-hand side
        copyTree(rhs.root, root);  // copy right-hand side
    }
    return *this;
}

//---------------------------------------------- operator==-------------------------------------------------------------

// overloaded ==: Return true if two BST have same structure and data

// Defines two trees to be equal if they have the same data and same structure
bool BinTree::operator==(const BinTree& rhs) const
{
    if(root == NULL && rhs.root == NULL)
    {
        return true;
    }
    else
    {
        return isEqual(root, rhs.root);
    }
}

// helper functions that compare nodes of the tree
bool BinTree::isEqual(Node* left, Node* right) const
{
    
    //Check whether the node data is the same
    if ((left != NULL && right != NULL) && (*left->data == *right->data))
    {
        return true;
    }
    

    if ((left == NULL) || (right == NULL))
    {
        return false;
    }
    

    return ((left->data == right->data) && isEqual(left->leftChildPtr,  right->leftChildPtr )
            && isEqual (left->rightChildPtr, right->rightChildPtr));
}

//---------------------------------------------- operator!=-------------------------------------------------------------

// overloaded !=: Return true if two BST do NOT have same structure and data
// two trees are equal if they have the same data and same structure
bool BinTree::operator!=(const BinTree& rhs) const
{
    return !(*this == rhs);
}

//---------------------------------------------- insert()---------------------------------------------------------------
// Inserts a new Node* into BST


bool BinTree::insert(NodeData* newPtr)
{
    Node* ptr = new Node;    // exception is thrown if memory is not allocated
    ptr->data = newPtr; //Link to current NodeData
    newPtr = NULL;
    ptr->leftChildPtr = ptr->rightChildPtr = NULL;
    if (isEmpty())
    {
        root = ptr; //Empty, set as root
    }
    else
    {
        Node* current = root;
        bool insert = false;
        
        // if data is less than current data, insert in left subtree,
        // otherwise insert in right subtree
        while (!insert)
        {
            if (*ptr->data == *current->data) //Duplicate found, dont allow insert
            {
                delete ptr; //Handle duplicate properly
                ptr = NULL;
                return false;
            }
            else if (*ptr->data < *current->data)
            {
                if (current->leftChildPtr == NULL)
                {
                    current->leftChildPtr = ptr;
                    insert = true;
                }
                else
                    current = current->leftChildPtr;
            }
            else
            {
                if (current->rightChildPtr == NULL)
                {
                    current->rightChildPtr = ptr;
                    insert = true;
                }
                else
                {
                    current = current->rightChildPtr;
                }
            }
        }
    }
    return true;
}

//----------------------------------------------retrieve()---------------------------------------------------------------
//
// gets the NodeData* of a given object in the tree (via pass-by-reference parameter), reports whether the object is
// found (tree or false).

bool BinTree::retrieve(const NodeData & dataItem, NodeData*& dataFound) const
{
    retrieveHelper(root, dataItem, dataFound);
    
    if (dataFound != NULL) //Check is dataFound was changed
    {
        return true;
    }
    else
    {
        return false; //If dataFound was not found then return false
    }
}

// retrieve helper
void BinTree::retrieveHelper(Node* curPtr, const NodeData & dataItem, NodeData*& dataFound) const
{
    if (curPtr == NULL)
    {
        dataFound = NULL;
    }
    
    else if (dataItem == *curPtr->data)
    {
        dataFound = curPtr->data;
    }
    else if(dataItem < *curPtr->data)
    {
        retrieveHelper(curPtr->leftChildPtr, dataItem, dataFound);
    }
    else
    {
        retrieveHelper(curPtr->rightChildPtr, dataItem, dataFound);
    }
}

//---------------------------------------------- copyTree()---------------------------------------------------------------

// makes an exact copy of the BST


void BinTree::copyTree(Node *treePtr, Node *& newTreePtr) const
{
    // preorder traversal
    if (treePtr != NULL)
    {
        //Create new Node object for copy
        newTreePtr = new Node;
        //Create new NodeData* object for copy and use existing data
        NodeData *temp = new NodeData(*treePtr->data);
        newTreePtr->data = temp; //set data to be the same
        //go left in BST
        copyTree(treePtr->leftChildPtr, newTreePtr->leftChildPtr);
        //go right in BST
        copyTree(treePtr->rightChildPtr, newTreePtr->rightChildPtr);
    }
    else
    {
        newTreePtr = NULL;  // copy empty tree
    }
}


//---------------------------------------------- displaySideways()---------------------------------------------------------------
//
// Displays a binary tree as if you are viewing it from the side


void BinTree::displaySideways() const
{
    sideways(root, 0);
}

void BinTree::sideways(Node* current, int level) const
{
    if (current != NULL)
    {
        level++;
        sideways(current->rightChildPtr, level);
        
        
        for(int i = level; i >= 0; i--)
        {
            cout << "    ";
        }
        
        cout << *current->data << endl;      // display data
        sideways(current->leftChildPtr, level);
    }
}

//---------------------------------------------- getHeight()---------------------------------------------------------------

// finds the height of a given value in the tree
// the height of a node at a leaf is 1, height of a node at the next level is 2, and so on.  The height of a value not
// found is zero.

int BinTree::getHeight(const NodeData &data) const
{
    Node* ptr = NULL;
    findNodePtr(root, data, ptr);
    if(ptr != NULL)
    {
        return totalHeight(ptr);
    }
    return 0;
}

// the helper method finds the node data
void BinTree::findNodePtr(Node* n, const NodeData &data, Node*& TPtr) const
{
    if ( n != NULL )
    {
        findNodePtr(n->leftChildPtr, data, TPtr);
        
        if(*n->data == data)
        {
            TPtr = n;
        }
        
        findNodePtr(n->rightChildPtr, data, TPtr);
    }
}

// returns the height of the node
int BinTree::totalHeight(Node* node) const
{
    if(!node)
    {
        
        return 0;
    }
    return 1 + max(totalHeight(node->leftChildPtr), totalHeight(node->rightChildPtr));
}

//---------------------------------------------- bstreeToArray()---------------------------------------------------------------
//
// fills an array of Nodedata* by using an inorder traversal of the tree. It leaves the tree empty

void BinTree::bstreeToArray(NodeData* tempArray[])
{
    bstreeToArrayHelper(root, tempArray);
    makeEmpty(); //Make BST empty
}

// helper method to fill an array
int BinTree::bstreeToArrayHelper(Node* curPtr, NodeData *tempArray[])
{
    if(curPtr == NULL)
    {
        return 0;
    }
    
    int left = bstreeToArrayHelper(curPtr->leftChildPtr, tempArray);
    
    NodeData *temp;
    temp = curPtr->data; // save the pointer to NodeData object to temp
    curPtr->data = NULL; // disconnect NodeData from Node
    *(tempArray + left) = temp; //tempArray points to temp
    temp = NULL; //Disconnect
    
    //set location of right
    int right = bstreeToArrayHelper(curPtr->rightChildPtr, tempArray + left + 1);
    
    return left + right + 1; //Return position
}

//---------------------------------------------- arrayToBSTree()---------------------------------------------------------------
// builds a balanced BinTree from a sorted array of NodeData* leaving the array filled with NULLs.

void BinTree::arrayToBSTree(NodeData* tempArray[])
{
    int high = 0;
    
    for(int i = 0; i < 100; i++) //Count how many indexs of array are used
    {
        if (tempArray[i] != NULL)
        {
            high++;
        }
        else
        {
            tempArray[i] = NULL;
        }
    }
    
    
    arrayToBSTreeHelper(tempArray, root, 0, high-1);
}

// helper for arrayToBSTree()
void BinTree::arrayToBSTreeHelper(NodeData* tempArray[], const Node* curPtr, int low, int high)
{
    if (low > high)
    {
        curPtr = NULL;
    }
    else
    {
        int root = (low + high) / 2;
        
        NodeData *temp;
        temp = tempArray[root];
        tempArray[root] = NULL;
        
        insert(temp); //insert NodeData to BST
        
        //check left array
        arrayToBSTreeHelper(tempArray, curPtr, low, root - 1);
        
        //check right array
        arrayToBSTreeHelper(tempArray, curPtr, root + 1, high);
    }
}

//---------------------------------------------- operator<<---------------------------------------------------------------
//
// overloaded <<: outputs contents of BST inorder


ostream& operator<<(ostream& output, const BinTree& bst)
{
    bst.inOrderDisplay(bst.root); //call inOrderDisplay
    output << endl;
    return output;
}

// helper method that recursively traverse tree and print data.
void BinTree::inOrderDisplay(Node *curPtr) const
{
    if (curPtr != NULL) //Traverse inorder and print data
    {  
        inOrderDisplay(curPtr->leftChildPtr);
        cout <<*curPtr->data << " ";
        inOrderDisplay(curPtr->rightChildPtr);
    }
}
 