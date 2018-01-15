#ifndef circuler_linkedlist_H_
#define ciirculer_linkedlist_H_
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


void insertEnd_C_list(struct Node **start, int data);
void insertAfter_C_list(struct Node** start, int value1);
void push_C_list(struct Node **head_ref, int data);
void printList_C_list(struct Node *head);

#endif 
