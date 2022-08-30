//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

typedef long long LL;

int main(){
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        int a,b,p;
        scanf("%d%d%d",&a,&b,&p);
        LL res=1%p; // avoid WA at "p = 1"
        while(b){
            if(b&1){
                res = (LL)res * a %p;
            }
            a = a * (LL)a %p;
            b>>=1;
        }
        printf("%lld\n",res);
    }
    return 0;
}