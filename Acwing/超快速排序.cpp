//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
const int N = 500010;

int n;
LL q[N], w[N];

LL merge_sort(int l, int r){
    if(l == r) return 0;

    int mid = l + r >>1;
    LL res = merge_sort(l,mid) + merge_sort(mid+1, r);
    int i = l, j = mid + 1, k = 0;
    while(i<=mid && j <=r){
        if(q[i] <= q[j]) w[k++] = q [i++];
        else {
            res += mid - i + 1;
            w[k++] = q[j++];
        }
    }
    while(i<=mid) w[k++] = q[i++];
    while(j<=r) w[k++] = q[j++];

    for(int i=l,j = 0;i<=r;i++,j++) q[i] = w[j];

    return res;
}
int main(){
    while(scanf("%d", &n), n){
        for(int i=0;i<n;i++){
            scanf("%d", &q[i]);
        }
        printf("%lld\n", merge_sort(0, n - 1));
    }
    return 0;
}