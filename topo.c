#include<stdio.h>
int a[10][10],vis[10],exp[10],n,i,j=0;
void dfs(int v)
{
    int i;
    vis[v]=1;
    for(i=1;i<=n;i++)
    {
        if(a[v][i]==1 && vis[i]==0)
            dfs(i);
    }
    exp[j++]=v;
}
void main()
{
    int i,k,m,p,q;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        for(k=1;k<=n;k++)
            a[i][k]=0;
    }
    printf("Enter number of edges:");
    scanf("%d",&m);
    for(i=1;i<=m;i++)
    {
        printf("Enter edge:");
        scanf("%d%d",&p,&q);
        a[p][q]=1;
    }
    for(i=1;i<=n;i++)
        vis[i]=0;
    for(i=1;i<=n;i++)
    {
        if(vis[i]==0)
            dfs(i);
    }
    printf("Topological Order:\n");
    for(i=1;i<n;i++)
        printf("%d ",exp[i]);
}
