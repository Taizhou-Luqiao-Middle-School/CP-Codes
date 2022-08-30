//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100005;

int count(int x){
    int res = 0;
    while(x){
        if(x&1) res++;
        x>>=1;
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        int x;
        scanf("%d",&x);
        printf("%d ",count(x));
    }
    return 0;
}