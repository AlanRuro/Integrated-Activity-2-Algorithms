#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>

class Graph {

    private:
        int numVertices;
        int numEdges;
        int** weightMatrix;
        std::pair<std::pair<int, int>, int>* edges;

    public:
        Graph(int);
        void initialize(); // O(n^2)
        void fillFromInput(); // O(n^2)
        void fillEdges(); // O(n^2)
        void fillWeightMatrix(); // O(n^2)
        void resetWeightMatrix(); // O(n^2)
        int getNumVertices();// O(1)
        int getNumEdges(); // O(1)
        int** getWeightMatrix(); // O(1)
        std::pair<std::pair<int, int>, int>* getEdges(); // O(1)
};

#endif