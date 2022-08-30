#include <iostream>
#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
const int N = 1e5+5;
set< pair<int,int> > external,inter;
set< pair<int,int> >:: iterator it;
int f_in[N],f_ex[N],ans=0;
int calc_inter(){
    int res=0,now=0;
    while(it=inter.lower_bound(make_pair(now,now)),
          it!=inter.end()){
        res++;
        now=it->second;
        inter.erase(it);
    }
    return res;
}
int calc_external(){
    int res=0,now=0;
    while(it=external.lower_bound(make_pair(now,now)),
          it!=external.end()){
        res++;
        now=it->second;
        external.erase(it);
    }
    return res;
}
int main(){
    int n,m1,m2;
    pair<int,int> t;

    scanf("%d%d%d",&n,&m1,&m2);
    for(int i=0;i<m1;i++){
        scanf("%d%d",&t.first,&t.second);
        inter.insert(t);
    }
    for(int i=0;i<m2;i++){
        scanf("%d%d",&t.first,&t.second);
        external.insert(t);
    }
    f_ex[0]=0,f_in[0]=0;

    for(int i=1;i<=n;i++)
        f_in[i]=f_in[i-1]+calc_inter();
    for(int i=1;i<=n;i++)
        f_ex[i]=f_ex[i-1]+calc_external();

    for(int i=0;i<=n;i++){
        ans = max(f_in[i]+f_ex[n-i],ans);
    }
    printf("%d",ans);
    return 0;
}