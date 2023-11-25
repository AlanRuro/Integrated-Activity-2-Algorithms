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

void deleteMatrix(int** matrix, int n) {
    for (int i = 0; i < n; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

int EdmondsKarp(Graph graph, int s, int t) {
    int numVertices = graph.getNumVertices();
    int** flows = emptyMatrix<int>(graph.getNumVertices(), graph.getNumVertices()); 

    Graph residualGraph(numVertices);
    updateResidualGraph(graph, residualGraph, flows);
    std::vector<int> path = BFS(residualGraph, s, t);
    while (!path.empty()) {
        int residualCapacity = findMinResidualCapacity(path, residualGraph);
        for (size_t i = 0; i < path.size() - 1; i++) {
            int u = path[i];
            int v = path[i + 1];
            if (graph.getWeightMatrix()[u][v] != 0) {
                flows[u][v] += residualCapacity;
            } else {
                flows[v][u] -= residualCapacity;
            }
        }
        updateResidualGraph(graph, residualGraph, flows);
        path = BFS(residualGraph, s, t);
    }

    int maxFlow = 0;
    for (int i = 0; i < numVertices; ++i) {
        maxFlow += flows[s][i];
    }

    deleteMatrix(flows, numVertices);

    return maxFlow;
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
    int numVertices = capacities.getNumVertices();
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            int totalResidualCapacity = capacities.getWeightMatrix()[i][j] - flows[i][j] + flows[j][i];
            residualGraph.getWeightMatrix()[i][j] = totalResidualCapacity;
        }
    }
    residualGraph.fillEdges();
}

std::vector<int> BFS(Graph graph, int s, int t) {
    int numVertices = graph.getNumVertices();
    std::vector<int> parent(numVertices, -1);
    std::queue<int> q;
    std::vector<bool> visited(numVertices, false);

    q.push(s);
    visited[s] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (current == t) {
            std::vector<int> path;
            int currentPath = t;
            while (currentPath != -1) {
                path.push_back(currentPath);
                currentPath = parent[currentPath];
            }
            std::reverse(path.begin(), path.end());
            return path;
        }

        const auto& weightMatrix = graph.getWeightMatrix();
        for (int i = 0; i < numVertices; ++i) {
            if (!visited[i] && weightMatrix[current][i] > 0) {
                q.push(i);
                parent[i] = current;
                visited[i] = true;
            }
        }
    }

    return std::vector<int>();
}


