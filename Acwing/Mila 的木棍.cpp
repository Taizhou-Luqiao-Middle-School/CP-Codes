#include<bits/stdc++.h>
using namespace std;
long long int b[1000005],a,maxx=0,ans=0;
int main()
{
	freopen("stick.in","r",stdin);
	freopen("stick.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a-1;i++)
	{
		cin>>b[i];
	}
	int j=a-1;
	while(j!=-1)
	{
		if(b[j]<b[j-1])
		{
			ans+=b[j-1]-b[j];
			while(b[j]>b[j-1])
			{
				j--;
			}
		}
		j--;
	}
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
}