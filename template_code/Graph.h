#ifndef GRAPH_H
#define GRAPH_H

class Graph{
    private:
        int totalVert;
        int startVert;
        int endVert;
        int weight;
        // Initialize the adjacency matrix as a 2D array
        int** adjMatrix; 
        int* tableOfProgress;
    public:
        Graph();
        Graph(int);
        ~Graph(); // Aisha: added desconstructor 

        // Sheridan: getter and setter for 2D array cells
        void setAdjMatrix(int startVert, int endVert, int weight);
        int getAdjMatrix(){return adjMatrix[startVert][endVert];};
        void minimumDistFromNode(int);
        void printOddInDegree();
        void printLineOfAdjMatrix();

        int getWeight();
        void setWeight(int);

        void printAdjMatrix(); // Aisha: added function to print the adjacency matrix
        
    



        
};


#endif