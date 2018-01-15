
#include<stdio.h>
#include<stdlib.h>
//#include  "Circuler_double_linked_list.h"
 


 struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

void insertEnd_circuler_double(struct Node **start, int value)
{
    
    if (*start == NULL)
    {
        struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
        return;
    }
 
   
    struct Node *last = (*start)->prev;
 
  
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;
 
    
    new_node->next = *start;
 
    
    (*start)->prev = new_node;
 
    
    new_node->prev = last;
 
    
    last->next = new_node;
}
 


void deleteNode_circuler_double(struct Node **head, int key)
{
    if (head == NULL)
        return;
 
    // Find the required node
    struct Node *curr = *head, *prev;
    while (curr->data != key)
    {
        if (curr->next == *head)
        {
            printf("\n");
            break;
        }
 
        prev = curr;
        curr = curr -> next;
    }
 
   
   
 
    
    if (curr == *head)
    {
        prev = *head;
        while (prev -> next != *head)
            prev = prev -> next;
        *head = curr->next;
        prev->next = *head;
        free(curr);
    }
 
    else if (curr -> next == *head)
    {
        prev->next = *head;
        free(curr);
    }
    else
    {
        prev->next = curr->next;
        free(curr);
    }
}


void insertBegin_circuler_double(struct Node **start, int value)
{
    struct Node  *temp = *start;
    struct Node *last = temp->prev;
     if (*start == NULL)
    {
        struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = value;
        new_node->next = new_node->prev = new_node;
        *start = new_node;
         
        
    }
    
 
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value;  
 
   
    new_node->next = (temp);
    new_node->prev = (temp)->prev->prev;
 
   
    temp->prev = new_node;

    last->next = temp->prev;
 
  
    *start = new_node;

}



void insertAfter_circuler_double(struct Node **start, int value1)
{
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value1;
 
    
    struct Node *temp = *start;
   
    struct Node *next = temp->next;
 
    
    temp->next = new_node;
    new_node->prev = temp;
    new_node->next = next;
    next->prev = new_node;
}
 
 
void display_circuler_double(struct Node *start)
{
    struct Node *temp = start;
 
   
    while (temp->next != start)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("%d ", temp->data);
  printf("\n");
 
    
}

