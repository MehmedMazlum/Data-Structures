// C / C++ program for Dijkstra's shortest path algorithm for adjacency
// list representation of graph
 
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


 
// A structure to represent a node in adjacency list
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode* next;
};
 
// A structure to represent an adjacency liat
struct AdjList
{
    struct AdjListNode *head;  // pointer to head node of list
};
 
// A structure to represent a graph. A graph is an array of adjacency lists.
// Size of array will be V (number of vertices in graph)
struct Graph
{
    int V;
    struct AdjList* array;
};
 
// A utility function to create a new adjacency list node
struct AdjListNode* newAdjListNode(int dest, int weight)
{
    struct AdjListNode* newNode =(struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}
 
// A utility function that creates a graph of V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
 
    // Create an array of adjacency lists.  Size of array will be V
    graph->array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
 
     // Initialize each adjacency list as empty by making head as NULL
    for (int i = 0; i < V; ++i)
        graph->array[i].head = NULL;
 
    return graph;
}
 
// Adds an edge to an undirected graph
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    // Add an edge from src to dest.  A new node is added to the adjacency
    // list of src.  The node is added at the begining
    struct AdjListNode* newNode = newAdjListNode(dest, weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
 
    // Since graph is undirected, add an edge from dest to src also
    newNode = newAdjListNode(src, weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
 
void Sensor(){

   int i=0, j=0, k=0, s=0;
int  k1,k2,k3=0;
 //char * pch;
int result[71][4];   

int validation=0;  
for(i=0; i<=71; i++){         
    for(j=0;j<=4;j++){
        result[i][j] = NULL;
    }
}
   FILE *file = fopen ( "/home/mazlum/MMazlum_daskin_odevler_C/odev9/sensor.txt", "r" );
   if ( file != NULL )
   {
      char line [ 20];
	
  //int validation=0;   
 /* or other suitable maximum line size */
      while ( fgets ( line, sizeof line, file ) != NULL ) /* read a line */
      {
	
   
        //fputs ( line, stdout ); /* write the line */
 int val=0;
char s1[256];
strcpy(s1,line);
char* token = strtok(s1, ",");
while (token) {
	 val = atoi(token);
    //printf("token: %d\n", val);
    token = strtok(NULL, ",");
if(validation==1)
k1=val;
printf("token: %d\n",k1);
if(validation==2)
k2=val;
printf("token: %d\n",k2);
if(validation==3)
k3=val;
printf("token: %d\n",k3);



int V = 71;
struct Graph* graph = createGraph(V);
addEdge(graph, k1, k2, k3);

validation++;
}

validation==0;
k++;

 /* char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",line);
  pch = strtok (line,",");
  while (pch != NULL)
  {
    printf ("%s\n",pch);
    pch = strtok (NULL, ",");
  }
  
*/


}
      fclose ( file );
   }
  
}
// Driver program to test above functions
int main()
{
   
 	Sensor();
 
    return 0;
}
