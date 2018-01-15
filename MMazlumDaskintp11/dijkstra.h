
#ifndef Dijkstra_H_
#define  Dijkstra_H_
#define V 9

int minDistance(int dist[], bool sptSet[]);
void printPath(int parent[], int j);
int printSolution(int dist[], int n, int parent[]);
void dijkstra(int graph[V][V], int src);

#endif
