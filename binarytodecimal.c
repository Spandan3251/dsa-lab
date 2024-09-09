#include<stdio.h>
int binaryTodecimal(int binary)
{
    if(binary==0)
    return 0;
    else
    return(binary%10)+2*binaryTodecimal(binary/10);
}
int main()
{
    int n,z;
    printf("\n enter a no");
    scanf("%d",&n);
    z=binaryTodecimal(n);
    printf("\n decimal=%d",z);
}
