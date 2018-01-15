#ifndef Priority_queue_H_
#define Priority_queue_H_
#define MAXSIZE 10
#define MAXSIZE_1 5
#define MAXSIZE_2 5


typedef struct Queue Queue;
typedef struct person person;
typedef struct Queue_cust Queue_cust;
typedef struct Queue_nocust Queue_nocust;

void init(Queue *);
void enqueue(Queue *, person*);
void add_customer(Queue*, person*);
int  dequeue(Queue *);
int  length(Queue *);
int  empty(Queue *);

#endif
