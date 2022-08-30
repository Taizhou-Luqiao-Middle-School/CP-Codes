//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int N= 100005;

int a[N],tmp[N];

void merge_sort(int l,int r){
    if(l>=r) return ;
    int mid = r+l>>1;

    merge_sort(l,mid);merge_sort(mid+1,r);

    int k = 0, i = l, j = mid + 1;
    while (i <= mid && j <= r)
        if (a[i] <= a[j]) tmp[k ++ ] = a[i ++ ];
        else tmp[k ++ ] = a[j ++ ];
    while (i <= mid) tmp[k ++ ] = a[i ++ ];
    while (j <= r) tmp[k ++ ] = a[j ++ ];

    for (i = l, j = 0; i <= r; i ++, j ++ ) a[i] = tmp[j];
}
int main(){
    int n;
    scanf("%d",&n);

    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    merge_sort(0,n-1);

    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}