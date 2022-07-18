#include <iostream>
#include <queue>
using namespace std;
const int N = 105;
int R, C;
int a[N][N], f[N][N];
int dx[] = {0,0,-1,1};
int dy[] = {1,-1,0,0};
int mem[N][N];
bool check(int x, int y, int xx, int yy){
    if(xx>0&&yy>0&&xx<=R&&yy<=C&&a[x][y]>a[xx][yy]){
        return true;
    }
    return false;
}

int dfs(int x,int y){
    if(mem[x][y])return mem[x][y];
    mem[x][y]=1;
    for(int i=0;i<4;i++)
    {  int xx=dx[i]+x;
       int yy=dy[i]+y;
       if(check(x, y, xx, yy)){
       	  dfs(xx, yy);
          mem[x][y]=max(mem[x][y],mem[xx][yy]+1);
       }
    }
    return mem[x][y];
}

int main(){
    int R, C;
    cin>>R>>C;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            cin>>a[i][j];
        }
    }
    int ans = -1;
    for(int i=1;i<=R;i++){
        for(int j=1;j<=C;j++){
            ans = max(ans, dfs(i, j));
        }
    }

    cout<<ans<<endl;
    return 0;
}