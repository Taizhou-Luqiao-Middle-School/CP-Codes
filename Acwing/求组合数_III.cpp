//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
int qpow(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1) res = (LL)res * a % p;
        a = (LL)a * a % p;
        k >>= 1;
    }
    return res;
}
LL C(LL a, LL b, int p)
{
    if(b > a) return 0;
    if(b > a - b) b = a - b;
    LL x = 1, y = 1;
    for(int i = 0; i < b; i++)
    {
        x = x * (a - i) % p;
        y = y * (i + 1) % p;
    }
    return x * qpow(y, p - 2, p) % p;
}
// int lucas(LL a,LL b,int p){
//     if(a<p && b<p) return C(a,b,p);
//     return (LL)C(a%p,b%p,p) * C(a/p,b/p,p) % p;
// }
int lucas(LL a, LL b, int p)
{
    if (a < p && b < p) return C(a, b, p);
    return (LL)C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
int main(){
    int n;
    cin >> n;

    while (n -- )
    {
        LL a, b;
        int p;
        cin >> a >> b >> p;
        cout << lucas(a+b, b, p) << endl;
    }
    return 0;
}