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
        void initialize();
        void fillFromInput();
        void fillEdges();
        void fillWeightMatrix();
        void resetWeightMatrix();
        int getNumVertices();
        int getNumEdges();
        int** getWeightMatrix();
        std::pair<std::pair<int, int>, int>* getEdges();
};

#endif