
// Johnson and Trotter algorithm.
#include<stdio.h>
#include<conio.h>
#include<stdbool.h>

bool LEFT_TO_RIGHT = true;
bool RIGHT_TO_LEFT = false;

int p,q;
// Utility functions for finding the
// position of largest mobile integer in a[].
int searchArr(int a[], int n, int mobile)
{
	for (int i = 0; i < n; i++)
		if (a[i] == mobile)
		return i + 1;
}

// To carry out step 1 of the algorithm i.e.
// to find the largest mobile integer.
int getMobile(int a[], bool dir[], int n)
{
	int mobile_prev = 0, mobile = 0;
	for (int i = 0; i < n; i++)
	{
		// direction 0 represents RIGHT TO LEFT.
		if (dir[a[i]-1] == RIGHT_TO_LEFT && i!=0)
		{
			if (a[i] > a[i-1] && a[i] > mobile_prev)
			{
				mobile = a[i];
				mobile_prev = mobile;
			}
		}

		// direction 1 represents LEFT TO RIGHT.
		if (dir[a[i]-1] == LEFT_TO_RIGHT && i!=n-1)
		{
			if (a[i] > a[i+1] && a[i] > mobile_prev)
			{
				mobile = a[i];
				mobile_prev = mobile;
			}
		}
	}

	if (mobile == 0 && mobile_prev == 0)
		return 0;
	else
		return mobile;
}

// Prints a single permutation
int printOnePerm(int a[], bool dir[], int n)
{
	int mobile = getMobile(a, dir, n);
	int pos = searchArr(a, n, mobile);

	// swap the elements acc to direction

	if (dir[a[pos - 1] - 1] == RIGHT_TO_LEFT)
	{                       //swap(a[pos-1], a[pos-2]);
	    int temp=a[pos-1];
	    a[pos-1]=a[pos-2];
	    a[pos-2]=temp;
	}


	else if (dir[a[pos - 1] - 1] == LEFT_TO_RIGHT)
	{                       //	swap(a[pos], a[pos-1]);

	    int temp=a[pos];
	    a[pos]=a[pos-1];
	    a[pos-1]=temp;
	}

	// changing  dir for elements >largest mobile integer.

	for (int i = 0; i < n; i++)
	{
		if (a[i] > mobile)
		{
			if (dir[a[i] - 1] == LEFT_TO_RIGHT)
				dir[a[i] - 1] = RIGHT_TO_LEFT;
			else if (dir[a[i] - 1] == RIGHT_TO_LEFT)
				dir[a[i] - 1] = LEFT_TO_RIGHT;
		}
	}
   printf("\t");
	for (int i = 0; i < n; i++)
		printf("%d",a[i]);
printf("   -->  %d\n",mobile);
}


int fact(int n)
{
	int res = 1;
	for (int i = 1; i <= n; i++)
		res = res * i;
	return res;
}


void printPermutation(int n)
{

	int a[n];
	bool dir[n];

	// storing the elements from 1 to n and
	// printing first permutation
	printf("\t");
	for (int i = 0; i < n; i++)
	{
		a[i] = i + 1;
		printf("%d",a[i]);
	}
   printf("   -->  %d\n",n);

	// initially all directions are set
	// to  0.
	for (int i = 0; i < n; i++)
		dir[i] = RIGHT_TO_LEFT;

	// for generating permutations in the order.
	for (int i = 1; i < fact(n); i++)
		printOnePerm(a, dir, n);
}


int main()
{
	int n;
    printf("Enter the number of integers:>\t");
	scanf("%d",&n);
	printf("\n permutations --> mobile no.\n");
	printPermutation(n);
	return 0;
}
