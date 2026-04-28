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
        int getWeight();
        void setWeight(int);
        
    



        
};


#endif