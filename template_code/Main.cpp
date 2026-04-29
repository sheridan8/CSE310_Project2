#include "Edge.h"
# include "Graph.h"
#include <iostream>

using namespace std;
Graph* newGraph;

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
        return NULL;
    }

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

        //Sheridan: condition to find out if it is the first line of the input or not
        if(index == 0){
            newGraph = new Graph(startVertice);

        }else{
            newGraph->setAdjMatrix(startVertice, endVertice, weight);
        }

        index++;
    } 

    // And here is where you start working on the three tasks

    //Task One: Print out the adjacency matrix of graph G
    std::cout << "The adjacency matrix of G is: " << std::endl;

    cout << newGraph << endl;

    cout << endl;

    //Task Two: Print out the odd degrees in G
    std::cout << "The nodes with odd degrees in G are:" << std::endl;


    //Task Three: Print out the shortest path lengths from all nodes
    

    return 0;
}

