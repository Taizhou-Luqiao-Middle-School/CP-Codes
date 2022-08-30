//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;
#define PII pair<int,int>
const int N = 100005;
vector<PII> seg;
int merge(){
    vector<PII> tmp;
    sort(seg.begin(),seg.end());
    int l = -2e9,r = -2e9;
    for(auto s:seg){
        if(r<s.first){
            if (l != -2e9) tmp.push_back({l,r});
            l = s.first;r = s.second;
        }
        else{
            r = max(r,s.second);
        }
    }
    if(l != -2e9) tmp.push_back({l,r});
    // for(auto s:tmp){
    //     cout<<s.first<<' '<<s.second<<endl;
    // }
    return tmp.size();
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        PII t;
        scanf("%d%d",&t.first,&t.second);
        seg.push_back(t);
    }

    int ans = merge();

    cout<<ans<<endl;
    return 0;
}