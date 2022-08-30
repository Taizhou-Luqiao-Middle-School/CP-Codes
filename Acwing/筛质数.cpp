#include <iostream>
#include <algorithm>
using namespace std;

int prime[1000005],index=0;
bool st[1000005];
int main(){
    int n;
    cin>>n;
    for(int i=2;i<=n;i++){
        if(!st[i]) prime[index++] = i;
        for(int j=0;prime[j]<=n/i;j++){
            st[prime[j]*i] = true;
            if(i%prime[j]==0) break;
        }
    }
    cout<<index<<endl;
    return 0;
}