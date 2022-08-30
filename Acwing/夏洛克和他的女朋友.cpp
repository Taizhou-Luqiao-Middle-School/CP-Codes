//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
int st[N],primes[N],cnt;

void primeseive(int n){
    for(int i=2;i<=n;i++){
        if(!st[i]) primes[cnt++] = i;
        for(int j=0;primes[j]*i<=n;j++){
            st[primes[j]*i] = 1;
            if(i%primes[j] == 0) break;
        }
    }
}

int main(){
    int n;
    cin>>n;
    primeseive(n+1);
    if(n<=2){
        printf("1\n");
    } else {
        printf("2\n");
    }
    for(int i=2;i<=n+1;i++){
        if(!st[i]){
            printf("1 ");
        } else {
            printf("2 ");
        }
    }
    return 0;
}