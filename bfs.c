#include<stdio.h>
int a[30][30],vis[10],n;
void bfs(int);
void main()
{
    int i,j,m,p,q,start;
    printf("Enter number of vertices:");
    scanf("%d",&n);
    printf("Enter number of edges:");
    scanf("%d",&m);
    for(i=0;i<=n;i++)
    {
        for(j=1;j<=n;j++){
            a[i][j]=0;
        }
    }
    for(i=1; i<=m; i++){
        printf("Enter edge:");
        scanf("%d%d",&p,&q);
        a[p][q]=1;
    }
    for(i=1;i<=m;i++){
        vis[i]=0;
    }
    printf("Enter the starting vertex:");
    scanf("%d",&start);
    printf("Nodes reachable from starting vertex:\n");
    bfs(start);
}

void bfs(int v)
{
    int i, q[30],f=0,r=0,u;
    vis[v]=1;
    q[r]=v;
    while(f<=r){
        u=q[f];
        printf("%d ",u);
        for(i=1;i<=n;i++){
            if(a[u][i]==1&& vis[i]==0){
                r=r+1;
                q[r]=i;
                vis[i]=1;
            }
        }
f=f+1;
}
}
