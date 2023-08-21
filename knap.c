#include <stdio.h>
 
int max(int a, int b) { 
    return (a > b) ? a : b; 
}

int knapSack(int W, int wt[], int val[], int n)
{
    int i, j;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (j = 0; j <= W; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (wt[i - 1] <= j)
                K[i][j] = max(val[i - 1]
                                  + K[i - 1][j - wt[i - 1]],
                              K[i - 1][j]);
            else //wt > j
                K[i][j] = K[i - 1][j];
        }
    }
 
    return K[n][W];
}
 
// Driver Code
int main()
{
    int profit[25], weight[25], n, W, i, final;
    printf("Enter number of objects (25):\n");
    scanf("%d", &n);
    for(i = 0; i<n; i++){
        printf("Enter profit and weight of Object %d:\n", i+1);
        scanf("%d %d", &profit[i], &weight[i]);
    }
    printf("Enter the max weight:\n");
    scanf("%d", &W);
    final = knapSack(W, weight, profit, n);
    printf("%d", final);
    return 0;
}
