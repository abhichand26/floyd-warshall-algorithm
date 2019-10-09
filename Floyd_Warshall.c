#include <stdio.h>
#define inf 9999

/*
** Program to find all-pairs shortest path using Floyd-Warshall algorithm
** Made by - Abhishek Chand
*/

void printMatrix(int n, int A[][n+1])
{
	int i,j;
	for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if(A[i][j]==9999)
				printf("inf\t", A[i][j]);
			else
				printf("%d\t", A[i][j]);
        }
        printf("\n");
    }
}

void printpath(int n, int P[][n+1], int i, int j)
{
	if(P[i][j]==-1)
	{
		printf(" %d",j);
		return;
	}
	printpath(n,P,i,P[i][j]);
	printf("-->%d",j);
}

void floydWarshall (int n, int W[][n+1], int P[][n+1]) {
	int i, j, k;
	for (k = 1;k <= n;k++)
    {
        for (i = 1;i <= n;i++)
        {
            for (j = 1;j <= n;j++)
            {
                if (W[i][k] != inf && W[k][j] != inf && W[i][k] + W[k][j] < W[i][j])
                {
                    W[i][j] = W[i][k] + W[k][j];
                    P[i][j] = P[k][j];
                }
                
            }
        }
        printf("\n Distance matrix \n" );
 		printMatrix(n,W);
    	printf("\n Predecessor matrix \n" );
    	printMatrix(n,P);
    }
    
    for(i=1;i<=n;i++)
    {
    	for(j=1;j<=n;j++)
    	{
    		if(i!=j)
			{
				printf("\nPath from %d to %d:",i,j);
				printpath(n,P,i,j);
			}
		}
	}
	
}

int main()
{
	int i,e,j,k,w,n;
	printf("Enter the number of vertices:");
	scanf("%d",&n);
	printf("\nEnter the number of edges:");
	scanf("%d",&e);
    int b[n+1][n+1],p[n+1][n+1];
    for (i = 1; i <= n; i++)
    {
    	for (j = 1; j <= n; j++)
    	{
    		if(i==j)
    			b[i][j] = 0;
    		else
				b[i][j] = inf;
    		
    		p[i][j] = -1;
		}
	}
	for (i = 0; i < e; i++)
    {
        printf("Enter Edge and Weight (u v w): ");
        scanf("%d %d %d",&j, &k, &w);
        b[j][k]=w;
        p[j][k]=j;
    }

   	floydWarshall (n, b, p);
    return 0;
}
