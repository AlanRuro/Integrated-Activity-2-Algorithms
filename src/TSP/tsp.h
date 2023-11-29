#ifndef TSP_H
#define TSP_H

#include <iostream>
#include <limits.h>
#include "../Graph.h"


std::pair<int*, int> nearestNeighbour(Graph, int); // O(n^2)
int findMin(int*, bool*, int); // O(n)
std::pair<int*, int> repeatitiveNearestNeighbour(Graph); // O(n^3)
template <class T> T* createEmptyArray(int); // O(n)

#endif