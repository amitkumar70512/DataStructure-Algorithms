
#include <stdio.h>
#include <stdlib.h>
#include<time.h>

void InsertionSorting(int arr[],int n)
{
    int i,j,temp;
    for (i = 1 ; i <= n - 1; i++)
    {
	    j = i;
            while ( j > 0 && arr[j-1] > arr[j])
            {
                temp     = arr[j];
                arr[j]   = arr[j-1];
                arr[j-1] = temp;
                j--;
            }
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
            printf(" 1.  Insertion sort \n 2. display \n 3. exit \n ");
            scanf("%d",&ch);
                switch(ch)
                {

                  case 1:
                  {
                      double time_spent = 0.0;
                      clock_t begin = clock();
                      for(int i=0;i<80000000;i++);
                       InsertionSorting(arr,size);
                        clock_t end = clock();
                      printf("\n Array list has been sorted successfully.... using Insertion sort\n");
                      time_spent += (double)(end - begin) / CLOCKS_PER_SEC;

    printf("The elapsed time is %f seconds", time_spent);


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
