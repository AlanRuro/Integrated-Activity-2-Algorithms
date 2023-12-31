#include <iostream>
#include <limits.h>
#include "../Graph.h"
#include "mst.h"
using namespace std;



int main() {
    
    int numNeighborhoods;
    cin >> numNeighborhoods;

    Graph city = Graph(numNeighborhoods);
    city.fillFromInput();
    cout << "Way of wiring the neighborhoods with fiber: " << endl;

    cout << "Kruskal: " << Kruskal(city) << endl;


    return 0;
}

