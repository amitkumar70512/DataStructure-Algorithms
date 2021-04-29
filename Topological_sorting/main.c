#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int a[10][10],n,indegre[10];

void find_indegre()
{ int j,i,sum;
for(j=0;j<n;j++)
{
sum=0;
for(i=0;i<n;i++)
sum+=a[i][j];
indegre[j]=sum;
}
}

int check()
{
    int i,j,valid=0;
    for(i=0;i<n;i++)
    {

            if(a[i][i]==1)
               return -1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if((a[i][j]==a[j][i])&&(a[i][j]==1))
            {
            printf("%d--- %d",a[i][j],a[j][i]);
            printf("\n Alert !! cyclic graph not allowed..");
                return -1;
            }
        }
    }
        return 1;

}


void topology()
    {
    int col,u,v,t[10],s[10],top=-1,k=0;
    find_indegre();
        for(col=0;col<n;col++)
        {
        if(indegre[col]==0) s[++top]=col;
        }
        while(top!=-1)
        {
            u=s[top--];
            t[k++]=u;
            for(v=0;v<n;v++)
                {
                if(a[u][v]==1)
                    {
                    indegre[v]--;
                    if(indegre[v]==0) s[++top]=v;
                    }
                }
        }
    printf("The topological Sequence is:\n");
    int i;
        for(i=0;i<n;i++)
        printf("%d ",t[i]);
    }


void main()
{
int i,j;

printf("Enter number of vertices:");
scanf("%d",&n);
printf("\nEnter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
    printf("\n %d row \n",i+1);
        for(j=0;j<n;j++)
        scanf("%d",&a[i][j]);
    }
    int valid;
    valid=check();
    if(valid==1){
       topology();
    }
    else{ printf("\n !! Not valid matrix..");}


getch();
}
