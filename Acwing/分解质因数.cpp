#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        for(int j=2;j<=a/j;j++){
            if(a%j==0){
                int t = 0;
                while(a%j==0){
                    a/=j;
                    t++;
                }
                cout<<j<<' '<<t<<endl;
            }
        }
        if(a>1) cout<< a <<' '<<1<<endl;
        cout<<endl;
    }
    return 0;
}