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
    public:
        Graph();
        Graph(int);
        ~Graph(); // Aisha: added desconstructor 

        // Sheridan: getter and setter for 2D array cells
        void setAdjMatrix(int startVert, int endVert, int weight){adjMatrix[startVert][endVert] = weight;};
        int getAdjMatrix(){return adjMatrix[startVert][endVert];};

        int getWeight();
        void setWeight(int);
        
    



        
};


#endif