#include "mst.h"

int FIRST_ASCII_VALUE = 65;

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

void mergeSort(std::pair<std::pair<int, int>, int>* array, int p, int r) {
    if (p >= r) return;
    int q = (p  + r) / 2;
    mergeSort(array, p, q);
    mergeSort(array, q+1, r);
    merge(array, p, q, r);
}

void merge(std::pair<std::pair<int, int>, int>* array, int p, int q, int r) {
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

int Kruskal(Graph graph) {
    for (int i = 0; i < graph.getNumVertices(); i++) {
        make_set(i);
    }

    int cost = 0;

    std::pair<std::pair<int, int>, int>* edges = graph.getEdges();


    mergeSort(edges, 0, graph.getNumEdges()-1);

    for (int i = 0; i < graph.getNumEdges(); i++) {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        if (find_set(u) != find_set(v)) {
            cost += w;
            union_sets(u, v);
            std::cout << "(" << static_cast<char>(u + FIRST_ASCII_VALUE) << "," << static_cast<char>(v + FIRST_ASCII_VALUE) << ")" << std::endl;
        }
    }

    return cost;
}
