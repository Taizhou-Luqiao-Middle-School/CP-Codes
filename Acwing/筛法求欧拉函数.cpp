// Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 1000010;

int primes[N], cnt;
int phi[N];
bool st[N];

LL get_eulers(int n)
{
    phi[1]  = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i]){
            primes[cnt++] = i;
            phi[i] = i-1;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0){
                phi[i*primes[j]] = primes[j] * phi[i];
                break;
            }
            phi[i*primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
    LL res = 0;
    for(int i=1;i<=n;i++){
        res += phi[i];
    }
    return res;
}

int main(){
    int n;
    cin>>n;
    cout<<get_eulers(n)<<endl;
    return 0;
}
