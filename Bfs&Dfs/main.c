#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int i,j,n;
int f=0,r=-1;
int arr[10][10],visited[10],q[10],reach[20];
void checkAdjacency();

void input()
{
	
    printf("\n Enter the Adjacency matrix..\n");
 
     for(i=0;i<n;i++)
     {
	     reach[i]=0;
         printf("\n %d Row \n",i+1);
         for(j=0;j<n;j++)
         {
           scanf("%d",&arr[i][j]);
           
         }
     }
    checkAdjacency(); 
}
void checkAdjacency(){
 
    for(i=0;i<n;i++)
    {
     if(arr[i][i]==1)
     {
      
       printf("\nInvalid Adjacency matrix!!! \n Insert values again..\n");
       input();
     }
    }
}

void bfs(int v) {
    	for (i=0;i<n;i++)
    	{
    	  if(arr[v][i]==1 && visited[i]==0)//not visited,add it to queue
    	   q[++r]=i;
    	}
    while(f<=r)
    {
		visited[q[f]]=1;//make front element visited
		f++;//pop front element
		bfs(q[f]); 
	}
}

void dfs(int v)
{
int i;
reach[v]=1;
for(i=1;i<=n;i++)
if(arr[v][i] && !reach[i])
{
printf("\n %d-->%d",v,i);
dfs(i);
}
}

int main()
{
    int v;
    char choice;
	printf("Enter the number of vertices:\t");
	scanf("%d",&n);
     input();
   while(1)
   {
  
    printf("\n\n Enter the option \n a. Print all the nodes reachable from a given starting node in a digraph using BFS method \n b. Check whether a given graph is connected or not using DFS method.\n :>");
    scanf("%s",&choice);
    if(choice=='a')
    {
		 
        printf("\n Enter the starting vertex:");
    	scanf("%d",&v);
    	q[++r]=v;
    	bfs(v);
    	
        printf("\n The node which are reachable are:\n ");
    	for (i=0;i<n;i++)
    	{
    	   if(visited[i])
    	   printf("v%d\t",i);
    	   else
    	   printf("\n Bfs is not possible");
    	}
    }
    else if(choice=='b')
    {
			
        dfs(0);
	    int count=0;
		printf("\n");
		for(i=0;i<n;i++)
		{
			if(reach[i])
			count++;
		}
		if(count==n)
		printf("\n Graph is connected");
		else
		printf("\n Graph is not connected!!");   
    }
	
    else 
		{	
		printf("\n Alert !! Invalid option.. Retry  .\n");
		exit(0);
		}
	

  }  
}

