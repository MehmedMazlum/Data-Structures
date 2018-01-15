
#include<stdio.h>
#include<stdlib.h>
#include <limits.h>

#define N   20
#include "BNtree.h"
  
struct node
{
    int key,count;
    struct node *left, *right;
    //struct node *Btr[N]; 
};


 struct node *Btr[N]; 

struct node *newNode(int item)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right= NULL;
    temp->count=0;
    return temp;
}
  
void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d \n", root->key);
        inorder(root->right);
    }
}
  

struct node * minValueNode(struct node* node)
{
    struct node* current = node;
 
   
    while (current->left != NULL)
        current = current->left;
 
    return current;
}

int findMax(struct node* node)
{
    // Base case
    if (node == NULL)
      return INT_MIN;
 
  
    int res = node->key;
    int lres = findMax(node->left);
    int rres = findMax(node->right);
    if (lres > res)
      res = lres;
    if (rres > res)
      res = rres;
    return res;
}

int findMin(struct node* node)
{
    // Base case
    if (node == NULL)
      return INT_MAX;
 
   
    int res = node->key;
    int lres = findMin(node->left);
    int rres = findMin(node->right);
    if (lres < res)
      res = lres;
    if (rres < res)
      res = rres;
    return res;
}


struct node* deleteNode(struct node* root, int key)
{
    // base case
    if (root == NULL) return root;
 

    if (key < root->key)
        root->left = deleteNode(root->left, key);
     //else if (key == root->key)
         // root->count--;
 
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
 
   
    else
    {
       
        if (root->left == NULL)
        {
            struct node *temp = root->right;
           if(root->count>=1)
            root->count--;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            if(root->count>=1)
            root->count--;
            free(root);
            return temp;
        }
 
        
        struct node* temp = minValueNode(root->right);
 
       
        root->key = temp->key;
 
      
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void Btree(struct node* node){
   for (int i=1; i<=N; i++)
        Btr[i] = 0;

}

void printBtree(struct node* node)
{
     if (node == NULL)
        return;
 
 
    
     printBtree(node->left);
    
 
    
     printBtree(node->right);
	
     printf("%d ", node->count);
}
struct node* insert(struct node* node, int key)
{
   
    if (node == NULL) return newNode(key);
 
   
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key == node->key)
          node->count++;
    else if (key > node->key)
        node->right = insert(node->right, key);   
 

    return node;
}
//////////////levelorder
void printLevelOrder(struct node* root)
{
    int h = height(root);
    int i;
    for (i=1; i<=h; i++)
        printGivenLevel(root, i);
}
 
/* Print nodes at a given level */
void printGivenLevel(struct node* root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->key);
    else if (level > 1)
    {
        printGivenLevel(root->left, level-1);
        printGivenLevel(root->right, level-1);
    }
}
 

int height(struct node* node)
{
    if (node==NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lheight = height(node->left);
        int rheight = height(node->right);
 
        /* use the larger one */
        if (lheight > rheight)
            return(lheight+1);
        else return(rheight+1);
    }
}
/////////////////////levvel order
  

void printPostorder(struct node* node)
{
     if (node == NULL)
        return;
 
    
     printPostorder(node->left);
 
   
     printPostorder(node->right);
 
    
     printf("%d ", node->key);
}

 

void printInorder(struct node* node)
{
     if (node == NULL)
          return;
 
    
     printInorder(node->left);
 
    
     printf("%d ", node->key);  
 
     
     printInorder(node->right);
}
 

void printPreorder(struct node* node)
{
     if (node == NULL)
          return;
 
     
     printf("%d ", node->key);  
 
    
     printPreorder(node->left);  
 
     printPreorder(node->right);
}

