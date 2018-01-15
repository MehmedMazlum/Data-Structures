#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include  "Priority_queue.h"



struct person{

    int idendite;
     char name[20];
    int  moneyT;
   };

struct Queue {
  char  data[MAXSIZE];
  int first;
  int last;
  int size;

 };

//başlangıç ve bitiş değerleri ile kuyruk başatma işlemi
void init(Queue *q) {
  q->first = 0;
  q->last  = MAXSIZE-1;
  q->size  = 0;
}


int empty(Queue *q) {
  return q->size == 0;
}

///q.size 9 ise kuyruk dolmuş demektir.

int length(Queue *q) {
  return q->size;
}




void enqueue(Queue *q, person *item) {

  if(q->size>=MAXSIZE)
      printf("hatalı giriş kuyruk dolu!!!!!!!\n");
  if(q->size < MAXSIZE) {
    q->last = (q->last + 1) % MAXSIZE;
    //q->data[q->last] = item->moneyT;
    q->data[q->last] = item->idendite;
    q->size++;
    printf(" last :%d\n",q->last);
    printf("%d\n",q->data[q->last]);
  }

}



void add_customer(Queue *q, person *item) {
   if(q->size>=MAXSIZE)
      printf("hatalı giriş kuyruk dolu!!!!!!!\n");
  if(q->size < MAXSIZE) {
    q->first = (q->first - 1) % MAXSIZE;
    q->data[q->first] = item->idendite;
    q->size++;
    printf(" last :%d\n",q->first);
    printf("%d\n",q->data[q->first]);
  }
  //printf("%d\n",q->data[q->last]);
}



int dequeue(Queue *q) {
  if(!empty(q)) {
   printf("first:%d\n",q->first);
    int value = q->data[q->first];

    q->first = (q->first + 1) % MAXSIZE;
    q->size--;
    //printf("first:%d\n",q->first);

    return value;
  }
  return -1;
}


void shift_all(Queue *q) {
  if(empty(q)) 
    printf("hatalı giriş");
    
    for(int i=0;i<(q->size);i++)
      q->data[((q->last+1)-i)%MAXSIZE]=q->data[((q->last)-(i))%MAXSIZE];
      
      q->first=(q->first+1)%MAXSIZE;
      q->last=(q->last+1)%MAXSIZE;


    }


