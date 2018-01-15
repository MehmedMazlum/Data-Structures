#include<stdio.h>
#include<stdlib.h>
#include "header_avl.h"


//soruda istenilen diğer kısımlar fonksiyonlarda mevcuttur
int main()
{
  struct Node *root = NULL;
 
 
    root = insert(root, 9);
    root = insert(root, 5);
    root = insert(root, 10);
    root = insert(root, 0);
    root = insert(root, 6);
    root = insert(root, 11);
    root = insert(root, -1);
    root = insert(root, 1);
    root = insert(root, 2);
 
   
 
    printf("Preorder traversal of the constructed AVL "
           "tree is \n");
    preOrder(root);
 
    root = deleteNode(root, 10);
 
   
 
    printf("\nPreorder traversal after deletion of 10 \n");
    preOrder(root);
 
    return 0;
}
