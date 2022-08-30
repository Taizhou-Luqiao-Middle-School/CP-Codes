#include <stdio.h>
int main()
{
    long long int n,s=0;
    scanf("%lld",&n);
    while(n)
    {
        s+=n%10;n/=10;
    }
    printf("%lld",s);
}