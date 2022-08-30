//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 100010;

int row[N], col[N], s[N], c[N];

LL work(int n, int a[]){
    for(int i=1;i<=n;i++){
        s[i] = s[i-1] + a[i];
    }
    if(s[n] % n) return -1;

    int avg = s[n] / n;
    c[1] = 0;
    for(int i=2;i<=n;i++){
        c[i] = s[i-1] - (i-1) * avg;
    }
    
    sort(c+1,c+n+1);
    LL res = 0;
    for(int i=1;i<=n;i++){
        res += abs(abs(c[i] - c[(n+1)/2]));
    }

    return res;
}
int main(){
    int n,m,cnt;
    scanf("%d%d%d",&n,&m,&cnt);
    while(cnt--){
        int x,y;
        scanf("%d%d",&x,&y);
        row[x]++, col[y]++;
    }
    LL r = work(n, row);
    LL c = work(m, col);

    if(r!=-1&&c!=-1) printf("both %lld\n", r+c);
    else if(r!=-1) printf("row %lld\n", r);
    else if(c!=-1) printf("column %lld\n", c);
    else printf("impossible");

    return 0;
}