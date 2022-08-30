#include<bits/stdc++.h>
using namespace std;
long long int b[1000001];
int main()
{
	freopen("mcircle.in","r",stdin);
	freopen("mcircle.out","w",stdout);
	long long int a,maxx=0,ans=0;
	cin>>a;
	for(int i=0;i<=a-1;i++)
	{
		cin>>b[i];
		maxx=max(maxx,b[i]);
	}
	for(int i=0;i<=a-1;i++)
	{
		if(b[i]!=maxx) ans++;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}