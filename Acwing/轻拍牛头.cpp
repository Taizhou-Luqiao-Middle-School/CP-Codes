#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int N = 1e6 + 10, M = 1e5 + 10;
int a[M],cnt[N],ans[N];
int main(){
    int n;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        cnt[a[i]]++;
    }

    for(int i=1;i<=N;i++){
        if(cnt[i]==0) continue;
        for(int j=i;j<=N;j+=i){
            ans[j] += cnt[i];
        }
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[a[i]]-1);
    }
    return 0;
}