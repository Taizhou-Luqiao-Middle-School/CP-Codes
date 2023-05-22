#include <iostream>
#include <cstring>
#include <string>
using namespace std;

string change(unsigned short a){
    string r="";
    //int r0=0;
    //r0 += ;
    if ((a/5)*1000){
        r = r + "1";
    }
    else {
        r = r + "0";
    }
    a = a - 5*(a/5);
    //r0 += ;
    if ((a/4)*100){
        r = r + "1";
    }
    else {
        r = r + "0";
    }
    a = a - 4*(a/4);
    //r0 += ;
    if ((a/2)*10){
        r = r + "1";
    }
    else {
        r = r + "0";
    }
    a = a - 2*(a/2);
    //r0 += ;
    if ((a/1)*1){
        r = r + "1";
    }
    else {
        r = r + "0";
    }
    a = a - 1*(a/1);
    
    return r;
}

signed main(){
    int a;
    cin>>a;
    string r="";
    while (a){
        r = change(a%10) + r;
        a/=10;
    }
    cout<<r;
    return 0;
}