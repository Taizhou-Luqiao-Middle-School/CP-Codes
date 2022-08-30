#include <iostream>
#include <cstring>
using namespace std;
const int N = 100;
string v[N];
int l[N],r[N];
bool st[N];

void dfs(int i){
    cout<<'(';
    if(l[i]!=-1&&r[i]!=-1){
        dfs(l[i]);
        dfs(r[i]);
        cout<<v[i];
    } else if(l[i]==-1&&r[i]==-1){
        cout<<v[i];
    } else {
        cout<<v[i];
        dfs(r[i]);
        
    }
    cout<<')';
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>v[i]>>l[i]>>r[i];
        if(l[i] != -1) st[l[i]] = true;
        if(r[i] != -1) st[r[i]] = true;
    }
    int root;
    for(int i=1;i<=n;i++){
        if(!st[i]){
            root = i;
        }
    }

    dfs(root);

    return 0;
}