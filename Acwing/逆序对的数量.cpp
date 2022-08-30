//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N= 100005;

int a[N],tmp[N];
long long cnt=0;

void merge_sort(int l,int r){
    if(l>=r) return ;
    int mid = r+l>>1;

    merge_sort(l,mid);merge_sort(mid+1,r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) tmp[k ++ ] = a[i ++ ];
        else {
            tmp[k ++ ] = a[j ++ ];
            cnt+=mid - i + 1;  //因为每次归并所使用的上次归并的结果数组都是有序的，[l,mid] 之间如果有q[i]大于右边数组q[j]的值，则[i,mid]之间的所有值都是大于q[j]的，可以用mid-l+1来计算
        }
    while (i <= mid) tmp[k ++ ] = a[i ++ ];
    while (j <= r) tmp[k ++ ] = a[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) a[i] = tmp[j];
}mid - i + 1
int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    merge_sort(0,n-1);

    printf("%lld",cnt);
    return 0;
}