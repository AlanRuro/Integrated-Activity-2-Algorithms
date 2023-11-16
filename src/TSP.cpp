#include "tsp.h"

template <class T>
T* createEmptyArray(int n) {
    T *array = new T[n];
    for(int i = 0; i < n; i++) {
        array[i] = 0;
    }
    return array;
}

int findMin(int* array, bool* visited, int n) {
    int min = INT_MAX;
    int nearest = 0;
    for(int i = 0; i < n; i++) {
        if (visited[i] == true || array[i] == 0) continue;
        if (array[i] < min) {
            min = array[i];
            nearest = i;
        } 
    }
    return nearest;
}


std::pair<int*, int> nearestNeighbour(Graph graph, int startNode) {
    int currentNode = startNode;
    bool* visited = createEmptyArray<bool>(graph.getNumVertices());
    visited[currentNode] = 1;
    int countVisited = 1;
    float shortestDistance = 0;

    std::pair<int*, int> path;
    path.first = new int[graph.getNumVertices()+1];
    path.first[0] = startNode;

    int** distances = graph.getWeightMatrix();

    int i = 1;

    while(countVisited < graph.getNumVertices()) {
        int nearestNode = findMin(distances[currentNode], visited, graph.getNumVertices());
        shortestDistance += distances[currentNode][nearestNode];
        currentNode = nearestNode;
        visited[currentNode] = 1;
        path.first[i] = currentNode;
        countVisited++;
        i++;
    }
    path.first[graph.getNumVertices()] = startNode;
    path.second = shortestDistance + distances[currentNode][startNode];
    return path;
}

std::pair<int*, int> repeatitiveNearestNeighbour(Graph graph) {
    int minimumDistance = INT_MAX;
    std::pair<int*, int> minimumPath;
    for(int i = 0; i < graph.getNumVertices(); i++) {
        std::pair<int*, int> path = nearestNeighbour(graph, i);
        if(path.second < minimumDistance){
            minimumPath = path;
            minimumDistance = path.second;
        } 
    }
    return minimumPath;
}
