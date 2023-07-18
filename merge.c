#include<stdio.h>
#include <time.h>
clock_t start, end;
void merge(int a[],int low,int mid,int high)
{
    int i,j,k,c[100];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid&&j<=high)
    {
        if(a[i]<a[j])
            c[k++]=a[i++];
        else
            c[k++]=a[j++];
    }
    while(i<=mid)
        c[k++]=a[i++];
    while(j<=high)
        c[k++]=a[j++];
    for(i=0;i<=high;i++)
        a[i]=c[i];
}
void mergesort(int a[],int low, int high)
{
    int mid;
    if(low<high)
    {
        mid=(low+high)/2;
        mergesort(a,low,mid);
        mergesort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}
void main()
{
    int n,i;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]);
    start=clock();
    mergesort(a,0,n-1);
    end=clock();
    double t=((double)end-start)/CLOCKS_PER_SEC;
    printf("After sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nTime Taken: %lf",t);
}
