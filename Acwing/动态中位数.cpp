//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;


int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int n,m;
        scanf("%d%d", &m, &n);
        printf("%d %d\n", m, (n+1)/2);
        priority_queue<int> down;
        priority_queue<int, vector<int>, greater<int> > up;
        int cnt = 0;
        for(int i=1;i<=n;i++){
            int x;
            scanf("%d", &x);

            if(down.empty()||x<=down.top()) down.push(x);
            else up.push(x);

            if(down.size() > up.size() + 1) up.push(down.top()), down.pop();
            if(up.size() > down .size()) down.push(up.top()), up.pop();

            if(i%2){
                printf("%d ", down.top());
                if(++cnt % 10 == 0) puts("");
            }
        }
        if(cnt% 10) puts("");
    }

    return 0;
}