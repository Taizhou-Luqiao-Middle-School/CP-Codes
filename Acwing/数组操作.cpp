//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define Re register
#define max(a, b) ((a) > (b) ? (a) : (b))
#define min(a, b) ((a) > (b) ? (b) : (a))
using namespace std;
typedef long long ll;

int a[1000];
int main(){
    int n;
    cin>>n;
    int s=0, x=0x3f3f3f3f;

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        s += a[i];
        x = min(s, x);
    }
    x = min(0, x);
    // cout<<s<<' '<<x<<endl;
    cout<<s-x<<endl;
    return 0;
}