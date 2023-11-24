#include <iostream>
#include <limits.h>
#include "../Graph.h"
#include "maxFlow.h"


using namespace std;

void printArray(int*, int);

int main() {
    
    int numNeighborhoods;
    cin >> numNeighborhoods;

    Graph network = Graph(numNeighborhoods);
    network.fillFromInput();

    cout << EdmondsKarp(network, 0, 3) << endl;

    return 0;
}

