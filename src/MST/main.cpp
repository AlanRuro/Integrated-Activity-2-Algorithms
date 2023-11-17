#include <iostream>
#include <limits.h>
#include "../Graph.h"
#include "mst.h"

using namespace std;

void printArray(int*, int);

int main() {
    
    int numNeighborhoods;
    // cout << "Number of neighborhoods";
    cin >> numNeighborhoods;

    // cout << endl;

    Graph city = Graph(numNeighborhoods);
    cout << "1. Way of wiring the neighborhoods with fiber: " << endl;

    cout << "Kruskal: " << Kruskal(city) << endl;

    return 0;
}

void printArray(int* array, int n) {
    for(int i = 0; i < n-1; i++) {
        cout << array[i] << "->";
    }
    cout << array[n-1];
}