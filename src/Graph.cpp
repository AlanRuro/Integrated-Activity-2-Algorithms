#include "Graph.h"
#include <iostream>

Graph::Graph(int numVertices) {
    this->numVertices = numVertices;
    this->numEdges = (numVertices * (numVertices - 1)) / 2;
    fillGraph();
}

void Graph::fillGraph() {
    fillWeightMatrix();
    fillEdges();
}

void Graph::fillWeightMatrix() {
    this->weightMatrix = new int*[this->numVertices];
    for (int i = 0; i < this->numVertices; i++) {
        weightMatrix[i] = new int[this->numVertices];
        for (int j = 0; j < this->numVertices; j++) {
            std::cin >> this->weightMatrix[i][j];
        }
    }
}

void Graph::fillEdges() {
    this->edges = new std::pair<std::pair<int,int>, int>[this->numEdges];
    int k = 0;
    for (int i = 0; i < this->numVertices - 1; i++) {
        for (int j = i + 1; j < this->numVertices; j++) {
            this->edges[k] = {{i, j}, this->weightMatrix[i][j]};
            k++;
        }
    }
}

int Graph::getNumVertices() {
    return this->numVertices;
}

int Graph::getNumEdges() {
    return this->numEdges;
}

int** Graph::getWeightMatrix(){
    return this->weightMatrix;
}

std::pair<std::pair<int, int>, int>* Graph::getEdges(){
    return this->edges;
}