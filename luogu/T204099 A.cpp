#include <bits/stdc++.h>
using namespace std;
int X[50005],Y[50005];
int main(){
	freopen("A.out","w",stdout);
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i<=n;i++){
		int temp;
		scanf("%d",&temp);
		Y[i]=temp;
	} 
	for(int i=0;i<=n;i++){
		int temp;
		scanf("%d",&temp);
		X[i]=temp;
	} 
	for(int i=0;i<k;i++){
		int up,down,right,left,aX,aY,ans=0;
		scanf("%d%d%d%d",&up,&down,&left,&right);
		for(int j=0;j<n;j++){
			for(int jj=0;jj<n;jj++){
//				cout<<endl<<X[j]<<endl<<X[j+1]<<endl<<Y[jj]<<endl<<Y[jj+1]<<endl;
				if(X[j]==left&&X[j+1]==right&&Y[jj]==up&&Y[jj+1]==down){
					ans++;
					aY=j;aX=jj;
				}
			}
		}
		if(ans!=0) printf("%d %d\n",aX+1,aY+1);
		else printf("%d\n",ans);
	}
	return 0;
}
