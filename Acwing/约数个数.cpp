//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
long long p = 1e9+7;
unordered_map<int,int> m;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        for(int j=2;j<=a/j;j++){
            if(a%j==0){
                while(a%j==0){
                    a/=j;
                    m[j]++;
                }
            }
        }
        if(a>1) m[a]++;
    }
    long long res = 1;
    for(auto t:m){
        res = res * (t.second+1) % p; //不能写成 res *= ..., 会溢出
    }
    cout<<res<<endl;
    return 0;
}