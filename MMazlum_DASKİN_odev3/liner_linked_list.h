#ifndef liner_linked_list_H_
#define liner_linked_list_H_
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>


void push(struct Node** head_ref, int new_data);
void insertAfter(struct Node* prev_node, int new_data);
void append(struct Node** head_ref, int new_data);
void deleteNode(struct Node **head_ref, int position);
 void reverse(struct Node** head_ref);
 bool search(struct Node* head, int x);
int getCount(struct Node* head);
void union_list(struct Node** head1_ref,struct Node** head2_ref);
#endif
