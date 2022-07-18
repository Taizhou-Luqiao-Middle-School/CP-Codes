#include <iostream>
using namespace std;
typedef long long ll;
ll x, y;

void exgcd(ll a, ll b){
    if(b==0){
        x=1;
        y=0;
        return;
    }

    exgcd(b, a%b);

    ll tmpx = x;
    x=y;
    y= tmpx - a/b*y;
}

int main()
{
	ll a, b;
	cin >> a >> b;
	exgcd(a, b);
    
	x = (x % b + b) % b;
	printf("%lld\n", x);
	return 0;
}