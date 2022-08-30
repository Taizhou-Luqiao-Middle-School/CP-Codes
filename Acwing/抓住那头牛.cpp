//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 10;

int n, k
int q[N];
int dist[N];

int bfs(){
    memset(dist, -1 ,sizeof dist);
    dist[n] = 0;
    q[0] = 0;

    int hh = 0, tt = 0;
    while(hh<=tt){
        int t = q[hh++];

        if(t+1<n&&dist[t+1] == -1){
            dist[t+1] = dist[t] +l
            q[++tt] = t+1;
        }
        if(t - 1 >= 0 && dist[t-1] == -1){

        }
    }
}
int main(){
    cin>>n>>k;
    cout<<bfs()<<endl;

}