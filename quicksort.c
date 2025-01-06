#include<stdio.h>
#include<string.h>
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[20],int low,int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i] <=pivot && i<high)
        {
            i++;
        }

        while(arr[j] >pivot && j>low)
        {
            j--;
        }
        if(i<j){
        swap(&arr[i],&arr[j]);
    }
    }
    swap(&arr[low],&arr[j]);
    return j;
}
void qsort(int arr[20],int low,int high)
{
    int pos;
    if(low<high)
    {
         pos=partition(arr,low,high);
        qsort(arr,low,pos-1);
        qsort(arr,pos+1,high);
    }
}
int main()
{
    int x[20],i,n;
    printf("\n how many nos");
    scanf("%d",&n);
    printf("\n enter nos");
    for(i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    qsort(x,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%5d",x[i]);
    }
    return 0;
} 