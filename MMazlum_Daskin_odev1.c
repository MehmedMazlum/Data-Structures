    //////**//////
    //Mehmet Mazlum DAŞKIN-Veri yapıları ödev1
   

    #include <stdio.h>

    #define SIZE 20  //global olarak dizi boyutu tanımlama.1.soru

     

    void get_value(int arr[]);

    void print_value(int arr[], int n);

    void function_sort(int arr[]);

    int find_intersection(int array1[], int array2[], int intersection_array[]);

    int find_union(int array1[], int array2[], int union_array[]);

     

    int main(int argc, char *argv[])

    {
        //intersection size en fazla SIZE kadar olabilir ama union bütün dizi farklıysa 2*SIZE kadar olacaktır
        int array1[SIZE], array2[SIZE], intersection_array[SIZE], union_array[SIZE*2];

        int number_s;

     

       

        get_value(array1);

        printf("\n\n 1.dizi Array_1: ");

        print_value(array1, SIZE);

     

        //1.dizyi sırlama, problemin karmaşıklığı  N^2  den nlog(n) e çekiyoruz.

        function_sort(array1);

        printf("\n sıralanmış Array_1: \n");

        print_value(array1, SIZE);

     

        


        get_value(array2);

        printf("\n\n 2.dizi Array 2: ");

        print_value(array2, SIZE);

     

      //problemin karmaşıklığını N^2 den Nlog(N)e çekiyoruz.

        function_sort(array2);

        printf("\n\nsıralanmış dizi Array 2: ");

        print_value(array2, SIZE);

     
         //sıralanmış array bulma işlemi intersetion ve union bulurken kolaylık sağlıyor 
           //diziler arasında ikili ikili karşılaştırma yapıldığı için N^2 yerine Nlog(N) zamanda iş görülüyor
        // Intersection bulma

        number_s = find_intersection(array1, array2, intersection_array);

        printf("\n\n Intersection : ");

        print_value(intersection_array, number_s);

     

        // Union bulma

        number_s= find_union(array1, array2, union_array);

        printf("\n\n Union : ");

        print_value(union_array, number_s);

    }

     

    void get_value(int arr[])

    {

        int i;

        for (i = 0; i < SIZE; i++)

        {

           
            scanf("%d", &arr[i]);
             
        }

    }

     

    void print_value(int arr[], int m)

    {

        int i;

        printf("{ ");

        for (i = 0; i < m; i++)

        {

            printf("%d ", arr[i]);

        }

        printf("}");

    }

     

    void function_sort(int arr[])

    {

        int k, m, gecici, p;

     

        for (k = 1; k < SIZE; k++)

        {

            p = 0;

            for (m = 0; m < SIZE-k; m++)

            {

                if (arr[m] > arr[m+1])

                {

                    gecici = arr[m];

                    arr[m] = arr[m + 1];

                    arr[m + 1] = gecici;

                    p = 1;

                }

            }

            if (p == 0)

            {

                break;

            }

        }

    }

     
   //diziler arasında ikili ikili arama yapıyor zaten sıralanmış dizide bunu yapmak oldukça kolay oluyor
    int find_intersection(int array1[], int array2[], int intersection_array[])

    {

        int i = 0, j = 0, k = 0;

        while ((i < SIZE) && (j < SIZE))

        {

            if (array1[i] < array2[j])

            {

                i++;

            }

            else if (array1[i] > array2[j])

            {

                j++;

            }

            else

            {

                intersection_array[k] = array1[i];

                i++;

                j++;

                k++;

            }

        }
         
       return(k);

    }

     
     //diziler arasında ikili ikili arama yapıyor,zaten sıralanmış dizide bunu yapmak oldukça kolay oluyor.
    int find_union(int array1[], int array2[], int union_array[])

    {

        int i = 0, j = 0, k = 0;

        while ((i < SIZE) && (j < SIZE))

        {

            if (array1[i] < array2[j])

            {

                union_array[k] = array1[i];

                i++;

                k++;

            }

            else if (array1[i] > array2[j])

            {

                union_array[k] = array2[j];

                j++;

                k++;

            }

            else

            {

                union_array[k] = array1[i];

                i++;

                j++;

                k++;

            }

        }

        if (i == SIZE)

        {

            while (j < SIZE)

            {

                union_array[k] = array2[j];

                j++;

                k++;

            }

        }

        else

        {

            while (i < SIZE)

            {

                union_array[k] = array1[i];

                i++;

                k++;

            }

        }

        return(k);

    }
