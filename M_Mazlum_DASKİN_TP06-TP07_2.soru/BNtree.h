#ifndef BNtree_H_
#define BNtree_H_







struct node *newNode(int item);
void inorder(struct node *root);
struct node * minValueNode(struct node* node);
int findMax(struct node* node);
int findMin(struct node* node);
struct node* deleteNode(struct node* root, int key);
void Btree(struct node* node);
void printBtree(struct node* node);
struct node* insert(struct node* node, int key);
void printLevelOrder(struct node* root);
void printGivenLevel(struct node* root, int level);
int height(struct node* node);
void printPostorder(struct node* node);
void printInorder(struct node* node);
void printPreorder(struct node* node);


#endif
