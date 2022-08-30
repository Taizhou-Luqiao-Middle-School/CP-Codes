//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Re register
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;
typedef long long ll;
const int N = 105, M = 25005;
int a[N];
bool d[M];
int main(){
    int T;
    scanf("%d", &T);
    while(T--){
        memset(d, 0 ,sizeof d);
        int n;
        scanf("%d", &n);
        for(int i=0;i<n;i++){
            scanf("%d", &a[i]);
        }
        sort(a, a+n); //从小到大排序
        int ans = 0;
        int mx = a[n-1];
        d[0] = true;
        for(int i=0;i<n;i++){
            if(!d[a[i]]) ans ++;
            for(int k=a[i];k<=mx;k++){
                d[k] = d[k - a[i]] | d[k];
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}