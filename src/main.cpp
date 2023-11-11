#include <iostream>

using namespace std;

void make_set(int); // O(1)
int find_set(int); // O(lg n)
void union_sets(int, int); // O(n)
int** createWeightMatrix(int);
pair<pair<int,int>, int>* getEdges(int, int**);
int Kruskal(int**, int, int);
void mergeSort(pair<pair<int,int>, int>*, int, int); // O(n lg n)
void merge(pair<pair<int,int>, int>*, int, int, int);

const int N = 1e5 + 5;
int parent[N];
int sz[N];

int main() {
    
    int numNeighborhoods;
    cout << "Number of neighborhoods";
    cin >> numNeighborhoods;

    int** distances = createWeightMatrix(numNeighborhoods);
    int numEdges = (numNeighborhoods * (numNeighborhoods - 1)) / 2;
    cout << Kruskal(distances, numNeighborhoods, numEdges) << endl;
    int** dataFlowCapacities = createWeightMatrix(numNeighborhoods);

    return 0;
}

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
            swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int** createWeightMatrix(int n) {
    int** weightMatrix = new int*[n];
    for (int i = 0; i < n; i++) {
        weightMatrix[i] = new int[n];
        for (int j = 0; j < n; j++) {
            cin >> weightMatrix[i][j];
        }
    }
    return weightMatrix;
}

pair<pair<int,int>, int>* getEdges(int numEdges, int** weightMatrix) {
    pair<pair<int,int>, int>* edges = new pair<pair<int,int>, int>[numEdges];
    int k = 0;
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = i + 1; j < numEdges; j++) {
            edges[k] = {{i, j}, weightMatrix[i][j]};
            k++;
        }
    }
    return edges;
}

void mergeSort(pair<pair<int,int>, int>* array, int p, int r) {
    if (p >= r) return;
    int q = (p  + r) / 2;
    mergeSort(array, p, q);
    mergeSort(array, q+1, r);
    merge(array, p, q, r);
}

void merge(pair<pair<int,int>, int>* array, int p, int q, int r) {
    int nL = q - p + 1;
    int nR = r - q;
    pair<pair<int, int>, int> *L = new pair<pair<int, int>, int>[nL];
    pair<pair<int, int>, int> *R = new pair<pair<int, int>, int>[nR];
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

    pair<pair<int, int>, int> *edges = getEdges(numVertices, weightMatrix);

    mergeSort(edges, 0, numEdges-1);

    for (int i = 0; i < numEdges; i++) {
        int u = edges[i].first.first;
        int v = edges[i].first.second;
        int w = edges[i].second;

        if (find_set(u) != find_set(v)) {
            cost += w;
            union_sets(u, v);
        }
    }

    return cost;
}