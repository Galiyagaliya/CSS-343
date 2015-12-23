
// Galiya Shakenova CSS 343 A
// Creation Date: 11/11/2015
// Date of Last Modification: 11/12/15

// displays the graph information and implements depth-first (search always starts at node #1).
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// -- reads a data file consisting of many lines
// -- displays the cost and path from every node to every other node
// -- the input data file has correctly formatted, valid data
// -- edges in the input are always shown in reverse order in the output
// --------------------------------------------------------------------------------------------------------------------


//

#ifndef GRAPHL_H
#define	GRAPHL_H
#include <iostream>
#include <climits>
#include "nodedata.h"

using namespace std;

struct EdgeNode;//needed for complier

// --------------------------------------------------------------------------------------------------------------------
// an array is filled with graphNodes A->[GN][GN][GN][GN]
// each graphNode representing a location on a graph
struct GraphNode {
    EdgeNode* edgeHead = NULL;
    NodeData data;
    bool visited;
};

// --------------------------------------------------------------------------------------------------------------------
// each graphNode contains a list of edgeNodes representing which
// other graphNodes are adjacent to it by a value stored in the edgeNode

struct EdgeNode {
    int adjGraphNode;
    EdgeNode* nextEdge = NULL;
};

class GraphL {
public:
// ---------------------------------------------Constructor------------------------------------------------------------
 
    GraphL();
    
// ---------------------------------------------Deconstructor----------------------------------------------------------

    ~GraphL();
    
// ----------------------------------------Functions----------------------------------------------------------------
    // build graph reads a file, line by line, builds an array of graph nodes.
    // in each graph node there is a list of edgeNodes that contains data about
    // which nodes are adjacent to the source node
    void buildGraph(istream& infile);
    
    //---------------------------------------------------------------------------
    // depth-first search goes as deep as possible, into the graph, by connecting
    // the source node to it's next node, and then that next node's, next node
    // and so on. Continues until it hits a null edge
    void depthFirstSearch();
    
    //---------------------------------------------------------------------------
    // displays the graph by printing the node's data. Then printing all of the
    // edges surrounding that node
    void displayGraph()const;
    
private:
    
    //---------------------------------------------------------------------------
    // called in destructor, deletes the array of graphNodes & edgeNodes
    void makeEmpty();
    
    //---------------------------------------------------------------------------
    // recursive makeEmpty helper, deletes the edgeNode objects
    void remove(EdgeNode* p);
    
    //---------------------------------------------------------------------------
    // recursive helper for depth first search
    void searchHelper(EdgeNode*,int);
    
    //---------------------------------------------------------------------------
    // recursive helper for display Graph
    void displayEdge(const EdgeNode*, const int)const;
    
    GraphNode* adjList = NULL; // GraphNode array
    int size;           	// array size
};

#endif	// GRAPHL_H
