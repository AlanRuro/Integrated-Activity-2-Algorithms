#ifndef MAX_FLOW_H
#define MAX_FLOW_H

#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include "../Graph.h"
#include <queue>


int EdmondsKarp(Graph, int, int); // O(V*E^2)
std::vector<int> BFS(Graph, int, int); // O(V(E*E))
int findMinResidualCapacity(std::vector<int>, Graph); // O(|path|)
void updateResidualGraph(Graph, Graph&, int**); // O(V^2)
void deleteMatrix(int**, int); // O(n * m)

template <class T> T* emptyArray(int); // O(n)
template <class T> T** emptyMatrix(int, int); // O(n * m)

#endif