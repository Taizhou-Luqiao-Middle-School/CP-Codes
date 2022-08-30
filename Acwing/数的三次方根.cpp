//Author: CodeBoy

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include<iomanip>
using namespace std;

double calc(double x){
    return x*x*x;
}

int main(){
    double x;
    cin>>x;
    double l=-10000,r=10000,mid;
    while(r-l>=1e-7){
        mid = (l+r)/2;
        if(calc(mid)>=x) r = mid;
        else l =mid;
    }
    cout<<fixed<<setprecision(6)<<l;
    return 0;
}