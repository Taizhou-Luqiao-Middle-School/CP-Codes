#include <iostream>
#include <deque>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long ll;
struct node{
    int x, y, l, r;
};
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int n,m, r,c, x,y;
char g[2005][2005];
bool st[2005][2005];

bool check(int x, int y){
    if(x<=0||x>n||y<=0||y>m||g[x][y]=='*'||st[x][y]==1) return 1;
    return 0;
}
int bfs(){
    int res = 0;
    deque<node> q;
    q.push_back((node){r,c,x,y});
	while(!q.empty())
	{
		node p;
		p=q.front();
		q.pop_front();
		if(st[p.x][p.y]==1||(p.l<0)||(p.r<0)) continue;
		st[p.x][p.y]=1;
		res++;
		for(int i=0;i<4;i++)
		{
			int ax=p.x+dx[i];
			int ay=p.y+dy[i];
			if(check(ax, ay)) continue;
			if(i==0||i==1)
			{
				q.push_front((node){ax,ay,p.l,p.r});
				continue;
			}
			if(i==2)
			{
				q.push_back((node){ax,ay,p.l-1,p.r});
				continue;
			}
			if(i==3)
			{
				q.push_back((node){ax,ay,p.l,p.r-1});
			}
		}
	}

    return res;
}

int main(){
    cin>>n>>m>>r>>c>>x>>y;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            cin>>g[i][j];

    int ans = bfs();

    cout<<ans<<endl;
    return 0;
}