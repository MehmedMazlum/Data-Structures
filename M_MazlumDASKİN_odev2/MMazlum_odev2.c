#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>


int okek(int a,int b,int c);//1.soru
int obeb(int a1,int b1,int c1);//2.soru
void islemler_(float a,float b);//3.soru
void islemler_1(float a,float b,char c);//4.soru
void asal(int a);//5.soru
void  asallar();//6.soru
void asal_carpanlar(int a);//7.soru
void fark_hesapla(double arr[],double arr1[]);//8.soru
void ucgen(int a,int b,int c);//9.soru
int collatz(int a,int b);//10.soru
void dizi_arama(int a);//11.soru
void histogram();//12.soru
void matris_carpim_toplam();//13.soru
void dogru_denklemi();//14.soru




struct dogru {
   double m;
   double n;
   double x1,x2;
   double y1,y2;

} dogru1;
 
int main() {
    //1 ve 2 soru cevapları
    printf("Slm! ben bir C programıyım,ufak bir test deneycez.\n\n");
    int sayi1,sayi2,sayi3;
    int okek1,obeb1;
    int count=1;
    int control=0;
    while(count<5 && control==0){
    
    printf("Birinci Sayiyi Giriniz: \n");
    scanf("%d", &sayi1);
       printf("Ikinci Sayiyi Giriniz: \n");
       scanf("%d", &sayi2);
           printf("üçüncü Sayiyi Giriniz: \n");
           scanf("%d", &sayi3);
    if(sayi1>0 && sayi2>0 && sayi3>0){
    okek1 = okek(sayi1,sayi2,sayi3);
    obeb1= obeb(sayi1,sayi2,sayi3);
    printf(" sayıların okeki %d \n",okek1);
    printf(" sayiların obebi %d \n",obeb1);
    break;
    
      }
      count++;
      int hak=5-count;
      printf("%d hakkın kaldı \n ",hak);
      if(hak==0)
        printf("Program bitti! diğer sorulara geçilecek!\n");
                                   }
//3. ve 4soru cevapları
int a2,b2;
char c2;
printf("Bir Sayiyi Giriniz: \n");
scanf("%d", &a2);
printf("Ikinci Sayiyi Giriniz: \n");
scanf("%d", &b2);
islemler_(a2,b2);
printf("+,-,*,/ opreratörlerinden birini giriniz: \n");
scanf("%s", &c2);

printf("operatörlü cevap!");
islemler_1(a2,b2,c2);





 //5ve 6 ,7cevapları
int a3;
printf("Birinci Sayiyi Giriniz: \n");
scanf("%d", &a3);
asal(a3);

//1-1200 arasındaki asallar
asallar();//6.soru
int num;
printf("\nbir sayı giriniz\n:");//7.soru
scanf("%d",&num);
asal_carpanlar(num);







//8 ve 9 sorular


//int x=(a,b)
//int y=(c,d)
double a,b,c,d;
printf("Birinci Sayiyi Giriniz: \n");
scanf("%lf", &a);
printf("Ikinci Sayiyi Giriniz: \n");
scanf("%lf", &b);
printf("Üçüncü Sayiyi Giriniz: \n");
scanf("%lf", &c);
ucgen(a,b,c);
printf("\ndördüncü Sayiyi Giriniz: \n");
scanf("%lf", &d);
double arr[2]={a,b};
double arr1[2]={c,d};


printf("\nfark hesaplanacak\n");
fark_hesapla(arr,arr1);

//soru10
int k=0;
printf("\nBir Sayi Giriniz: \n");
int a4;
scanf("%d", &a4);
int control1=collatz(a4,k);
control1++;
printf("%d kadar adımda bu etorem gerçekleşti \n",control1);




//soru11
int a1;
printf("Bir  Sayi Giriniz: \n");
scanf("%d", &a1);
dizi_arama(a1);//soru bitti

//soru12
printf("histogram \n");
histogram();


//soru13


matris_carpim_toplam();


//soru14
//
dogru_denklemi();

return 0;
                                       
}

 
    
 



int okek(int x,int y, int z)
{
        long max,lcom, count, flag=0;
        if(x>=y&&x>=z)
                max=x;
        else if(y>=x&&y>=z)
                max=y;
        else if(z>=x&&z>=y)
                max=z;
        for(count=1;flag==0;count++)
        {
                lcom=max*count;
                if(lcom%x==0 && lcom%y==0 && lcom%z==0)
                {
                        flag=1;
                }
        }
        return lcom;  


}
 
int obeb(int p, int q, int r)
{
        int gcf=1,flag=0, count;
        for(count=1; flag==0;count++)
        {
                if(p%count==0&&q%count==0&&r%count==0)
                        gcf=count;
                if(count>p&&count>q&&count>r)
                {
                        flag=1;
                }
        }
        return gcf;
}
 



void islemler_(float a,float b){

printf("toplama islemi %f \n",a+b);
printf("çıkarma işlemi %f \n",a-b);
printf("çarpma işlemi %f \n",a*b );
printf(" bölme işlemi %f \n", a/b);

     

}
void islemler_1(float a,float b,char d){



     char c=d;

    if(c =='+')
        printf("\ntoplama islemi %f \n",a+b);
    else if (c =="-")
        printf("çıkarma işlemi %f \n",a-b);
    else if(c =='*')
        printf("çarpma işlemi %f \n",a*b );
    else 
        printf(" bölme işlemi %f \n",a/b);

}


void asal(int a){

     
     int count=0;

     for(int i=2;i<=a ; i++)
        if(a%i==0)
            count++;

  if(count==1)
    printf("sayı asaldır\n");
  else 
    printf("sayı sasal değildir\n");




}
 
 void asallar(){

   printf("1-1200 arasındakı asal sayılar:\n");

     int count=0;
   for(int j=2;j<1201;j++){
     for(int i=1;i<= j ; i++){
         if(j%i==0)
            count++;

            } 

              if(count==2)
              printf(" %d ,",j);
         count=0; 
   }
   printf("\nsayıları asaldır");

 }
  void asal_carpanlar(int a){
 int num,i=1,j,k;
  num=a;
  printf("asal çarpanlar");
  while(i<=num){
      k=0;
      if(num%i==0){
         j=1;
          while(j<=i){
            if(i%j==0)
                 k++;
             j++;
          }
          if(k==2)
             printf("\n%d\n",i);
      }
      i++;
   }
}

 void ucgen(int a,int b,int c){
      if(a+b > c && a+c>b && b+c > a && abs(b-a)<c  && abs(c-a)<b &&  abs(c-b)<a )
           return printf(" bu bir üçgendir");
       else return printf("bu bir üçgen değildir");;
 
      }

void fark_hesapla(double arr[],double arr1[]){
      //#include<math.h>
      double fark=0;
      fark= sqrt(pow(abs(arr[0]-arr1[0]),2)+pow(abs(arr[1]-arr1[1]),2));
      printf("  fark %lf olarak bulundu!\n ",fark);


}



int collatz(int n, int k)
{
    int count1=0;
    if(n==1)
    {
        return k;
    }
    // Case where n is even.
    else if(n%2==0)
    {
        k = k+1;
        n = n/2;
        printf("%d\n", n);
        count1++;

        collatz(n,k);
    }
   
    else
    {
        k = k+1;
        n = 3*n+1;
        printf("%d\n", n);
        count1++;
        collatz(n,k);
    }
}


void dizi_arama(int b){
    int count2=0;
    int a=b;
    int arr2[10]={1,2,3,4,5,6,7,8,9,10};
    //int arr3[10]={};
    printf("sayının geçtiği indeksler\n");
    for(int i=0;i<10;i++){
     if(arr2[i]==a){
        printf("[%d]\n",i);
    
        //arr3[j]=i;
        count2++;
        }

    }
    if (count2>0)
    {
        
        printf("%d sayısı dizide %d  kere vardır \n", a,count2);
        
        
      

    }
    
    
}

void histogram(){

    int arr4[10]={1,2,3,4,5,6,7,8,9,10};

    for(int i=0;i<10;i++){
        printf("%d grup",i);
            for(int j=0;j<i;j++)
                printf("*");
                printf("\n");
    }
 }



void matris_carpim_toplam(){
          int m, n, c, d, first[10][10], second[10][10], sum[10][10];
   printf("aynı satır sutun alınarak boyut kontrolü yapılmış olacaktır\n");
   printf(" Matrisler için satır ve sütün değerleri giriniz\n");
   scanf("%d%d", &m, &n);
   printf("Birinci matris değerleri\n");
 
   for (c = 0; c < m; c++)
      for (d = 0; d < n; d++)
         scanf("%d", &first[c][d]);
 
   printf("İkinci  matris değerleri giriniz\n");
 
   for (c = 0; c < m; c++)
      for (d = 0 ; d < n; d++)
            scanf("%d", &second[c][d]);
 
   printf("Matris toplamları:-\n");
 
   for (c = 0; c < m; c++) {
      for (d = 0 ; d < n; d++) {
         sum[c][d] = first[c][d] + second[c][d];
         printf("%d\t", sum[c][d]);
      }
      printf("\n");
   }
      printf("Matris çarpımları:-\n");
 
   for (c = 0; c < m; c++) {
      for (d = 0 ; d < n; d++) {
         sum[c][d] = first[c][d] * second[c][d];
         printf("%d\t", sum[c][d]);
      }
      printf("\n");
   }

}


void  dogru_denklemi(){
      printf("bir x1 değeri giriniz\n");
      scanf("%lf", &dogru1.x1);
      printf("bir x2 değeri giriniz\n");
      scanf("%lf", &dogru1.x2);
      printf("bir y1 değeri giriniz\n");
      scanf("%lf", &dogru1.y1);
      printf("bir y2 değeri giriniz\n");
      scanf("%lf", &dogru1.y2);
     
      
      
      dogru1.m=0;
      dogru1.n=0;
      
      

      //y=mx+n
      //m eğim demektir m=(y2-y1)(x2-x1)
      dogru1.m=(dogru1.y2-dogru1.y1)/(dogru1.x2-dogru1.x1);

      //n değerini bulmak için x1,y1 değerini yerine yazalım
       dogru1.n=dogru1.y1-dogru1.m*dogru1.x1;

       printf("dogru denklemi:");
       printf("y = %lfX + %lf\n",dogru1.m,dogru1.n );


}

