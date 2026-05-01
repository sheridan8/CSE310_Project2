#include "Edge.h"
# include "Graph.h"
#include <iostream>

using namespace std;


int main(){

    // start of the initial pipeline that loads the test case file stream from std::cin

    int numOfVertices;
    int numOfEdges;

    if(!std::cin.eof()){
        std::cin >> numOfVertices;
        std::cin >> numOfEdges;
    }
    else{
        std::cout<<"Input not found!"<<std::endl;
        return 1;
    }

    // Aisha: Moved the creation of the Graph object here so that we can use the number of vertices read from the input file to initialize the adjacency matrix in the Graph constructor
    Graph* newGraph= new Graph(numOfVertices); // Aisha: created a new Graph object with the number of vertices read from the input file
    

    while(!std::cin.eof()){
        int index = 0; // Sheridan: added index to check if the while loop is on its first iteration
        int startVertice;
        int endVertice;
        int weight;
        std::cin >> startVertice;
        std::cin >> endVertice;
        std::cin >> weight;
        Edge* newEdge = new Edge(startVertice, endVertice);
        newEdge->setWeight(weight);

        // Here is where you load up the Graph object
        newGraph->setAdjMatrix(startVertice, endVertice, weight);
        
        index++;
    } 

    //For tasks 2 and three i need something to return the weight from each vertice
    // for(int i = 0; i < ){

    // }

    // And here is where you start working on the three tasks

    //Task One: Print out the adjacency matrix of graph G
    std::cout << "The adjacency matrix of G is: " << std::endl;

    newGraph->printAdjMatrix();

    cout << endl;

    //Task Two: Print out the odd degrees in G
    std::cout << "The nodes with odd degrees in G are:" << std::endl;
    //cout << "O = {";
    //newGraph->printInDegreeValue();
    //cout << "}" << endl;
    

    //Task Three: Print out the shortest path lengths from all nodes
    for(int i = 0; i < numOfVertices; i++){
        cout << "The shortest path lengths from Node " << i << " to all other nodes are:" << endl;
        newGraph->printLineOfAdjMatrix(i);
    }

}

