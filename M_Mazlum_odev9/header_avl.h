#ifndef header_avl_H_
#define  header_avl_H_

//void preOrder( *root);
struct Node* deleteNode(struct Node* root, int key);
struct Node * minValueNode(struct Node* node);
 
struct Node* insert(struct Node* node, int key);
int getBalance(struct Node *N);
struct Node *leftRotate(struct Node *x);
struct Node *rightRotate(struct Node *y);
struct Node* newNode(int key);
int max(int a, int b);
int height(struct Node *N);
#endif
