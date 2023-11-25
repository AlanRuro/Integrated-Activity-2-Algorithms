#ifndef MAX_FLOW_H
#define MAX_FLOW_H

#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include "../Graph.h"
#include <queue>


int EdmondsKarp(Graph, int, int);
std::vector<int> BFS(Graph, int, int); // O(V(E*E))
int findMinResidualCapacity(std::vector<int>, Graph);
void updateResidualGraph(Graph, Graph&, int**);
void deleteMatrix(int**, int);

template <class T> T* emptyArray(int);
template <class T> T** emptyMatrix(int, int);

#endif