#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include  "Priority_queue.h"

#define MAXSIZE 10
#define MAXSIZE_1 5
#define MAXSIZE_2 5

struct person{

    int idendite;
     char name[20];
    int  moneyT;
   };
//genel kuyruk
struct Queue {
  char  data[MAXSIZE];
  int first;//baş değer
  int last;//son değer
  int size;//eleman sayısı//boyut

 };
////customer kuyruğu
struct Queue_cust {
  char  data[MAXSIZE_1];
  int first;
  int last;
  int size;

 };
 //customer olayan kuyruk
struct Queue_nocust {
  char  data[MAXSIZE_2];
  int first;
  int last;
  int size;

 };



typedef struct Queue Queue;
typedef struct person person;
typedef struct Queue_cust Queue_cust;
typedef struct Queue_nocust Queue_nocust;



////////////////
////dinmik bir dizi ile baş ve son bilgisi tutuyorum.kuyruktan eklme veya çıkarma işlemi
// yaptığımda kuyruğu kaydırma gibi bir işlem yapmama gerek yok sadece baş ve son işaretlerini değiştirmem ilev görüyor.
//////////////////////////////////

void main() {
////kuyruk ve person kişilerimizi oluşturuyoruz
  Queue *q = malloc(1 * sizeof(Queue));
  person *m_0=malloc(1*sizeof(person));
  person *m_1=malloc(1*sizeof(person));
  person *m_2=malloc(1*sizeof(person));
  person *m_3=malloc(1*sizeof(person));
  person *m_4=malloc(1*sizeof(person));
  person *m_5=malloc(1*sizeof(person));
  person *m_6=malloc(1*sizeof(person));
  person *m_7=malloc(1*sizeof(person));
  person *m_8=malloc(1*sizeof(person));
  person *m_9=malloc(1*sizeof(person));
  person *m_10=malloc(1*sizeof(person));
  person *m_11=malloc(1*sizeof(person));
  person *m_12=malloc(1*sizeof(person));
  person *m_13=malloc(1*sizeof(person));
  init(q);

////müşteri olanların idenditesi true olsun olmyanların ise
///false olsun ,kuyruğa idendite ile para miktarı ile veya  isim ile kelme yapılabilir 
////ben kolay olması açısından idendite ile ekleme yapcam.
  m_0->moneyT=100;m_0->idendite=false; 
  m_1->moneyT=200;m_1->idendite=false;
  m_2->moneyT=100;m_2->idendite=false;
  m_3->moneyT=200;m_3->idendite=false;
  m_4->moneyT=200;m_4->idendite=false;
  m_5->moneyT=200;m_5->idendite=true;
  m_6->moneyT=200;m_6->idendite=true;
  m_7->moneyT=100;m_7->idendite=false; 
  m_8->moneyT=200;m_8->idendite=false;
  m_9->moneyT=100;m_9->idendite=false;
  m_10->moneyT=200;m_10->idendite=false;
  m_11->moneyT=200;m_11->idendite=false;
  m_12->moneyT=200;m_12->idendite=true;
  m_13->moneyT=200;m_13->idendite=true;


//////elemanları isimleri ilede koyabilriz farketmez.
//ben idenditeleri ile koymayı tercih ettim
//tasarıma göre farklı çözümler ve fikirler olabilir.ben böyle kolay olacağını düşündüğüm için böyle yapıyorum.
enqueue(q,m_0);
enqueue(q,m_1);
enqueue(q,m_2);
enqueue(q,m_3);
enqueue(q,m_4);
shift_all(q);
enqueue(q,m_5);
shift_all(q);
enqueue(q,m_6);
enqueue(q,m_7);
enqueue(q,m_8);
enqueue(q,m_9);
enqueue(q,m_10);

printf("dequeue:%d\n",dequeue(q));
printf("dequeue:%d\n",dequeue(q));
shift_all(q);
enqueue(q,m_11);
enqueue(q,m_12);
enqueue(q,m_13);


//kuyruğumuzu başlatıyoruz
  init(q);
//elemanları eklemeye başlıyoruz

///bu şekilde eklme daha güzel oluyor gibi ama anlamadığım bir şekilde şf /else blokları yanlış çalışıyor!!
/*
  if(m_0->idendite==false)
     enqueue(q,m_0);
   else if(m_o->idendite==true)
    shift_all(q);add_customer(q,m_0);
    else
    
    
  if(m_1->idendite==false)
     enqueue(q,m_1);
   else if(m_1->idendite==true)
    shift_all(q);add_customer(q,m_1);
    else;
    

  if(m_2->idendite==false)
     enqueue(q,m_2);
  else if(m_2->idendite==true)
    shift_all(q);add_customer(q,m_2);
    else
    

  if(m_3->idendite==false)
     enqueue(q,m_3);
   else if(m_3->idendite==true)
    shift_all(q);add_customer(q,m_3);
    else
    

  if(m_4->idendite==false)
     enqueue(q,m_4);
else if(m_4->idendite==true)
    shift_all(q);add_customer(q,m_4);
    else
    

  if(m_5->idendite==false)
     enqueue(q,m_5);
   else if(m_5->idendite==true)
    shift_all(q);add_customer(q,m_5);
    else
   

  if(m_6->idendite==false)
     enqueue(q,m_6);
  else if(m_6->idendite==true)
    shift_all(q);add_customer(q,m_6);
    else;
    
 
    if(m_7->idendite==false)
     enqueue(q,m_7);
  else if(m_7->idendite==true)
    shift_all(q);add_customer(q,m_7);
    else
    

  if(m_8->idendite==false)
     enqueue(q,m_8);
  else if(m_8->idendite==true)
    shift_all(q);add_customer(q,m_8);
    else
    

  if(m_9->idendite==false)
     enqueue(q,m_9);
  else if(m_9->idendite==true)
    shift_all(q);add_customer(q,m_0);
    else
    

  if(m_10->idendite==false)
     enqueue(q,m_10);
  else if(m_10->idendite==true)
    shift_all(q);add_customer(q,m_10);
    else
     


 
   printf("dequeue:%d\n",dequeue(q));
  printf("dequeue:%d\n",dequeue(q));
   
  if(m_11->idendite==false)
     enqueue(q,m_11);
   else if(m_11->idendite==true)
    shift_all(q);add_customer(q,m_11);
    else
    

  if(m_12->idendite==false)
     enqueue(q,m_12);
   else if(m_12->idendite==true)
    shift_all(q);add_customer(q,m_12);
    else;
    

  if(m_13->idendite==false)
     enqueue(q,m_13);
   else if(m_13->idendite==true)
    shift_all(q);add_customer(q,m_13);
    else
    
 
*/
////////////////////////////////////////
//////////////////////////////////////777
///////////////////////////////////77

///soru 5 ve 6 yeni bir main açmaya gerek yok bu işimizi görüyor
//genel kuyruğun fonksiyonlarını kullnarak   yeni kuyruklar açabiliriz.
//baş ve son işaretçileimiz oluşturduğumuz yeni kuyruğa özel olacağı için hehangi bir sorun oluşmuyor.
Queue_cust *q_cust = malloc(1 * sizeof(Queue_cust));
Queue_nocust *q_nocust= malloc(1 * sizeof(Queue_nocust));



 if(m_0->idendite==false)
     enqueue(q_nocust,m_0);
   else {enqueue(q_cust,m_0); }
  

 if(m_1->idendite==false)
     enqueue(q_nocust,m_1);
   else {enqueue(q_cust,m_1); }

  
 if(m_2->idendite==false)
     enqueue(q_nocust,m_2);
   else {enqueue(q_cust,m_2); }

  
 if(m_3->idendite==false)
     enqueue(q_nocust,m_3);
   else {enqueue(q_cust,m_3); }

  
 if(m_5->idendite==false)
     enqueue(q_nocust,m_5);
   else {enqueue(q_cust,m_5); }

 
 if(m_6->idendite==false)
     enqueue(q_nocust,m_6);
   else {enqueue(q_cust,m_6); }

/*enqueue(q_nocust,m_0);
enqueue(q_nocust,m_1);
enqueue(q_nocust,m_2);
enqueue(q_nocust,m_3);


enqueue(q_cust,m_5);
enqueue(q_cust,m_6);*/



 if(empty(q_cust)==0)
    printf("dequeue:%d\n",dequeue(q_nocust));
 else {printf("dequeue:%d\n",dequeue(q_cust)); }
 
 if(empty(q_cust)==0)
    printf("dequeue:%d\n",dequeue(q_nocust));
   else {printf("dequeue:%d\n",dequeue(q_cust)); }


 if(empty(q_cust)==0)
    printf("dequeue:%d\n",dequeue(q_nocust));
   else {printf("dequeue:%d\n",dequeue(q_cust)); }


}
