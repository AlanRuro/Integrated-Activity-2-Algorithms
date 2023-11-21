#ifndef MAX_FLOW_H
#define MAX_FLOW_H

#include <iostream>
#include <limits.h>
#include "../Graph.h"


int EdmondsKarp(Graph, int, int);
void BFS(Graph, int, int, int*); // O(V(E*E))

#endif