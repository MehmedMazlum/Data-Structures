
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include "liner_linked_list.h"
 

struct Node
{
  int data;
  struct Node *next;
};
 

void push(struct Node** head_ref, int new_data)
{
    
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    
    new_node->data  = new_data;
 
   
    new_node->next = (*head_ref);
 
    
    (*head_ref)    = new_node;
}

void insertAfter(struct Node* prev_node, int new_data)
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
}
 
////////////////////
///sondan ekleme fonksyionu
void append(struct Node** head_ref, int new_data)
{
    
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
 
    struct Node *last = *head_ref;  
 
    
    new_node->data  = new_data;
 
    
    new_node->next = NULL;
 
   
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
 
    
    while (last->next != NULL)
        last = last->next;
 
    
    last->next = new_node;
    return;
}
void reverse(struct Node** head_ref)
{
    struct Node* prev   = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
    while (current != NULL)
    {
        next  = current->next;  
        current->next = prev;   
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
//////////////////////////////////////////77777777
///bu delete iişlemi kaçıncı position daki eleamnı silmek istediğinize göre çalışır
 
void deleteNode(struct Node **head_ref, int position)
{

   if (*head_ref == NULL)
      return;
 
   
   struct Node* temp = *head_ref;
 
    
    if (position == 0)
    {
        *head_ref = temp->next;   
        free(temp);             
        return;
    }
 
    
    for (int i=0; temp!=NULL && i<position-1; i++)
         temp = temp->next;
 
    
    if (temp == NULL || temp->next == NULL)
         return;
 
    
    struct Node *next = temp->next->next;
 
    free(temp->next);  
 
    temp->next = next;  
}

void ListDelete(struct  Node **head_ref, int value)
{
  struct Node *currP, *prevP;

  prevP = NULL;

  
  for (currP = *head_ref;
  currP != NULL;
  prevP = currP, currP = currP->next) {

    if (currP->data== value) {  
      if (prevP == NULL) {
      
        *head_ref = currP->next;
      } else {
        
        prevP->next = currP->next;
      }

     
      free(currP);

      
      return;
    }
  }
}
 bool search(struct Node* head, int x)
{
  
    if (head == NULL)
        return false;
     
    
    if (head->data == x){
       printf("X değeri: %d\n",x);
        return true;  }
 
   
    return search(head->next, x);
}
 

void printList(struct Node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
  printf("\n" );
}
int getCount(struct Node* head)
{
    
    if (head == NULL)
        return 0;
 
    
    return 1 + getCount(head->next);
}
void union_list(struct Node** head1_ref,struct Node** head2_ref){

struct Node *last = *head1_ref; 

  while (last->next != NULL)
        last = last->next;

last->next=*head2_ref;



}

