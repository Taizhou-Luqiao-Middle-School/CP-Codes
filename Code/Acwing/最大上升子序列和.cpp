//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Re register
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;
int a[1005], f[1005];

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        f[i] = a[i];
        for(int j=0;j<i;j++){
            if(a[i]>a[j]) f[i] = max(f[i], f[j] + a[i]);
        }
    }
    
    int ans = -1;
    for(int i=0;i<n;i++){
        ans = max(ans, f[i]);
    }
    
    cout<<ans<<endl;
    return 0;
}