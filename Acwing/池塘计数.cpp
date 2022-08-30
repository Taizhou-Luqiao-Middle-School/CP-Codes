//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 1005;
int dx[10] = {-1,-1,-1,0,0,1,1,1};
int dy[10] = {-1,0,1,1,-1,0,-1,1};
int n,m;

int a[N][N],st[N][N],cnt;

void dfs(int x,int y){
    a[x][y] = 0;
    for(int i=0;i<8;i++){
        int x2 = x+dx[i], y2 = y+dy[i];
        if(x2>=0&&y2>=0&&x2<n&&y2<m&&a[x2][y2]==1){
            dfs(x2,y2);
        }
    }
}
int main(){
    cin>>n>>m;
    // INPUT
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            char t;
            cin>>t;
            if(t == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(a[i][j]==1){//找到“ W ”.
                dfs(i,j);
                cnt++;//统计答案
    }
    cout<<cnt<<endl;
    return 0;
}