#include<stdio.h>
#define size 10
int mergesort(int *A,int lb,int ub)
{
    if(lb<ub)
    {
        int mid=(lb+ub)/2;
        mergesort(A,lb,mid);
        mergesort(A,mid+1,ub);
        merge(A,lb,mid,ub);
    }
}
int merge(int *a,int lb,int mid,int ub)
{
    int i,j,k,b[50];
    i=lb;
    j=mid+1;
    k=lb;
    while(i<=mid && j<=ub)
    {
        if(a[i]<=a[j]){
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }
    if (i>mid)
    while(j<=ub)
    {
        b[k]=a[j];
        j++;
        k++;
    }
    else
    {
        while(i<=mid){
            b[k]=a[i];
            i++;
            k++;
        }
    }
    k=lb;
    while(k<=ub)
    {
        a[k]=b[k];
        k++;
    }
}
main()
{
    int x[50],n,i,z;
    printf("\n how many nos");
    scanf("%d",&n);
    printf("\n enter nos");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    mergesort(x,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%5d",x[i]);
    }
}
