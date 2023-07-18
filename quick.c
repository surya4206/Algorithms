#include<stdio.h>
#include <time.h>
clock_t start, end;
int parti(int a[],int low,int high)
{
    int i,j,temp,pivot;
    pivot=low;
    i=low+1;
    j=high;
    while(i<=j)
    {
        while(a[i]<a[pivot])
            i++;
        while(a[j]>a[pivot])
            j--;
        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[low];
    a[low]=a[j];
    a[j]=temp;
    return j;
}
void qsort(int a[],int low,int high)
{
    int mid;
    if(low<high)
    {
        mid=parti(a,low,high);
        qsort(a,low,mid-1);
        qsort(a,mid+1,high);
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
    qsort(a,0,n-1);
    end=clock();
    double t=((double)end-start)/CLOCKS_PER_SEC;
    printf("After sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\nTime Taken: %lf",t);
}
