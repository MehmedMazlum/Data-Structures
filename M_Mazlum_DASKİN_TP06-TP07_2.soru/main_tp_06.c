#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#include<string.h>


#include "BNtree.h"



struct node
{
    int key,count;
    struct node *left, *right;
    //struct node *Btr[N]; 
};








int main()
{
    
    
    struct node *root = NULL;
   

  
   
    

     //struct node *root1 = NULL;
     struct node *root1  = newNode(1);
     
 
  	int input;
   
     int a,b;
    int grad=1;
   while(grad==1){
  printf("bir sayi giriniz");
   scanf("%d",&input);
   if (input==9)
    grad=2;
   switch(input) {
      case 1 :



       //struct node *root = NULL;
  root = insert(root, 50);
       insert(root, 30);
       insert(root, 30);
       insert(root, 20);
       insert(root, 40);
       insert(root, 70);
       insert(root, 60);
       insert(root, 80);
             

	//struct node *root1  = newNode(1);
       printf("örnek girdi:\n");
       printf("\nPreorder traversal of binary tree is \n");
           printPreorder(root);
          
         break;
      case 2 :
          printf("\nDelete 20\n");
          root = deleteNode(root, 20);
         printf("Inorder traversal of the modified tree \n");
         inorder(root);
  
	 break;
      case 3 :
            a= findMax(root);
           printf("Max:%d\n",a);
         
         break;
      case 4 :
         b=findMin(root);
	printf("Min:%d\n",b);
         break;
      case 5 :
           printf("\nPreorder traversal of binary tree is \n");
           printPreorder(root);
 
         break;
	case 6 :
            printf("\nInorder traversal of binary tree is \n");
     printInorder(root);  
         break;
      case 7 :
            printf("\nPostorder traversal of binary tree is \n");
        printPostorder(root);
	 break;
      case 8 :
        printf("\nLevel order traversal of binary tree is \n");
         printLevelOrder( root);
         break;
     
      default :
            printf("çıkış");
         
   }



}


  ///////////////////////////////77
///bu soru tp-07 nin 2.sorusunun cevabıdır.
   	 //Btree(root);
   printf("bu soru tp-07 nin 2.sorusunun cevabıdır.\n");
   printf("print Btree:\n");
    printBtree(root);
  
  
    return 0;
}
