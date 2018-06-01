#include <cstdio>
#include <iostream>
using namespace std;

int n,m,k,x;
//a^k % m
int mo(int a,int k,int m)
{
	int ans=1;
	a%=m;
	while(k)
	{
		if(k&1)
			ans=(ans*a)%m;
		k/=2;
		a=(a*a)%m;
	}
	return ans;
}

int main()
{
	int now;
	scanf("%d%d%d%d",&n,&m,&k,&x);
	now=(x+m*mo(10,k,n))%n;
	printf("%d\n",now);
	return 0;
}
