#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>
#include "Expression_tree.h"

// An expression tree node
struct et
{
	char value;
	struct et *left, *right;
};

int top=-1;
struct et *st[20];
//struct et *st[20] =  (struct et *)malloc(sizeof(struct et));
//struct et *st =  (struct et *)malloc(sizeof(struct et));


void push1(struct et* et)
{
    st[++top]=et;
}

struct et *pop()
{
    return(st[top--]);
}

bool isOperator(char c)
{
	if (c == '+' || c == '-' ||
			c == '*' || c == '/' ||
			c == '^')
		return true;
	return false;
}

bool isOp(char c)
{
	if (c == '(')
		return true;
	return false;
}
bool isOpp(char c)
{
	if (c == ')')
		return true;
	return false;
}



void inorder1(struct et *t)
{
	if(t)
	{
		inorder1(t->left);
		printf("%c ", t->value);
		inorder1(t->right);
	}
}


struct et* newNode1(int v)
{       struct et *temp =  (struct et *)malloc(sizeof(struct et));
	//et *temp = new et;
	temp->left = temp->right = NULL;
	temp->value = v;
	return temp;
}


struct et* constructTree(char postfix[])
{
	//stack<et *> st;
	//et *t, *t1, *t2;
	//struct et *st =  (struct et *)malloc(sizeof(struct et));
        struct et *t =  (struct et *)malloc(sizeof(struct et));
	struct et *t1 =  (struct et *)malloc(sizeof(struct et));
	struct et *t2 =  (struct et *)malloc(sizeof(struct et));
	struct et *t3 =  (struct et *)malloc(sizeof(struct et));


	for (int i=0; i<strlen(postfix); i++)
	{
		// If operand, simply push into stack
		if (!isOperator(postfix[i]) && !isOp(postfix[i]) && !isOpp(postfix[i]))
		{
			t = newNode1(postfix[i]);
			push1(t);
		}
		else if(isOperator(postfix[i])) // operator
		{
			t = newNode1(postfix[i]);

			// Pop two top nodes
			t->right=pop();
      			t->left=pop();
    			push1(t);
			//t1 = st.top(); 
			//st.pop();	 
			//t2 = st.top();
			//st.pop();

			
			//t->right = t1;
			//t->left = t2;

			
			//st.push(t);
		}
		else if(isOp(postfix[i])){



		}
		else if(isOpp(postfix[i])){



		}
	}

	
	t3 = pop();
	//st.pop();

	return t3;
}


