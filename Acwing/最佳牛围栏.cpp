//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 100005;
int n,f;
int cows[N];
double sum[N];

bool check(double avg){
    for (int i = 1; i <= n; i++) {
        sum[i] = sum[i - 1] + cows[i] - avg;
    }
    double minv = 3005;
    for(int i=0,j=f;j<=n;j++,i++){
        minv = min(sum[i], minv);
        if(sum[j] - minv >= 0){
            return true;
        }
    }
    return false;
}

int main(){
    scanf("%d%d",&n,&f);
    double l,r;
    for(int i=1;i<=n;i++){
        scanf("%d",&cows[i]);
        r = max(cows[i],(int)r);
    }
    l = 0;
    while(r-l>0.00001){
        double mid = (l+r)/2;
        if(check(mid)){
            l = mid;
        } else {
            r = mid;
        }
    }
    printf("%d", (int)(r * 1000));
    return 0;
}