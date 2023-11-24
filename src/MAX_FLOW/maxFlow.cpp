#include "maxFlow.h"

template <class T>
T* emptyArray(int n) {
    T *array = new T[n];
    for(int i = 0; i < n; i++) {
        array[i] = 0;
    }
    return array;
}

template <class T>
T** emptyMatrix(int n, int m) {
    T **matrix = new T*[n];
    for(int i = 0; i < n; i++) {
        matrix[i] = emptyArray<T>(m);
    }
    return matrix;
}

int EdmondsKarp(Graph graph, int s, int t){
    int** flows = emptyMatrix<int>(graph.getNumVertices(), graph.getNumVertices());
    Graph residualGraph = Graph(graph.getNumVertices());
    updateResidualGraph(graph, residualGraph, flows);
    std::vector<int> path = BFS(residualGraph, s, t);
    while (!path.empty()) {
        int residualCapacity = findMinResidualCapacity(path, residualGraph);
        for (int i = 0; i < path.size()-1; i++) {
            int u = path[i];
            int v = path[i+1];
            if (graph.getWeightMatrix()[u][v] != 0) {
                flows[u][v] = flows[u][v] + residualCapacity;
            } else {
                flows[v][u] = flows[v][u] - residualCapacity;
            }
        }
        updateResidualGraph(graph, residualGraph, flows);
        path = BFS(residualGraph, s, t);
    }

    return 0;

}

int findMinResidualCapacity(std::vector<int> path, Graph residualGraph) {
    int minCapacity = INT_MAX;
    for (int i = 0; i < path.size()-1; i++) {
        int u = path[i];
        int v = path[i+1];
        int** residuals = residualGraph.getWeightMatrix();
        int residualCapacity = std::min(residuals[u][v], residuals[v][u]);

        if (residualCapacity < minCapacity) {
            minCapacity = residualCapacity;
        }

    }
    return minCapacity;
}

void updateResidualGraph(Graph capacities, Graph& residualGraph, int** flows) {
    for (int i = 0; i < residualGraph.getNumVertices(); i++) {
        for (int j = 0; j < residualGraph.getNumVertices(); j++) {
            int totalResidualCapacity = capacities.getWeightMatrix()[i][j] - flows[i][j] + flows[j][i];
            residualGraph.getWeightMatrix()[i][j] = totalResidualCapacity;
        }
    }
    residualGraph.fillEdges();
}
