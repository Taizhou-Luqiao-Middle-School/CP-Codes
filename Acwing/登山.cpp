#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1010;

int h[N],f[N][2];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        f[i][0] = f[i][1]  = 1; //f[i][0/1] 代表从左往右取到第 i 个数时的上升或下降状态的最大值
        for(int j=1;j<=i;j++){ // 第二维 0 代表上升状态 1 代表下降状态
            if(h[j]>h[i]) f[i][1] = max(f[i][1],max(f[j][1],f[j][0])+1);
            if(h[j]<h[i]) f[i][0] = max(f[i][0], f[j][0]+1);
        }
    }
    int res = 0;
    for(int i=1;i<=n;i++){ //因为取不同的 i 会影响结果, 所以要遍历一遍求最大值
        res= max(res,max(f[i][1],f[i][0])); //状态合并
        // cout<<f[i][1]<<" "<<f[i][0]<<endl;
    }
    cout<<res<<endl;
    return 0;
}
