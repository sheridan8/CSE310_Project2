#include "Graph.h"
#include <iostream>
using namespace std;


Graph::Graph(){
    this->totalVert = -1;
    this->startVert = -1;
    this->endVert = -1;
    this->weight = -1;
}

Graph::Graph(int vertices){
        this->totalVert = vertices;  

    adjMatrix = new int*[vertices]; //Aisha: initialize an array of pointers 

    //Creating each row 
    for(int i = 0; i < vertices; i++){
        adjMatrix[i] = new int[vertices];
    }

    // Initialized the matrix with 0s
    for (int i = 0; i < vertices; i++){
        for (int j = 0; j < vertices; j++){
            adjMatrix[i][j] = 0;
        }
    }
}


Graph::~Graph(){
    for (int i = 0; i < this->totalVert; i++){
        delete[] adjMatrix[i]; //Aisha: delete each row
    }
    delete[] adjMatrix; //Aisha: delete the array of pointers
}

int Graph::getWeight(){
    return this->weight;
}

void Graph::setWeight(int newWeight){
    this->weight = newWeight;
}

void Graph::setAdjMatrix(int start, int end, int weight){
    int u = start - 1;
    int v = end - 1;


    adjMatrix[u][v] = weight;
    adjMatrix[v][u] = weight; //Aisha: since the graph is undirected, I set the value for both [u][v] and [v][u]
}

void Graph::minimumDistFromNode(int nodeI){
    tableOfProgress = new int[totalVert];//init table of progress with size totalVert 
    
    // Initialized the array with 0s
    for (int i = 0; i < totalVert; i++){
        tableOfProgress[i] = 0;
    }
    
    int distance = 0; // Keeps track of distance
    int preNode = 0; //Keeps track of the previous node

    //Finding the minimum distance for nodeI aka Node A or Node B etc in the loop in main Task 3.
    for(int i = 0; i < nodeI; i++){
        preNode = nodeI;
            //if the node given and the current node has a value in the adjMatrix they have an edge together so return that
            //or if the wanted node is the same as the node were testing then it cant have an edge with itself so the value is zero
        if(adjMatrix[nodeI-1][i] != 0 || nodeI-1 == i){
            tableOfProgress[i] = adjMatrix[nodeI-1][i];
        } else {
            while(preNode != i){
                int minimum = 2001;
                for(int j = 0; j < preNode; j++){
                    if (minimum > adjMatrix[preNode-1][j] && adjMatrix[preNode-1][j] != 0){
                        minimum = adjMatrix[preNode-1][j];
                        preNode = j;
                    }
                }
                distance =+ minimum;
            }
            tableOfProgress[i] = distance;
        }
    }
}

void Graph::printOddInDegree(){
    for (int i = 0; i < totalVert; i++){
        int inDeg = 0;
        
        for (int j = 0; j < totalVert; j++){
            if(adjMatrix[i][j] != 0){
                inDeg++;
            }
        }
<<<<<<< HEAD
        if(inDeg % 2 == 1){
            cout << i + 1 << " "; //Aisha: print the node number (i + 1) if it has an odd degree
=======
        if((inDeg % 2) != 0){
            cout << (i+1) << ", ";
>>>>>>> 3bf427f0592ac43f1b23b5fd7a1ebfc841fbfd0c
            
        }
    }
}

void Graph::printLineOfAdjMatrix(){
    for (int j = 0; j < totalVert; j++){
        cout << j+1 << ": " << tableOfProgress[j];
    }
    cout << endl;
    //S: this prints the first line or the 2 or 3 etc depending on the node. 
}

void Graph::printAdjMatrix(){ // Aisha: function to print the adjacency matrix
    
    for (int i = 0; i < totalVert; i++){
        for (int j = 0; j < totalVert; j++){
            cout << adjMatrix[i][j];
            if (j < totalVert - 1){
                    cout << " ";
            } 
        }
        cout << endl;
    }
}