

#include <stdio.h>
#include <stdlib.h>
#include<time.h>
void SelectionSorting(int arr[], int n)
{
    int i, j, min;

    for (i = 0; i < n-1; i++)
    {
          min = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min])
            min = j;

        // Swap the found minimum element with the first element

        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}

    void display(int arr[],int size)
    {
         printf("\n \n \t Displaying entered array.. ");
        for(int k=0;k<size;k++)
        {
            printf(" %d ",arr[k]);
        }
    }

int main()
{
    int size;
    printf("\n Enter the number of elements for an array:> \t");
    scanf("%d",&size);
    int arr[size];
    printf("\n enter the %d elements in the array.\n",size);
        for(int i=0;i<size;i++)
        {
            printf("\nelement %d:- ",i+1);
            scanf("%d",&arr[i]);

        }

    int ch;
        while(1)
        {
            printf("\n \n <----------------------->\n");
            printf("Enter the option:> \n");
            printf(" 1. Selection sort \n 2. display \n 3. exit \n ");
            scanf("%d",&ch);
                switch(ch)
                {
                  case 1:
                  {
                      clock_t t;
                        t = clock();
                        for(int i=0;i<80000000;i++);
                      SelectionSorting(arr,size);
                        t = clock() - t;
                        double time_taken = ((double)t)/CLOCKS_PER_SEC; // in seconds
                         printf("\n Array list has been sorted successfully.... using Selection sort\n");
                           printf("It took %f seconds to execute \n", time_taken);


                      break;

                  }

                  case 2:
                  display(arr,size);
                  break;

                  case 3:
                  exit(0);

                  default:
                  printf("\n Invalid option!!");
                }
        }

    return 0;
}
