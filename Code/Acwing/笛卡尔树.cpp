#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int a[50],cnt=-1;
vector<int> t[50];
int getmin(int l, int r){
    int res = l;
    for(int i=l;i<=r;i++){
        if(a[res]>a[i]){
            res=i;
        }
    }
    return res;
}
void build(int l, int r, int d){
    if(l>r) return;
    int root = getmin(l,r);
    t[d].push_back(a[root]);
    build(l, root-1, d+1);
    build(root+1, r, d+1);
}
void print(){
    for(int i=0;t[i].size();i++){
        for(auto x: t[i]){
            cout<< x <<' ';
        }
    }
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    build(0, n-1, 0);

    print();
    return 0;
}