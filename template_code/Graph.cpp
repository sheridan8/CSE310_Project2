#include "Graph.h"


Graph::Graph(){
    this->totalVert = -1;
    this->startVert = -1;
    this->endVert = -1;
    this->weight = -1;
}

Graph::Graph(int vertices){
   this->startVert = vertices;

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
    for (int i = 0; i < this->startVert; i++){
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
