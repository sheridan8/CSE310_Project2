#include "Graph.h"


Graph::Graph(){
    this->totalVert = -1;
    this->startVert = -1;
    this->endVert = -1;
    this->weight = -1;
}

Graph::Graph(int vertices){
    this->startVert = vertices;
}

int Graph::getWeight(){
    return this->weight;
}

void Graph::setWeight(int newWeight){
    this->weight = newWeight;
}
