#include <iostream>
#include <cstring>
#include <string>
using namespace std;

signed main(){
    int p=0;
    cin>>p;//刷掉输入
    string input;
    cin>>input;
    char sign = input[0];
    p=0;
    int len[1000]={};
    for (int i=0;i<input.length();i++){
        if (sign==input[i]){
            len[p]++;
        }
        else {
            p++;
            sign=input[i];
            len[p]++;
        }
    }
    int sum=0;
    for (int i=0;i<=p;i++){
        len[i] = len[i] % 2;
    }
    
    for (int i=0;i<=p;i++){
        if (len[i]==0){
            continue;
        }
        int k=i+1;
        for (k=i+1;k<=p;k++){
            if (len[k]==1){
                break;
            }
            
        }
        sum += k-i;
        i=k;
    }
    
    cout<<sum;
    
    return 0;
}