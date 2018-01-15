#include <time.h>
#include <stdio.h>
#include <stdbool.h>

 
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubbleSort(int arr[], int n)
{
   int i, j;
   bool swapped;
   for (i = 0; i < n-1; i++)
   {
     swapped = false;
     for (j = 0; j < n-i-1; j++)
     {
        if (arr[j] > arr[j+1])
        {
           swap(&arr[j], &arr[j+1]);
           swapped = true;
        }
     }
 
    
     if (swapped == false)
        break;
   }
}
 
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
     
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
void insertionSortD(double arr[], int n)
{
   int i,  j;
  double key;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;
 
     
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}
void bucketSort(int array[], int n)

{  

    int i, j;  

    int count[n]; 

    for (i = 0; i < n; i++)

        count[i] = 0;

 

    for (i = 0; i < n; i++)

        (count[array[i]])++;

 

    for (i = 0, j = 0; i < n; i++)  

        for(; count[i] > 0; (count[i])--)

            array[j++] = i;

}   
void selectionSort(int arr[], int n)
{
    int i, j, min_idx;
 
 
    for (i = 0; i < n-1; i++)
    {
        
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        
        swap(&arr[min_idx], &arr[i]);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];   
    int i = (low - 1);  
 
    for (int j = low; j <= high- 1; j++)
    {
       
        if (arr[j] <= pivot)
        {
            i++;    
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
 

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
       
        int pi = partition(arr, low, high);
 
       
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    
    int L[n1], R[n2];
 
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
 
   
    i = 0; 
    j = 0; 
    k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
  
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
   
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        
        int m = l+(r-l)/2;
 
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
}
 

void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void printArrayD(double arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%.5f ", arr[i]);
    printf("\n");
}
 
int main(){
int m;
printf("bir sayı giriniz ");
scanf("%d",&m);

int arr[m];

for(int i=0;i<m;i++){

	arr[i]=(rand()%100)+1;

}




 int n = sizeof(arr)/sizeof(arr[0]);
clock_t start = clock();
// Execuatable code

  
    bubbleSort(arr, n);
  
clock_t stop = clock();
printf("Sorted array: \n");
    //printArray(arr, n);
double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
printf("Time buble: %.5f", elapsed);
FILE *f = fopen("buble.txt", "wb");
fwrite(arr, sizeof(char), sizeof(arr), f);
fclose(f);


clock_t start1 = clock();
// Execuatable code

  
    selectionSort(arr, n);
  
clock_t stop1 = clock();
printf("Sorted array: \n");
    //printArray(arr, n);
double elapsed1 = (double)(stop1 - start1) * 1000.0 / CLOCKS_PER_SEC;
printf("Time selection: %.5f", elapsed1);
FILE *f1 = fopen("selection.txt", "wb");
fwrite(arr, sizeof(char), sizeof(arr), f1);
fclose(f1);



clock_t start2 = clock();
// Execuatable code

  
    bucketSort(arr, n);
  
clock_t stop2 = clock();
printf("Sorted array: \n");
    //printArray(arr, n);
double elapsed2 = (double)(stop2 - start2) * 1000.0 / CLOCKS_PER_SEC;
printf("Time bucket: %.5f", elapsed2);
FILE *f2 = fopen("bucket.txt", "wb");
fwrite(arr, sizeof(char), sizeof(arr), f2);
fclose(f2);




clock_t start3 = clock();
// Execuatable code

  
    mergeSort(arr,0, n-1);
  
clock_t stop3 = clock();
printf("Sorted array: \n");
    //printArray(arr, n);
double elapsed3 = (double)(stop3 - start3) * 1000.0 / CLOCKS_PER_SEC;
printf("Time merge: %.5f", elapsed3);
FILE *f3 = fopen("merge.txt", "wb");
fwrite(arr, sizeof(char), sizeof(arr), f3);
fclose(f3);



clock_t start4 = clock();
// Execuatable code

  
   quickSort(arr, 0, n-1);
  
clock_t stop4 = clock();
printf("Sorted array: \n");
    ///printArray(arr, n);
double elapsed4 = (double)(stop4 - start4) * 1000.0 / CLOCKS_PER_SEC;
printf("Time quick: %.5f", elapsed4);
FILE *f4 = fopen("quick.txt", "wb");
fwrite(arr, sizeof(char), sizeof(arr), f4);
fclose(f4);



clock_t start5 = clock();
// Execuatable code

  
    insertionSort(arr, n);
  
clock_t stop5 = clock();
printf("Sorted array: \n");
    //printArray(arr, n);
double elapsed5 = (double)(stop5 - start5) * 1000.0 / CLOCKS_PER_SEC;
printf("Time inseriton: %.5f", elapsed5);

FILE *f5 = fopen("inseriton.txt", "wb");
fwrite(arr, sizeof(char), sizeof(arr), f5);
fclose(f5);


double times[6]={0};
times[0]=elapsed;
times[1]=elapsed1;
times[2]=elapsed2;
times[3]=elapsed3;
times[4]=elapsed4;
times[5]=elapsed5;


clock_t start6 = clock();
// Execuatable code

  
    insertionSortD(times, 6);
  
clock_t stop6 = clock();
printf("Sorted array: \n");
    //printArray(arr, n);
double elapsed6= (double)(stop6 - start6) * 1000.0 / CLOCKS_PER_SEC;
printf("Times comparaison: %.5f", elapsed6);
printArrayD(times, 6);
FILE *f6 = fopen("Timescomparaison.txt", "wb");
fwrite(times, sizeof(char), sizeof(times), f6);
fclose(f6);


}
