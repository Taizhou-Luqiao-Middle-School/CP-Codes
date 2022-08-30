//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
unsigned long long s;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        int t, flag = 0;
        s = 0;
        for(int i=0;i<n;i++){
            scanf("%d", &t);
            if(i==n-1) break;
            if(flag&&t==0) s ++;
            if(flag&&t!=0) s += t;
            if(t!=0&&!flag){
                flag = 1;
                s += t;
            }
        }
        cout<<s<<endl;
    }
    return 0;
}