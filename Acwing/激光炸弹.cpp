//Author: CodeBoy

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 5005;
int a[N][N];
int main(){
    int n,r;
    scanf("%d%d",&n,&r);
    if(r>5001) r= 5001;
    for(int i=0;i<n;i++){
        int x,y,w;
        scanf("%d%d%d",&x,&y,&w);
        x++,y++;
        a[x][y] += w;
    }
    for(int i=1;i<=5001;i++){
        for(int j=1;j<=5001;j++){
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
        }
    }
    int res = 0;
    for(int i=r;i<=5001;i++){
        for(int j=r;j<=5001;j++){
            res = max(res, a[i][j]-a[i-r][j]-a[i][j-r]+ a[i-r][j-r]);
        }
    }
    printf("%d\n",res);
    return 0;
}