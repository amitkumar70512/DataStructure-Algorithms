#include<stdio.h>
#include<time.h>
#include<stdlib.h>
//time complexity of merge sort:O(nlogn)

clock_t start,end;
double cpu_time_used;

void merge(int arr[],int l,int m,int u){
int n1=m-l+1;
int n2=u-m;
 int L[n1],M[n2];
 for(int i=0;i<n1;i++)
    L[i]=arr[l+i];
 for(int j=0;j<n2;j++)
    M[j]=arr[m+1+j];

 int i=0,j=0,k=l;

     while(i<n1&&j<n2)
     {

         if(L[i]<=M[j]){
            arr[k]=L[i];
            i++;
         }
         else {
            arr[k]=M[j];
            j++;
         }
         k++;
     }
     while(i<n1){
        arr[k]=L[i];
        i++;
        k++;
     }
      while(j<n2){
        arr[k]=M[j];
        j++;
        k++;
      }
}


void MergeSort(int arr[],int l,int u)
{
    int mid;

     if(l<u){
        mid=(l+u)/2;
      MergeSort(arr,l,mid);
      MergeSort(arr,mid+1,u);
      merge(arr,l,mid,u);
     }

}
void display(int *arr, int n)
{
    for(int j=0;j<n;j++)
        printf(" %d ",arr[j]);

}
int main()
{
    int n,n1;
    printf("Enter the size of an array:\n  ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter the elements of array: \n");
    for(int i=0;i<n;i++){
        scanf("  %d",&arr[i]);

    }
    printf("Sorting");
    start = clock();
    MergeSort(arr,0,n-1);
    end=clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Array has been sorted successfully taking %f\n",cpu_time_used);
    display(arr,n);

}
