// Author: Codeboy

/////////////////////// Macros & Head ////////////////////

#include <bits/stdc++.h>
#define Re register
#define F(i,l,r) for(int i=l;i<r;++i)
#define Fe(i,l,r) for(int i=l;i<=r;++i)
#define Fer(i,l,r) for(int i=l;i>=r;--i)
using namespace std;
typedef long long ll;
typedef __int128 lll;
typedef pair<int, int> PII;
void fastio(){ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);}

//////////////////// Global Variables ////////////////////

constexpr int N = 105;
constexpr int mod = 998244353;
int n;
int a[N];
ll ans;
ll f[N][N][N];

/////////////////////// Functions ////////////////////////



////////////////////// Main Execution ////////////////////

int main(){
	fastio();
	cin>>n;
	F(i, 0, n) cin>>a[i];
	
	for(int i=1;i<=n;i++){
		memset(f, 0, sizeof f);
		f[0][0][0] = 1;
		for(int j=0;j<n;j++){
			for(int k=0;k<=i;k++){
				for(int l=0;l<i;l++){
					f[j+1][k][l] = (f[j][k][l] + f[j+1][k][l]) % mod;
					if(k!=i) 
						f[j+1][k+1][(l+a[j])%i] = (f[j+1][k+1][(l+a[j])%i] + f[j][k][l]) % mod;
				}
			}
		}

		ans = (ans + f[n][i][0]) % mod;

	}
	
	cout<<ans % mod<<endl;
	
	return 0;
}

////////////////////// The End... ////////////////////////

////////////// Hope everything goes well. ////////////////

////////////////////// Farewell! /////////////////////////
