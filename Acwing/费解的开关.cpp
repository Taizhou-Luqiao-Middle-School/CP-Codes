//Author: CodeBoy
//TODO WA
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 6;
int dx[N] = {-1, 0, 1, 0, 0}, dy[N] = {0, 1, 0, -1, 0};
short a[N][N], g[N][N];
char tmp[N][N];
void toggle(int x, int y){
    for(int i=0;i<5;i++){
        if (x+dx[i] < 0 || x+dx[i] >= 5 || y+dy[i] < 0 || y+dy[i] >= 5) continue;
        g[x+dx[i]][y+dy[i]] ^= 1;
    }
}

int main(){
    int n;
    cin>>n;
    while(n--){
        for(int i=0;i<5;i++){
                cin>>tmp[i];
        }
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                g[i][j] = tmp[i][j] - '0';
            }
        }
        int ans = 100;
        for(int mo=0;mo<32;mo++){
            memcpy(a,g,sizeof g);
            int step = 0;
            for(int i=0;i<5;i++){
                if(mo>>i&1){
                    step++;
                    toggle(0,i);
                }
            }
            for(int i=0;i<4;i++){
                for(int j=0;j<5;j++){
                    if(g[i][j]==0){
                        step++;
                        toggle(i+1,j);
                    }
                }
            }
            bool flag = false;
            for (int j = 0; j < 5; j ++ )
                if (g[4][j] == '0')
                {
                    flag = true;
                    break;
                }

            if(!flag) ans = min(ans,step);
            memcpy(g,a,sizeof g);
        }
        if(ans>6) ans = -1;
        cout<<ans<<endl;
    }

    return 0;
}
