
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>
#include "dijkstra.h"
#define V 9


int main()
{
   //ilk firmanın değerleri bu matrise alınmıştır.Şehirler pdf teki gibi sırayla alınıştır.
    int graph[V][V] = {{0, 10, 0, 0, 0, 0, 0, 40, 0},
                       {10, 0, 10, 0, 0, 0, 0, 0, 9},
                       {0, 10, 0, 20, 100, 4, 0, 0, 100},
                       {0, 0, 20, 0, 30, 0, 0, 0, 0},
                       {0, 0, 100, 30, 0, 50, 0, 0, 30},
                       {0, 0, 0, 0, 50, 0, 0, 0, 50},
                       {0, 0, 0, 0, 0, 0, 0, 30, 70},
                       {40, 0, 0, 0, 0, 0, 30, 0, 20},
                       {0, 30,100, 0, 30, 50, 70, 20, 0}
                      };
 
    dijkstra(graph, 0);
printf("\nŞimdi ikinci firma\n");
  

 //ilk firmanın değerleri bu matrise alınmıştır.Şehirler pdf teki gibi sırayla alınıştır.
int graph1[V][V] = {{0, 20, 0, 0, 0, 0, 0, 20, 0},
                       {20, 0, 40, 0, 0, 0, 0, 30, 0},
                       {0, 40, 0, 30, 0, 100, 0, 0, 15},
                       {0, 0, 30, 0, 10, 0, 0, 0, 0},
                       {0, 0, 100, 10, 0, 30, 0, 0, 20},
                       {0, 0, 0, 0, 30, 0, 0, 0, 50},
                       {0, 0, 0, 0, 0, 0, 0, 60, 60},
                       {20, 0, 0, 0, 0, 0, 0, 60, 20},
                       {0, 30, 15, 0, 20, 50, 60, 20, 0}
                      };
 
    dijkstra(graph1, 0);
	



    return 0;
}
