#include <iostream>
#include <limits.h>
#include "mst.h"
#include "tsp.h"

using namespace std;

void printArray(int*, int);
int** createWeightMatrix(int);

int main() {
    
    int numNeighborhoods;
    cout << "Number of neighborhoods";
    cin >> numNeighborhoods;

    cout << endl;

    int** distances = createWeightMatrix(numNeighborhoods);
    int numEdges = (numNeighborhoods * (numNeighborhoods - 1)) / 2;
    cout << "Kruskal: " << Kruskal(distances, numNeighborhoods, numEdges) << endl;

    pair<int*, int> shortestPath = repeatitiveNearestNeighbour(distances, numNeighborhoods);
    printArray(shortestPath.first, numNeighborhoods+1);
    cout << endl;
    cout << "RNN: " << shortestPath.second << endl;

    int** dataFlowCapacities = createWeightMatrix(numNeighborhoods);

    return 0;
}

void printArray(int* array, int n) {
    for(int i = 0; i < n-1; i++) {
        cout << array[i] << "->";
    }
    cout << array[n-1];
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