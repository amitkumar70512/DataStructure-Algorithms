#include<stdio.h>
#include<time.h>

clock_t start,end;
double cpu_time_used;


void quicksort(int number[],int first,int last)
{
int i, j, pivot, temp;
    if(first<last)
    {
        pivot=first;
        i=first;
        j=last;
            while(i<j){
                while(number[i]<=number[pivot]&&i<last)
                i++;
                while(number[j]>number[pivot])
                j--;
                if(i<j){
                temp=number[i];
                number[i]=number[j];
                number[j]=temp;
                }
            }
        temp=number[pivot];
        number[pivot]=number[j];
        number[j]=temp;
        quicksort(number,first,j-1);
        quicksort(number,j+1,last);
    }
}

void display(int *arr, int n)
{
    for(int j=0;j<n;j++)
        printf(" %d ",arr[j]);

}
int main(){
int i, n;
printf("Enter number of elements ");
scanf("%d",&n);
int number[n];
printf("Enter %d elements: \n", n);
    for(i=0;i<n;i++)
    scanf("%d",&number[i]);

    start = clock();

    quicksort(number,0,n-1);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;

    printf("\n\n  Array has been sorted successfully using Quick Sort\n It took %f to sort \n\n ",cpu_time_used);

    display(number,n);
return 0;
}
