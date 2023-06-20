#include <stdio.h>
int vis[10],a[10][10],n;
void dfs(int);

void main()
{
    int i,j;
    printf("Enter the number of vertices:");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix:");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            scanf("%d",&a[i][j]);
    }

    printf("\nDFS traversal:");

    for(int i=1;i<=n;i++)
    {
        if(vis[i] == 0)
            dfs(i);
    }
}

void dfs(int v)
{
    int i;
    vis[v] = 1;
    printf("%d ",v);
    for(int i=1;i<=n;i++)
    {
        if(a[v][i]==1 && vis[i]==0)
            dfs(i);
    }
}
