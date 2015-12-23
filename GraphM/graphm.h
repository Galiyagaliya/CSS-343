// Galiya Shakenova CSS 343 A
// Creation Date: 11/11/2015
// Date of Last Modification: 11/12/15

// implements Dijkstra's shortest path algorithm
// --------------------------------------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions:
// -- reads a data file consisting of many lines
// -- displays the cost and path from every node to every other node
// -- the input data file has correctly formatted, valid data
// --------------------------------------------------------------------------------------------------------------------



#ifndef GRAPHM_H
#define GRAPHM_H
#include <iostream>
#include <climits>
#include "nodedata.h"

using namespace std;

const int MAXNODES = 100;
const int INF = INT_MAX;

class GraphM {
    
public:
// ---------------------------------------------Constructor------------------------------------------------------------

    GraphM();
    
// ---------------------------------------------Destructor------------------------------------------------------------

    ~GraphM();
    
// ----------------------------------------Functions----------------------------------------------------------------


    void buildGraph(istream& infile); // automated graph builder, sets size, verticies, and edges.
    


    bool insertEdge(int,int,int); // sets the edge value of two adjacent verticies.
    

    bool removeEdge(int,int); // removes the edge
    


    void findShortestPath();     // algorithm uses modified Dijkstras algorithm to traverse through
    // the graph and find all posible shortest paths.
    

    void displayAll();    // displays all shortest paths, and the path traversal for every
    // possible path on the graph.
    
    void display(int, int); // display the shortest path, and path traversal for two
    // adjacent verticies. includes the shortest path represented by the data name.
    
private:

    struct TableType {
        bool visited; // whether node has been visited
        int dist;     // currently known shortest distance from source
        int path;     // previous node in path of min dist
    };
    

    
    void initialize(); // GraphM from 0 to MAXNODES is set to INF
    

    void displayPath(int,int);   // helper function for the display and display all methods, uses
    // cout to print the shortest path between two adjacent verticies
    

    void displayNodeData(int,int); // prints the the path's nodes actual loactions, instead of a number
    // prints in order, from the starting source to the end


    int  findMin(int) const;     // findShortestPath helper, finds the next adjacent verticie with
    // the shortest distance, for computation of Dijkstras algorithm.
    
    bool pathfound;
    NodeData data[MAXNODES];	// data for graph nodes information
    int C[MAXNODES][MAXNODES];	// Cost array, the adjacency matrix
    int size;		// number of nodes in the graph
    TableType T[MAXNODES][MAXNODES];// stores visited, distance, path
};

#endif // GRAPHM_H
