#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int N = 100005;
int dist[N+10],q[N+10];
void bfs(int n, int m){
	memset(dist, -1, sizeof dist);
	q[0] = n;
	dist[n] = 0;
	int hh =0, tt = 0;
	while(hh<=tt){
		int t = q[hh++];
//		cout<<t<<endl;
		
		if(t == m) {
			cout<<dist[t]<<endl;
			return;
		}
		if(dist[t+1]==-1&&t+1<N){
			q[++tt] = t+1;
			dist[t+1] = dist[t] + 1;
		}
		if(dist[t-1]==-1&&t-1>=0){
			q[++tt] = t-1;
			dist[t-1] = dist[t] + 1;
		}
		if(dist[t*2]==-1&&t*2<N){
			q[++tt] = t*2;
			dist[t*2] = dist[t] + 1;
		}
	}

}
int main(){
	int n,k;
	cin>>n>>k;
	bfs(n,k);
	return 0;
}

