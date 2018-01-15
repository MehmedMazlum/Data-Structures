#include<stdio.h>
#include<stdlib.h>
//#include "circuler_linked_list.h"
 

struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};
 

 

 /*
void addEnd_(struct Node **last, int data)
{
    if (last == NULL)
        return addToEmpty(last, data);
     
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
 
    temp -> data = data;
    //temp -> next = **last -> next;
    temp -> next = *last;
    *last -> next = temp;
    *last = temp; 
 
    
}*/

void insertEnd_C_list(struct Node **start, int data)
{
    
    struct Node *ptr1 =(struct Node *)malloc(sizeof(struct Node));
    ptr1->data = data;
    
                                  
    
    if (*start != NULL)
    {
        
        struct Node *temp = *start;
         while (temp->next != *start)
            temp = temp->next;
        
        //temp->next=ptr1;
        ptr1->next=temp->next;
        temp->next=ptr1;
    }
    
}
void insertAfter_C_list(struct Node** start, int value1)
{
    struct Node* new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = value1; 
 
    
    struct Node *temp = *start;
    new_node->next=temp->next;
        temp->next=new_node;
   

}
void push_C_list(struct Node **head_ref, int data)
{
    
    struct Node *ptr1 =(struct Node *)malloc(sizeof(struct Node));
    ptr1->data = data;
    ptr1->next = *head_ref;
                                  
    
    if (*head_ref != NULL)
    {
       
        struct Node *temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; 
 
    *head_ref = ptr1;
}
 

void printList_C_list(struct Node *head)
{
    struct Node *temp = head;
    if (head != NULL)
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while (temp != head);
    }
 
    printf("\n");
}

 

void deleteNode_C_list(struct Node **head, int key)
{
    if (head == NULL)
        return;
 
    
    struct Node *curr = *head, *prev;
    while (curr->data != key)
    {
        if (curr->next == *head)
        {
            printf("\nGiven node is not found"
                   " in the list!!!");
            break;
        }
 
        prev = curr;
        curr = curr -> next;
    }
 
    if (curr->next == *head)
    {
        head = NULL;
        free(curr);
        return;
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




