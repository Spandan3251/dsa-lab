#include<stdio.h>
void qsort(int x[20],int low,int high);
int position(int x[20],int low,int high);
main()
{
    int i,a[20],n;
    printf("\n how many nos");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("\n a[%d]=",i);
        scanf("%d",&a[i]);
    }
    qsort(a,0,n-1);
    printf("\n");
    for(i=0;i<n;i++)
    {
        printf("%5d",a[i]);
    }
}
void qsort(int x[20],int low,int high)
{
    int pos;
    if(low<high)
    {
        pos=position(x,low,high);
        qsort(x,low,pos-1);
        qsort(x,pos+1,high);
    }
}
int position(int x[20],int low,int high)
{
    int i,j,flag=1,t;
    int pos=low;
    while(flag==1)
    {
        for(i=high;i>pos;i--)
        {
            flag=0;
            if(x[pos]>x[i])
            {
                t=x[pos];
                x[pos]=x[i];
                x[i]=t;
                pos=i;
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            for(i=low;i<pos;i++)
            {
                flag=0;
                if(x[pos]<x[i])
                {
                    t=x[pos];
                    x[pos]=x[i];
                    x[i]=t;
                    pos=i;
                    flag=1;
                    break;
                }
            }
        }
    }
    return(pos);
}