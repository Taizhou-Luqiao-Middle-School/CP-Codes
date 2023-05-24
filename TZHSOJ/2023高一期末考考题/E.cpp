#include <bits/stdc++.h>
using namespace std;

signed main(){
    int a,b;
    string s;
    cin>>a>>b>>s;
    if (s=="+"){
        cout<<a+b;
    }
    else if (s=="-"){
        cout<<a-b;
    }
    else if (s=="*"){
        cout<<a*b;
    }
    else if (s=="//"){
        if (b==0){
            cout<<"Error";
            return 0;
        }
        cout<<a/b;
    }
    else if (s=="%"){
        cout<<a%b;
    }
    else {
        cout<<"Error";
    }
    return 0;
}