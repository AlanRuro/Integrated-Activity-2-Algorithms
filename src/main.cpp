#include <iostream>
#include <limits.h>
#include "MST.h"


using namespace std;

int** createWeightMatrix(int);
template <class T> T* createEmptyArray(int);
void printArray(int*, int);

pair<int*, int> nearestNeighbour(int**, int, int);
int findMin(int*, bool*, int);
pair<int*, int> repeatitiveNearestNeighbour(int**, int);

int main() {
    
    int numNeighborhoods;
    cout << "Number of neighborhoods";
    cin >> numNeighborhoods;

    cout << endl;

    int** distances = createWeightMatrix(numNeighborhoods);
    int numEdges = (numNeighborhoods * (numNeighborhoods - 1)) / 2;
    cout << "Kruskal: " << Kruskal(distances, numNeighborhoods, numEdges) << endl;

    pair<int*, int> shortestPath = repeatitiveNearestNeighbour(distances, numNeighborhoods);
    // for (int i = 0; i < numNeighborhoods+1; i++) {
    //     cout << shortestPath.first[i] << "->";
    // }
    printArray(shortestPath.first, numNeighborhoods+1);
    cout << endl;
    cout << "RNN: " << shortestPath.second << endl;

    int** dataFlowCapacities = createWeightMatrix(numNeighborhoods);

    return 0;
}



int** createWeightMatrix(int n) {
    int** weightMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        weightMatrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> weightMatrix[i][j];
        }
    }
    return weightMatrix;
}

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

pair<int*, int> nearestNeighbour(int** distances, int numNodes, int startNode) {
    int currentNode = startNode;
    bool* visited = createEmptyArray<bool>(numNodes);
    visited[currentNode] = 1;
    int countVisited = 1;
    float shortestDistance = 0;

    pair<int*, int> path;
    path.first = new int[numNodes+1];
    path.first[0] = startNode;

    int i = 1;

    while(countVisited < numNodes) {
        int nearestNode = findMin(distances[currentNode], visited, numNodes);
        shortestDistance += distances[currentNode][nearestNode];
        currentNode = nearestNode;
        visited[currentNode] = 1;
        path.first[i] = currentNode;
        countVisited++;
        i++;
    }
    path.first[numNodes] = startNode;
    path.second = shortestDistance + distances[currentNode][startNode];
    return path;
}

pair<int*, int> repeatitiveNearestNeighbour(int** distances, int n) {
    int minimumDistance = INT_MAX;
    pair<int*, int> minimumPath;
    for(int i = 0; i < n; i++) {
        pair<int*, int> path = nearestNeighbour(distances, n, i);
        if(path.second < minimumDistance){
            minimumPath = path;
            minimumDistance = path.second;
        } 
    }
    return minimumPath;
}

void printArray(int* array, int n) {
    for(int i = 0; i < n-1; i++) {
        cout << array[i] << "->";
    }
    cout << array[n-1];
}