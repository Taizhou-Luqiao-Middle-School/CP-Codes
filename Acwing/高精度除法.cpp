#include <bits/stdc++.h>
using namespace std;

vector<int> div(vector<int> &a,int b,int &r){
    vector<int> C;
    r=0;
    for(int i=a.size()-1;i>=0;i--){
        r=r*10+a[i];
        C.push_back(r/b);//将上次的余数*10在加上当前位的数字，便是该位需要除的被除数
        r%=b;
    }
    reverse(C.begin(),C.end());
    while(C.size()>1&&C.back()==0){
        C.pop_back();
    }
    return C;
}
int main(){
    vector<int> a,res;
    int b,r;
    string A;
    cin>>A>>b;
    for(int i=A.size()-1;i>=0;i--){
        a.push_back(A[i]-'0');
    }
    res = div(a,b,r);
    for(int i=res.size()-1;i>=0;i--){
        cout<<res[i];
    }
    cout<<endl;
    cout<<r<<endl;
    return 0;
}