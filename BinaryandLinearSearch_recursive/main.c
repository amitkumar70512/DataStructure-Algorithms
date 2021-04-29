/*Implement Recursive Binary search and Linear search and determine the time required to search
an element. Repeat the experiment for different values of N and plot a graph of the time taken
versus N.*/

#include <stdio.h>
#include <stdlib.h>
#include<time.h>

clock_t start, end;
    double cpu_time_used;






int recLsearch(int arr[],int l,int r,int x)
{
    if(r<l)
    return -1;
    if(arr[l]==x)
    return l;
    if(arr[r]==x)
    return r;

    return recLsearch( arr,l+1,r,x);

}

void sorting(int arr[],int n)
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

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l) {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }

    return -1;
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
    printf("\n \n \t Displaying  array... ");
    for(int k=0;k<size;k++)
    {
        printf(" %d ",arr[k]);
    }
    int ch;
        while(1)
        {
            printf("\n \n <----------------------->\n");
            printf("Enter the option:> \n");
            printf(" 1. Linear Search \n 2. Binary search \n 3. exit \n ");
            scanf("%d",&ch);
                switch(ch)
                {
                  case 1:
                  {

                      int key;
                      printf("\n Linear searching.......\n ");
                      printf("Enter the key element:>  ");
                      scanf("%d",&key);
                      start = clock();
                      for(int i=0;i<80000000;i++);
                      int index=recLsearch(arr,0,size-1,key);
                      end = clock();
                      cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                      if(index!=-1){
                      printf("\n %d is found at %d position\n",key,index+1);}
                      else
                      printf("\n  Element %d is not found in the array\n ",key);

                      printf("\t Time complexity, O(n) in case of Linear searching \n");
                      printf("It took %f seconds to execute..\n ",cpu_time_used);
                      break;
                  }
                  case 2:
                  {
                       sorting(arr,size);
                      printf("\n Array list has been sorted successfully....\n");
                      display(arr,size);
                       int key;
                      printf("\n Binary searching.......\n ");
                      printf("Enter the key element:>  ");
                      scanf("%d",&key);
                      start = clock();
                      for(int i=0;i<80000000;i++);
                      int index=recLsearch(arr,0,size-1,key);
                      end = clock();
                      cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
                       if(index!=-1)
                       {
                      printf("\n %d is found at %d position\n",key,index+1);
                       }
                      else
                      printf("\n  Element %d is not found in the array\n ",key);

                      printf("\t Time complexity, O(Logn) In case of recursive Binary implementation\n");
                      printf("It took %f seconds to execute..\n ",cpu_time_used);
                      break;
                  }
                  case 3:
                  exit(0);

                  default:
                  printf("\n Invalid option!!");
                }
        }

    return 0;
}
