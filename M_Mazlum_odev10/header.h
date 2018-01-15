#ifndef header_H_
#define  header_H_

void Sensor();
void addEdge(struct Graph* graph, int src, int dest, int weight);
struct Graph* createGraph(int V);
struct AdjListNode* newAdjListNode(int dest, int weight);
void printGraph(struct Graph* graph);
#endif
