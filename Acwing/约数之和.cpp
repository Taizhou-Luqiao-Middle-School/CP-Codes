//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unordered_map>
using namespace std;
int a[105];
typedef long long LL;
LL mod = 1e9+7;
unordered_map<int,int> m;
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int tmp;
        cin>>tmp;
        // cout<<tmp<<endl;
        for(int j=2;j<=tmp/j;j++){
            while(tmp%j==0){
                tmp/=j;
                m[j]++;
                // cout<<tmp<

                <' '<<j<<endl;
            }
        }
        // 显然，如果剩下的tmp不是质数，那么tmp/j就一定大于现有tmp的最小质因子，也就会在上面的循环中被筛掉了。
        if(tmp>1) m[tmp] ++; //这行要在循环外，去除了所有小于根号的约数之后再执行
            // cout<<tmp<<' '<<j<<' '<<m[j]<<endl;

    }
    LL res = 1;
    for(auto p:m){
        LL a= p.first,b = p.second;
        LL t=1;
        while(b--){
            t=(t*a+1) % mod;
        }
        res = res * t % mod;
    }

    cout<<res<<endl;
    return 0;
}