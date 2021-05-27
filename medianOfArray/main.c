

#include <stdio.h>
#include<stdlib.h>
#define max(x, y) (((x) > (y)) ? (x) : (y))
#define min(x, y) (((x) < (y)) ? (x) : (y))
int n;


// A divide and conquer based efficient solution to find median
// of two sorted arrays of same size.

 
int median(int [], int); 
 

int getMedian(int ar1[], int ar2[], int n)
{
    /* return -1  for invalid input */
    if (n <= 0)
        return -1;
    if (n == 1)
        return (ar1[0] + ar2[0])/2;
    if (n == 2)
        return (max(ar1[0], ar2[0]) + min(ar1[1], ar2[1])) / 2;
 
    int m1 = median(ar1, n); /* get the median of the first array */
    int m2 = median(ar2, n); /* get the median of the second array */
 
    /* If medians are equal then return either m1 or m2 */
    if (m1 == m2)
        return m1;
 
    /* if m1 < m2 then median must exist in ar1[m1....] and
        ar2[....m2] */
    if (m1 < m2)
    {
        if (n % 2 == 0)
            return getMedian(ar1 + n/2 - 1, ar2, n - n/2 +1);
        return getMedian(ar1 + n/2, ar2, n - n/2);
    }
 
    /* if m1 > m2 then median must exist in ar1[....m1] and
        ar2[m2...] */
    if (n % 2 == 0)
        return getMedian(ar2 + n/2 - 1, ar1, n - n/2 + 1);
    return getMedian(ar2 + n/2, ar1, n - n/2);
}
 
/* Function to get median of a sorted array */
int median(int arr[], int n)
{
    if (n%2 == 0)
        return (arr[n/2] + arr[n/2-1])/2;
    else
        return arr[n/2];
}

int main()
{   printf("\n Enter the size of arrays:> ");
    scanf("%d",&n);
    int ar1[n],ar2[n];
    printf("\n Enter data in first array :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar1[i]);
    }
      printf("\n\n Enter data in  Second array :\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&ar2[i]);
    }

        printf("\n \n Array 1: ");
            for(int i=0;i<n;i++)
                {
                    printf(" %d ",ar1[i]);
                }
        printf("\n Array 2: ");
            for(int i=0;i<n;i++)
                {
                    printf(" %d ",ar2[i]);
                }
		printf("\n Median is %d", getMedian(ar1, ar2, n));
	
	getchar();
	return 0;
}

