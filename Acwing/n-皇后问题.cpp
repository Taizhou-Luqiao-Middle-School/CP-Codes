//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
char c[15][15];
bool xie1[30],xie2[30],li[15];
void place(int a,int i,int n){
    li[i] = xie1[i+a] = xie2[n-i+a] = 1;
}
void remove(int a,int i,int n){
    li[i] = xie1[i+a] = xie2[n-i+a] = 0;
}
void dfs(int a,int n){
    if(a==n){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<c[i][j];
            }
            cout<<endl;
        }
        cout<<endl;
        return ;
    };
    for(int i=0;i<n;i++){
        if(!li[i]&&!xie1[i+a]&&!xie2[n-i+a]){
            c[a][i] = 'Q';
            place(a,i,n);
            dfs(a+1,n);
            remove(a,i,n);
            c[a][i] = '.'; 
        } 
    }
}
void init(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            c[i][j] = '.';
        }
    }
}
int main(){
    int n;
    cin>>n;
    init(n);
    dfs(0,n);
    return 0;
}