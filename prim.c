#include<stdio.h>
#include<conio.h>
int vis[10],vt[10],et[10][2],e=0,n;
float cost[10][10],sum=0;
void prims()
{
    int x=1,min,i,j,m,k,u,v;
    vt[x]=1;
    vis[x]=1;
    for(i=1;i<n;i++)
    {

        j=x;
        min=999;
        while(j>0)
        {
            k=vt[j];
            for(m=2;m<=n;m++)
            {
                if(cost[k][m]<min && vis[m]==0)
                {
                    min=cost[k][m];
                    u=k;
                    v=m;
                }
            }
            j--;
        }
        vt[++x]=v;
        et[i][1]=u;
        et[i][2]=v;
        e++;
        vis[v]=1;
        sum=sum+cost[u][v];
    }
}
void main()
{
    int i,j;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the cost matrix:\n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%f",&cost[i][j]);
        }
    }
    prims();
    for(i=1;i<=e;i++)
    {
        printf("%d-->%d\n",et[i][1],et[i][2]);
    }
    printf("Total cost=%f",sum);
}
