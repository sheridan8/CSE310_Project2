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

void Graph::printInDegreeValue(){
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

void Graph::printLineOfAdjMatrix(int line){
    for (int j = 0; j < totalVert; j++){
        cout << j << ": " << adjMatrix[line][j];
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