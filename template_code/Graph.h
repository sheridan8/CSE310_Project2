#ifndef GRAPH_H
#define GRAPH_H

class Graph{
    private:
        int totalVert;
        int startVert;
        int endVert;
        int weight;
    public:
        Graph();
        Graph(int);
        int getWeight();
        void setWeight(int);


        
};


#endif