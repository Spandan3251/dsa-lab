#include<stdio.h>
void merge(int arr[20],int low,int mid,int high)
{
    int temp[20],k=0;
    int left=low;
    int right=mid+1;
    while(left<=mid && right<=high)
    {
        if(arr[left]<=arr[right])
        {
            temp[k]=arr[left];
            left++;
        }
        else
        {
            temp[k]=arr[right];
            right++;
        }
        k++;
    }
    
    while(left<=mid)
    {
        temp[k]=arr[left];
        left++;
        k++;
    }

    while(right<=high)
    {
        temp[k]=arr[right];
        right++;
        k++;
    }

    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[i-low];
    }
}
void ms(int arr[20],int low,int high)
{
    if(low==high)
        return;
    int mid=(low+high)/2;
    ms(arr,low,mid);
    ms(arr,mid+1,high);
    merge(arr,low,mid,high);
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
    ms(x,0,n-1);
    for(i=0;i<n;i++)
    {
        printf("%5d",x[i]);
    }
    return 0;
}