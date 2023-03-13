#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[30];
    for (int i = 0;i<20;i++){
        cin>>a[i];
    }
    for (int i= 20;i<26;i++){
        a[i] = a[i-20];
    }
    int p =0;
    int max = -1;
    for (int i = 0;i<20;i++){
        int n = a[i] + a[i+1] + a[i+2] + a[i+3];
        if (n>max){
            p = i;
            max = n;
        }
    }
    printf("%d %d",p+1,max);
    return 0;
}