//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
int a[205], n, x;
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int flag = 0;
        scanf("%d%d", &n, &x);
        
        for(int i=0;i<n*2;i++){
            scanf("%d", &a[i]);
        }
        sort(a, a+2*n);
        for(int i=0;i<n;i++){
            if(a[i]+x > a[i+n]){
                flag = 1;
            }
        }
        if(flag == 1) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}