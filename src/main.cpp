#include <iostream>
#include <limits.h>
#include "Graph.h"
#include "MST/mst.h"
#include "TSP/tsp.h"

using namespace std;

void printArray(int*, int);

int main() {
    
    int numNeighborhoods;
    cin >> numNeighborhoods;

    Graph city = Graph(numNeighborhoods);
    cout << "1. Way of wiring the neighborhoods with fiber: " << endl;

    cout << "Kruskal: " << Kruskal(city) << endl;

    cout << "2. Route to be followed by the mail delivery personnel: " << endl;

    pair<int*, int> shortestPath = repeatitiveNearestNeighbour(city);
    printArray(shortestPath.first, numNeighborhoods+1);
    cout << endl;
    cout << "RNN: " << shortestPath.second << endl;

    Graph network = Graph(numNeighborhoods);

    return 0;
}

void printArray(int* array, int n) {
    for(int i = 0; i < n-1; i++) {
        cout << array[i] << "->";
    }
    cout << array[n-1];
}