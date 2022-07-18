#include "stdio.h"
int minGB(int a,int b,int GB)
{
    if(b!=0)
        return minGB(b,a%b,GB);
    else
        return GB/a;
}
int main()
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n",minGB(a,b,a*b));
}