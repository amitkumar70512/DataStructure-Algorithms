/* C Program to find whether a Directed Graph is Cyclic or not */

#include<stdio.h>
#include<stdlib.h>

#define MAX 100

#define initial 1
#define visited 2
#define finished 3

int n;    /*Number of vertices in the graph */
int adj[MAX][MAX];
void create_graph( );

int state[MAX];



void DFS(int v)
{
        int i;
        state[v] = visited;

        for(i=0; i<n; i++)
        {
                if(adj[v][i]==1)
                {
                        if(state[i]==initial)
                                DFS(i);
                        else if(state[i]==visited)
                        {
                                printf("\nBack edge  (%d,%d) found\n", v, i);
                                printf("\nGraph is cyclic\n");
                                exit(1);
                        }
                }
        }
        state[v] = finished;
}/*End of DFS()*/

void DF_Traversal()
{
        int v;

        for(v=0; v<n; v++)
                state[v] = initial;

        DFS(0);/*start DFS from vertex 0*/

        for(v=0; v<n; v++)
        {
                if(state[v]==initial)
                        DFS(v);
        }
        printf("\nGraph is Acyclic\n");
}/*End of DF_Traversal( )*/



void create_graph()
{
    printf("\n Enter the Number of vertices:> ");
    scanf("%d",&n);
    printf("\n Enter the Adjacency matrix..\n");
 
     for(int i=0;i<n;i++)
     {
	     
         printf("\n %d Row \n",i+1);
         for(int j=0;j<n;j++)
         {
           scanf("%d",&adj[i][j]);
           
         }
     }
    
}




int main()
{
        create_graph();
        DF_Traversal();
        return 0;
}