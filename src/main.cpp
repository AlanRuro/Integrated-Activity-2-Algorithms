#include <iostream>

using namespace std;

int** createGraph(int);

int main() {
    
    int numNeighborhoods;
    cout << "Number of neighborhoods";
    cin >> numNeighborhoods;

    return 0;
}

int** createGraph(int n) {
    int** weightMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        weightMatrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> weightMatrix[i][j];
        }
    }
    return weightMatrix;
}