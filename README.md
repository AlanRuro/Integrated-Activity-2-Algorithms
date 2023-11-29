# INTEGRATED ACTIVITY 2

## Minimum Spanning Tree

To solve the first problem, we decided to implement Kruskal's algorithm, which involves determining the way of wiring the neighborhoods with fiber by identifying the list of arcs in the form (A, B). This algorithm efficiently finds the minimum spanning tree of the network, ensuring an optimal and cost-effective solution for connecting the neighborhoods with fiber.
   The output we had obtained with the input provided in the Integrated Activity 2 for wiring the neighborhoods with fiber, utilizing Kruskal's algorithm, is represented by the following list of arcs:

```
(C,D)
(A,B)
(B,C)
Kruskal: 41
```

For compilation: 
```
$ g++ mainMst.cpp mst.cpp ../Graph.cpp -o mainMst
```

## Traveling Salesman Problem

To determine the route for mail delivery personnel within the same neighborhoods, considering a start and end point within the network, we employed repetitive nearest neighbor. The resulting optimal route is outlined by the sequence of neighborhoods to be traversed:
```
0->1->2->3->0
RNN: 73
```

For compilation: 
```
$ g++ mainTsp.cpp tsp.cpp ../Graph.cpp -o mainTsp
```

## Maximum Flow Network 

To ascertain the maximum information flow value from the initial node to the final node within the network, we implemented the Edmonds-Karp algorithm. The output reveals the optimal flow along the network edges, ensuring efficient transmission of information.
Output:
```
Maximum flow from source 0 to sink 3 is 78
```
For compilation: 
```
$ g++ mainMF.cpp maxFlow.cpp ../Graph.cpp -o mainMF
```

## Voronoi Diagram

To solve the last question, we decided to use Voronoi diagrams to address the given problem. Voronoi diagrams are a powerful geometric tool that partitions a plane into regions based on proximity to a specified set of points.
Output:

For compilation: 
```
$ cmake -DCMAKE_BUILD_TYPE=Release .
```
