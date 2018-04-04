#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int Maxn = 1e6+5;
const int Maxk = 1e9+5;

int n,m,k,x;

int gcd(int a,int k,int mo)//a^k %mo
{
	int ans=1;
	a%=mo;
	while(k)//k!=0
	{
		if(k&1)//k%2==1
			ans=(ans*a)%mo;
		k>>=1;// k/=2
		a=(a*a)%n;
	}
	return ans;
}

int main()
{
	scanf("%d%d%d%d",&n,&m,&k,&x);
	//0~n-1
	// ( x + 10^k * m ) % n
	printf("%d\n",(x+m*gcd(10,k,n))%n);
	return 0;
}
