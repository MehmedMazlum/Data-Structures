
#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
#include <math.h>
#include <time.h>
#define  k   2

// A structure to represent node of kd tree
struct Node
{
    int point[k]; // To store k dimensional point
    //char index[m];
    struct Node *left, *right;
};
 
// A method to create a node of K D tree
struct Node* newNode(int arr[])
{
    struct Node* temp = (struct Node *)malloc(sizeof(struct Node));
 
    for (int i=0; i<k; i++)
       temp->point[i] = arr[i];
      
        
   
        
    temp->left = temp->right = NULL;
    return temp;
}


dist(struct Node *a, struct Node *b, int dim)
{
    double t, d = 0;
    while (dim--) {
        t = a->point[dim] - b->point[dim];
        d += t * t;
    }
    return d;
}

int visited;//global value
 //nearest node function
void nearest(struct Node *root, struct Node *nd, int i, int dim,
        struct Node **best, double *best_dist)
{
    double d, dx, dx2;
 
    if (!root) return;
    d = dist(root, nd, dim);
    dx = root->point[i] - nd->point[i];
    dx2 = dx * dx;
 
    visited ++;
 
    if (!*best || d < *best_dist) {
        *best_dist = d;
        *best = root;
    }
 
    /* if chance of exact match is high */
    if (!*best_dist) return;
 
    if (++i >= dim) i = 0;
 
    nearest(dx > 0 ? root->left : root->right, nd, i, dim, best, best_dist);
    if (dx2 >= *best_dist) return;
    nearest(dx > 0 ? root->right : root->left, nd, i, dim, best, best_dist);
}


void printPostorder(struct Node* node, int point[],unsigned depth)
{   
    unsigned cd = depth % k;
     if (node == NULL)
        return;
 
    
     printPostorder(node->left, point, depth + 1);
 
   
     printPostorder(node->right, point, depth + 1);
 
    
     printf("%d  \n ",node->point[cd]);  
}

 

void printInorder(struct Node* node,int point[], unsigned depth)
{   
    
     unsigned cd = depth % k;
     if (node == NULL)
          return;
 
    
     printInorder(node->left, point, depth + 1);
 
    
    printf("%d  \n ",node->point[cd]);  
 
     
     printInorder(node->right ,point, depth + 1);
}
 

void printPreorder(struct Node* node,int point[], unsigned depth)
{   
     unsigned cd = depth % k;
     if (node == NULL)
          return;
 
     
     printf("%d  \n ",node->point[cd]);   
 
    
     printPreorder(node->left, point, depth + 1);  
 
     printPreorder(node->right, point, depth + 1);
}
 
// Inserts a new node and returns root of modified tree
// The parameter depth is used to decide axis of comparison
struct Node *insertRec(struct Node *root, int point[], unsigned depth)
{
    // Tree is empty?
    if (root == NULL)
       return newNode(point);
 
    // Calculate current dimension (cd) of comparison
    unsigned cd = depth % k;
 
    // Compare the new point with root on current dimension 'cd'
    // and decide the left or right subtree
    if (point[cd] < (root->point[cd]))
        root->left  = insertRec(root->left, point, depth + 1);
    else
        root->right = insertRec(root->right, point,depth + 1);
 
    return root;
}
 
// Function to insert a new point with given point in
// KD Tree and return new root. It mainly uses above recursive
// function "insertRec()"
struct Node* insert(struct Node *root, int point[])
{
    return insertRec(root, point, 0);
 }
// A utility method to determine if two Points are same
// in K Dimensional space
bool arePointsSame(int point1[], int point2[])
{
    // Compare individual pointinate values
    for (int i = 0; i < k; ++i)
        if (point1[i] != point2[i])
            return false;
 
    return true;
}
 
// Searches a Point represented by "point[]" in the K D tree.
// The parameter depth is used to determine current axis.
bool searchRec(struct Node* root, int point[], unsigned depth)
{
    // Base cases
    if (root == NULL)
        return false;
    if (arePointsSame(root->point, point))
        return true;
 
    // Current dimension is computed using current depth and total
    // dimensions (k)
    unsigned cd = depth % k;
 
    // Compare point with root with respect to cd (Current dimension)
    if (point[cd] < root->point[cd])
        return searchRec(root->left, point, depth + 1);
 
    return searchRec(root->right, point, depth + 1);
}
 
// Searches a Point in the K D tree. It mainly uses
// searchRec()
bool search(struct Node* root, int point[])
{
    // Pass current depth as 0
    return searchRec(root, point, 0);
}
 
// Driver program to test above functions
int main()
{
    struct Node *root = NULL;
    int points[19][k] = {{16, 43}, {5, 33}, {4, 22}, {6, 17},
                       {3, 10}, {4, 5}, {4, 4},{5, 2}, {16, 3}, {25, 2}, {32, 3}, {39, 2},
                       {46, 7}, {45, 13},{45, 17}, {44, 14}, {32, 29}, {26, 31},{28, 16}};
     char indexs[19]= {'A', 'B', 'C', 'D',
                       'E', 'F', 'G','H', 'I', 'J','K', 'L',
                       'M', 'N','O','P','R','S','T'};
    /* char indexs[19][m]= {{'A','A'}, {'B','B'},{'C', 'C'}, {'D','D'},
                       {'E','E'}, {'F','F'}, {'G','G'},{'H','H'},{'I', 'I'}, {'J','J'},{'K','K'}, {'L','L'},
                       {'M','M'}, {'N','N'},{'O','O'},{'P','P'},{'R','R'},{'T','T'}};*/
    int n = sizeof(points)/sizeof(points[0]);
    unsigned depth=0;
    
    
    for (int i=0; i<n; i++)
       root = insert(root, points[i]);
 ////////////////////////////////////////////////77777
     int point1[] = {5, 33};
    (search(root, point1))? printf("found:\n"): printf("Not found:\n");
 
    int point2[] = {12, 19};
    (search(root, point2))? printf("found:\n"): printf("Not found:\n");
////arama fonksiyonlarım sadece level durumuna göre x veya y indeksindeki sayıyı yazdırıyor.
  /////////////////////////////
   printf("ınorder\n");
    printInorder(root,points,depth);
    printf("ınorder\n");
  ///////////////////////////7
    printf("postorder\n");
    printPostorder(root,points,depth);
    printf("postorder\n");
  ////////////////////////////////
    printf("preorder\n");
    printPreorder(root,points,depth);
    printf("preorder\n");
////////////////////////////////////////////////7
    struct Node testNode = {{6, 7}};
    struct Node *found, *million;
    double best_dist;
 
   // root = make_tree(wp, sizeof(wp) / sizeof(wp[1]), 0, 2);
 
    visited = 0;
    found = 0;
    nearest(root, &testNode, 0, 2, &found, &best_dist);
    //double sqrt=sqrt(best_dist);
 
    printf(">> K-d tree\nsearching for (%d, %d)\nfound (%d, %d) seen %d nodes. indexs:%c \n\n",testNode.point[0], testNode.point[1],found->point[0], found->point[1], visited-1,indexs[visited-1]);
 
   //////////////////////////////////////////////////////////////////
  //////////////////////////////////////////////////////////////////77
  ////yeni bir ağaç


    struct Node *root1 = NULL;
    
  int points1[19][k] = {{25, 2},{3, 10}, {28,16}, {5, 2}, {16, 3},
                       {6, 17}, {16, 43}, {5, 33},{4, 22}, {32, 29}, {39, 2}, {26, 31}, {44, 24},
                       {45, 17}, {32, 3},{46, 7}, {4, 4}, {4, 5}, {45, 13}};
   char indexs1[19] ={'J','E', 'T', 'H', 'I', 'D', 'A', 'B', 'C', 'R', 'L', 'S', 'P', 'O', 'K', 'M', 'G', 'F', 'N'};
    //int n = sizeof(points)/sizeof(points[0]);
   
    
    
    for (int i=0; i<n; i++)
       root1 = insert(root1, points1[i]);
 ////////////////////////////////////////////////77777
     int point3[] = {5, 33};
    (search(root1, point3))? printf("found:\n"): printf("Not found:\n");
 
    int point4[] = {12, 19};
    (search(root1, point4))? printf("found:\n"): printf("Not found:\n");
       
   struct Node testNode3 = {{25, 25}};
  struct Node testNode1 = {{14, 34}};
   struct Node testNode2 = {{5, 27}};
    
   // root = make_tree(wp, sizeof(wp) / sizeof(wp[1]), 0, 2);
 
    visited = 0;
    found = 0;
    nearest(root1, &testNode3, 0, 2, &found, &best_dist);
   
     printf(">> K-d tree\nsearching for (%d, %d)\nfound (%d, %d) seen %d nodes. indexs:%c \n\n",testNode.point[0], testNode.point[1],found->point[0], found->point[1], visited-1,indexs1[visited-1]);
     nearest(root1, &testNode1, 0, 2, &found, &best_dist);
       printf(">> K-d tree\nsearching for (%d, %d)\nfound (%d, %d) seen %d nodes. indexs:%c \n\n",testNode.point[0], testNode.point[1],found->point[0], found->point[1], visited-1,indexs1[visited-1]);
       nearest(root1, &testNode2, 0, 2, &found, &best_dist);
            printf(">> K-d tree\nsearching for (%d, %d)\nfound (%d, %d) seen %d nodes. indexs:%c \n\n",testNode.point[0], testNode.point[1],found->point[0], found->point[1], visited-1,indexs1        [visited-1]);
    


      return 0;
}
