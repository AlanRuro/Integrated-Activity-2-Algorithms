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

    int source = 0;
    int sink = 3;

    cout << "Maximum flow from source " << source << " to sink " << sink << " is " << EdmondsKarp(network, source, sink) << endl;

    return 0;
}

