#include <cstdio>
#include <iostream>
#define LL long long 
using namespace std;
const int Maxn = 1000000+5;

LL n,m,k,x;

LL q(LL a,LL k,LL mo)
{
	LL ans=1;
	a%=mo;
	while(k)
	{
		if(k&1)
		{
			ans=(ans*a)%mo;
		}
		k>>=1;
		a=(a*a)%mo;
	}
	return ans;
}

int main()
{
	cin>>n>>m>>k>>x;
	// (x+10^k*m)%n
	cout<<( x+m*q(10,k,n) )%n;
	return 0;
}
