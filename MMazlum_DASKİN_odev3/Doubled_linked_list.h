#ifndef Doubled_linked_list_H_
#define Double_linked_list_H_
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>



void push_double_linkedlist(struct Node** head_ref, int new_data);
void deleteNode_double_linkedlist(struct Node **head_ref, int position);
void deleteNode__doble_linkedlist(struct Node **head_ref, int value);
void insertAfter_double_linkedlist(struct Node* prev_node, int new_data);
void append_double_linkedlist(struct Node** head_ref, int new_data);
void printList_double_linkedlist(struct Node *node);
#endif
