#ifndef TSP_H
#define TSP_H

#include <iostream>
#include <limits.h>
#include "../Graph.h"


std::pair<int*, int> nearestNeighbour(Graph, int);
int findMin(int*, bool*, int);
std::pair<int*, int> repeatitiveNearestNeighbour(Graph);
template <class T> T* createEmptyArray(int);

#endif