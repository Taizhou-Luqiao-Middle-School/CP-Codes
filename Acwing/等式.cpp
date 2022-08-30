#include <bits/stdc++.h>
using namespace std;

int n,d;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&d);
		double a,b,c;
		c=d*d-4*d;
		if(c<0)
		{
			printf("N\n");
		}
		else
		{
			a=((double)d+sqrt(c))/2.0;
			b=((double)d-sqrt(c))/2.0;
			printf("Y %.10f %.10f\n",a,b);
		}
	}
	return 0;
}