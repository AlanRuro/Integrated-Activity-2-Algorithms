#ifndef MST_H
#define MST_H

#include <iostream>
#include "../Graph.h"

void make_set(int); // O(1)
int find_set(int); // O(lg n)
void union_sets(int, int); // O(n)
int Kruskal(Graph);
void mergeSort(std::pair<std::pair<int,int>, int>*, int, int); // O(n lg n)
void merge(std::pair<std::pair<int,int>, int>*, int, int, int);

#endif