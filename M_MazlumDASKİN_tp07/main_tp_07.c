#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<string.h>

#include "Expression_tree.h"
struct et
{
	char value;
	struct et *left, *right;
};

int main()
{
       ////////////////////////////////////////777777
/////////////////////////////////
///////////////777
//////77777
///////777
   //      girilecek sayıları ikili,ikili olrak düşündüm.
   //      sayılar geldikten sonra yapılacak operation sonlarına eklenecek.
  //       böylece   expression olarak ikili ağacı oluşturabiliriz. 
   
	 char postfix[] = "(ab+)(ef*g*)-";
	struct et *r =  (struct et *)malloc(sizeof(struct et));
	 r = constructTree(postfix);
	printf("\ninfix expression is \n");
	inorder1(r);
  
    return 0;
}
