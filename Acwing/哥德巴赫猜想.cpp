//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e6+5;
int st[N],primes[N],cnt;
void primes_seive(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]*i < n;j++){
            st[primes[j]*i] = 1;
            if(i%primes[j] == 0) break;
        }
    }
}
int main(){
    int n;
    primes_seive(N-1);
    while(cin>>n,n){
        for(int i=1;;i++){
            int p = primes[i];
            int b = n-p;
            if(!st[b]){
                printf("%d = %d + %d\n",n,p,b);
                break;
            }
        }
    }
    return 0;
}