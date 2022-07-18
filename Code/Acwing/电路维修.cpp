#include <iostream>
#include <cstring>
#include <algorithm>
#include <deque>

#define x first
#define y second
using namespace std;
typedef pair<int,int> PII;
char g[505][505];
int dist[505][505];
bool st[505][505];
int R, C;

int bfs(){
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    dist[0][0] = 0;
    deque<PII> q;
    q.push_back({0, 0});

    char cs[] = "\\/\\/";
    int dx[4] = {-1, -1, 1, 1}, dy[4] = {-1, 1, 1, -1};
    int ix[4] = {-1, -1, 0, 0}, iy[4] = {-1, 0, 0, -1};

    while(q.size()){

    }
}
int main(){
    int T;
    cin>>T;
    while(T--){
        cin>>R>>C;
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                cin>>g[i][j];
            }
        }
        
    }
    return 0;
}