#ifndef Expresion_tree_H_
#define Expression_tree_H_





//void push1(struct et *et);
struct et *pop();
bool isOperator(char c);
bool isOp(char c);
bool isOpp(char c);
void inorder1(struct et *t);
struct et* newNode1(int v);
struct et* constructTree(char postfix[]);

#endif
