#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>

#include "circuler_linked_list.h"
#include  "Circuler_double_linked_list.h"
#include "liner_linked_list.h"
#include   "Doubled_linked_list.h"


 
struct Node
{
  int data;
  struct Node *next;
  struct Node *prev;
};

  







int main()
{
printf("Doğrusal liste için");
////doğrusal linked list için olan kısım
	//////////////////

	    struct Node *head = NULL;
    struct Node *head1= NULL;
    struct Node *head2= NULL;
 
   
   push(&head,1);
     push(&head,2);
       push(&head,3);
         push(&head,4);
           push(&head,5);
             insertAfter(head,6);
               insertAfter(head,7);
                 insertAfter(head,8);
                   append(&head,9);
                     append(&head,10);
    
int count=0;
    count=getCount(head);
    printf("count  %d:\n",count);
    printf("Liste:");
    printList(head);

    push(&head1,1);
     push(&head1,2);
       push(&head1,3);
         push(&head1,4);
           push(&head1,5);
             insertAfter(head1,6);
               insertAfter(head1,7);
                 insertAfter(head1,8);
                   append(&head1,9);
                     append(&head1,10);
                       

              push(&head2,1);
                push(&head2,2);
                  push(&head2,3);
                    push(&head2,4);
                      push(&head2,5);
                        insertAfter(head2,6);
                          insertAfter(head2,7);
                            insertAfter(head2,8);
                              append(&head2,9);
                                append(&head,10);
                      ///head1 ve hed2 listeleri baş kısmı head1 olarak güncelendi.
                      union_list(&head1,&head2);
                      printf("birleşmeden sonra liste:\n");
                      printList(head1);

  if(search(head,2))
    printf("Evet arama değeri bulundu\n");
      else
        printf("aradığınız değer bulunamadı\n");

          ListDelete(&head,2);
            printf("liste den 2 değeri silindikten sonra\n");
            printList(head);
    reverse(&head);
    printf("reverse yapıldıktan sonraki lste:\n");
    printList(head);
    //////////////çift bağlı  linked list için olan kısım.
    /////////////////////////777
    ////////////////////7777
    ////////////77777
   printf("\n\n\nçift bağlı doğrusal liste için");
    struct Node *head3 = NULL;
 
   
     printf("liste:\n");
     push_double_linkedlist(&head3,1);
       push_double_linkedlist(&head3,2);
         push_double_linkedlist(&head3,3);
           push_double_linkedlist(&head3,4);
             push_double_linkedlist(&head3,5);
             
             printList_double_linkedlist(head3);
              printf("\nsondan ekleme yapıldıktan sonra\n");
               append_double_linkedlist(&head3,6);
                 append_double_linkedlist(&head3,7);
                   append_double_linkedlist(&head3,8);
                   
                   printList_double_linkedlist(head3);
                     printf("\nafter  ekleme yapıldıktan sonra\n");
                     insertAfter_double_linkedlist(head3,9);
                       insertAfter_double_linkedlist(head3,10);
                      
                           printList_double_linkedlist(head3);
                             printf("\nsilme den sonra liste:\n");
                             deleteNode__double_linkedlist(&head3,4);
                             
                             printList_double_linkedlist(head3);
                             /////////////////////////77
                             //////////////////////////////77

///////////////7tek yönlü circuler list
              //////////////////////7777
                             //////////////////777777777
                             /////////////////77777777
                             //////////////7

    printf("\n\n\nTek bağlı circuler liste için\n");
         struct Node *head4 = NULL;
   printf("liste:\n");
    push_C_list(&head4,1);
      push_C_list(&head4,2);
        push_C_list(&head4,3);
          push_C_list(&head4,4);
            push_C_list(&head4,5);
             printList_C_list(head4);
             printf("sondan ekleme:\n");
              insertEnd_C_list(&head4,6);
                insertEnd_C_list(&head4,7);
                  insertEnd_C_list(&head4,8);
                   
                   printList_C_list(head4);
                    printf("after eklemesi\n");
                     insertAfter_C_list(&head4,9);
                      insertAfter_C_list(&head4,10);
                      printList_C_list(head4);
                        printf("düğüm siindikten sonra\n");
                         deleteNode_C_list(&head4,5);
                          printList_C_list(head4);


                          //////////////////7777
                          ///////////////777777777777
                          ////////////////////777

//////////çift yönlü ciirculer list
                          ///////////////777777
                          ///////////777777777777
                          //////////7
        printf("\n\n\nÇift bağlı circuler liste için");
       struct Node *head5 = NULL;
 
   
   printf("liste:\n");
    printf("bastan ekleme");
    /////////İNSERT FONKSİYONU ANLAYAMADIĞIM BİR SEBEPTEN DOLAYI SEGMENTATİON HATASI VERİYOR!!!! 
   //////////////sebebini anlayamadım
    /*insertBegin_circuler_double(&head5,1);
      insertBegin_circuler_double(&head5,2);
        insertBegin_circuler_double(&head5,3);
          insertBegin_circuler_double(&head5,4);
            insertBegin_circuler_double(&head5,5);	
             display_circuler_double(head5);
             //////////////////////////7
             */
              printf("sondan ekleme\n");
               insertEnd_circuler_double(&head5,6);
                  insertEnd_circuler_double(&head5,7);
                     insertEnd_circuler_double(&head5,8);
                      display_circuler_double(head5);
                        printf("after eklemesi\n");
                        insertAfter_circuler_double(&head5,9);
                          insertAfter_circuler_double(&head5,10);
                            display_circuler_double(head5);
                              printf("delete işlemi\n");
                                deleteNode_circuler_double(&head5,8);
                                display_circuler_double(head5); 
                        
 

    return 0;
}
