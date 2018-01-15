
#include <stdio.h>
#include <stdlib.h>
//#include "Doubled_linked_list.h"

 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};
 
 

void push_double_linkedlist(struct Node** head_ref, int new_data)
{
    
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    
    new_node->data  = new_data;
 
  
    new_node->next = (*head_ref);
    new_node->prev = NULL;
 
    if((*head_ref) !=  NULL)
      (*head_ref)->prev = new_node ;
 
    (*head_ref)    = new_node;


   
}

	void deleteNode__double_linkedlist(struct Node **head_ref, int value)
{
   
   if (*head_ref == NULL)
      return;
 
  
   struct Node* temp = *head_ref;

   if(temp->data==value){

   	 temp = temp->next;
   	 //exit();
   }
 

    while(temp->next->data!=value && temp->next!=NULL){
         temp = temp->next;}
   
 
   
    struct Node *next = temp->next->next;
 
    free(temp->next);  
 
    temp->next = next; 
}
 

void insertAfter_double_linkedlist(struct Node* prev_node, int new_data)
{
    
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }
 
   
    struct Node* new_node =(struct Node*) malloc(sizeof(struct Node));
 
  
    new_node->data  = new_data;
 
    
    new_node->next = prev_node->next;
 
    
    prev_node->next = new_node;
 
 
    new_node->prev = prev_node;
 
  
    if (new_node->next != NULL)
      new_node->next->prev = new_node;
}
 

void append_double_linkedlist(struct Node** head_ref, int new_data)
{
    
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    struct Node *last = *head_ref;  
 
    
    new_node->data  = new_data;
 
    
    new_node->next = NULL;
 
   
    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }
 
  
    while (last->next != NULL)
        last = last->next;
 
    last->next = new_node;
 
    
    new_node->prev = last;
 
    return;
}
 

void printList_double_linkedlist(struct Node *node)
{
    struct Node *last;
    
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

}

