#include <iostream>
#include <cstdio>
#define LL long long
using namespace std;
const int maxn=1000000000;

LL a;
int n,b[12];

int main()
{
	bool flag=0;
	scanf("%lld",&a);
	if(a<0)
	{
		putchar('-');
		a=-a;
	}
	while(a>0)
	{
		n++;
		b[n]=a%10;
		a/=10;	
	}
	for(int i=1;i<=n;++i)
	{
		if(b[i])flag=1;
		if(flag)printf("%d",b[i]);
	}
	return 0;
} 
