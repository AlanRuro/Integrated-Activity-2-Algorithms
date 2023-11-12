#ifndef TSP_H
#define TSP_H

#include <iostream>
#include <limits.h>

std::pair<int*, int> nearestNeighbour(int**, int, int);
int findMin(int*, bool*, int);
std::pair<int*, int> repeatitiveNearestNeighbour(int**, int);
template <class T> T* createEmptyArray(int);

#endif