#include<bits/stdc++.h>
using namespace std;
const int maxN = 500005;
int n;
int arr[maxN];
int cnt,head[maxN],depth[maxN],vis[maxN]; 
struct node{
	int nxt,to;
}e[2*maxN];

void add(int x,int y){
	e[++cnt].nxt=head[x];
	head[x]=cnt;
	e[cnt].to=y;
}
void dfs(int u) ///递归实现深度优先搜索
{
    printf("%d ",u);
    vis[u]=true;
    for(int i=head[u];~i;i=e[i].nxt){
        int to=e[i].to;
        if(!vis[to]){
            dfs(to);
        }
    }
}

void getLIS2() {
	int tail[maxN ];
	fill(tail,tail+maxN,0);
	int cnt = 1;
	tail[cnt] = arr[0];
	for(int i = 1; i< n; i++) {
		if(arr[i] >= tail[cnt]) {
			tail[++cnt] = arr[i];
		} else {
			int idx= lower_bound(tail+1,tail+cnt+1,arr[i]) - tail;
			tail[idx] = arr[i];
		}
	}

	cout << cnt<<"\n";
}



int main() {
	memset(vis,false,sizeof(vis));
	cin >> n;
	int temp;
	for(int i = 0; i< n; i++) {
		scanf("%d",&temp);
		arr[i]=temp;
	}
	for(int i=0;i<n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	getLIS2();
}
