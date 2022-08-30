#include <cstdio>
#include <algorithm>
using namespace std;
long long a[100005],d[100005];
int main(){
    long long n;
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld",&a[i]);d[i] = a[i] - a[i-1];
    }
    long long pos = 0 ,neg = 0;
    for(int i = 2;i<=n;i++){
        if(d[i]>=0){
            pos += d[i];
        } else {
            neg -= d[i];
        }
    }
    printf("%lld\n%lld",max(pos,neg),abs(pos-neg)+1);
    return 0;
}