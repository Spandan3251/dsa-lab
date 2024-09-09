#include<stdio.h>
int factorial(int n)
{
    if(n==0||n==1)
    return 1;
    else
    return n*factorial(n-1);
}
main()
{
    int n,y;
    printf("\n enter no");
    scanf("%d",&n);
    y=factorial(n);
    printf("\n factorial=%d",y);
