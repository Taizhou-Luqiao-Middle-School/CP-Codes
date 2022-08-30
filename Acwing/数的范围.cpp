//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N  = 100005;
int a[N];
int n,q;
pair<int,int> query(int k){
    pair<int,int> res;
    int l=0,r=n-1;
    while(l<r){
        int mid = l+r>>1;
        if(a[mid]>=k) r=mid;
        else l=mid+1;
    }
    res.first = l;
    if (a[l] != k) {
        pair<int,int> invalid {-1,-1};
        return invalid;
    }
    l=0,r=n-1;
    while(l<r){
        int mid = l+r+1>>1; //PAY ATTENTION!
        if(a[mid]<=k) l=mid;
        else r=mid-1;
    }
    res.second = l;
    return res;
}
int main(){

    scanf("%d%d",&n,&q);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<q;i++){
        int k;
        scanf("%d",&k);
        auto res = query(k);
        printf("%d %d\n",res.first,res.second);
    }
    return 0;
}