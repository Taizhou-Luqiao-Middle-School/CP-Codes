#include <iostream>
#include <stack>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        stack<int> s;
        int t,cnt=0;
        cin>>t;
        for(int j=1;j<=t/j;j++){
            if(t%j==0){
                cout<<j<<' ';
                if(t/j!=j) {
                    cnt++;
                    s.push(t/j);
                }
            }
        }
        while(cnt--){
            cout<<s.top()<<' ';
            s.pop();
        }
        cout<<endl;
    }
    return 0;
}