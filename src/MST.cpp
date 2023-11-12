#include "MST.h"

const int N = 1e5 + 5;
int parent[N];
int sz[N];

void make_set(int v) {
    parent[v] = v;
    sz[v] = 1;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (sz[a] < sz[b])
            std::swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

std::pair<std::pair<int,int>, int>* getEdges(int numVertices, int numEdges, int** weightMatrix) {
    std::pair<std::pair<int,int>, int>* edges = new std::pair<std::pair<int,int>, int>[numEdges];
    int k = 0;
    for (int i = 0; i < numVertices - 1; i++) {
        for (int j = i + 1; j < numVertices; j++) {
            edges[k] = {{i, j}, weightMatrix[i][j]};
            k++;
        }
    }
    return edges;
}

void mergeSort(std::pair<std::pair<int,int>, int>* array, int p, int r) {
    if (p >= r) return;
    int q = (p  + r) / 2;
    mergeSort(array, p, q);
    mergeSort(array, q+1, r);
    merge(array, p, q, r);
}

void merge(std::pair<std::pair<int,int>, int>* array, int p, int q, int r) {
    int nL = q - p + 1;
    int nR = r - q;
    std::pair<std::pair<int, int>, int> *L = new std::pair<std::pair<int, int>, int>[nL];
    std::pair<std::pair<int, int>, int> *R = new std::pair<std::pair<int, int>, int>[nR];
    for (int i = 0; i < nL; i++) {
        L[i] = array[p + i];
    }
    for (int j = 0; j < nR; j++) {
        R[j] = array[q + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = p;

    while (i < nL && j < nR) {
        if (L[i].second < R[j].second) {
            array[k] = L[i];
            i++;
        } else {
            array[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < nL) {
        array[k] = L[i];
        i++;
        k++;
    }
    while (j < nR) {
        array[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}

int Kruskal(int** weightMatrix, int numVertices, int numEdges) {
    for (int i = 0; i < numVertices; i++) {
        make_set(i);
    }

    int cost = 0;

    std::pair<std::pair<int, int>, int> *edges = getEdges(numVertices, numEdges, weightMatrix);

    mergeSort(edges, 0, numEdges-1);

    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        if (find_set(u) != find_set(v)) {
            cost += w;
            union_sets(u, v);
            std::cout << u << "->" << v << std::endl;
        }
    }

    return cost;
}
