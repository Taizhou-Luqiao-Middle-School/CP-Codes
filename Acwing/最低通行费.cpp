/*
 * @Author: CodeBoy2006 gyj2006@foxmail.com
 * @Date: 2022-05-30 19:44:41
 * @LastEditors: CodeBoy2006 gyj2006@foxmail.com
 * @LastEditTime: 2022-05-30 19:56:03
 * @FilePath: \ACWing\最低通行费.cpp
 *  */
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;

int w[N][N],f[N][N];

int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin>>w[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==1&&j==1) f[i][j] =w[i][j];
            else{
                f[i][j]=1e9;
                if(i>1) f[i][j] = min(f[i][j],f[i-1][j]+w[i][j]);
                if(j>1) f[i][j] = min(f[i][j],f[i][j-1]+w[i][j]);
            }
        }
    }
    cout<<f[n][n]<<endl;
    return 0;
}