#include <cstdio>
#include <iostream>
#include <cmath>
#define NO "Crossing the line\n"
using namespace std;
const int Maxn = 1000+5;
const int Maxm = 1000000+5;

int n,m,l,r,cnt;
bool prime[Maxm];
int sum[Maxm];

int getint()
{
	int res=0;
	bool flag=0;
	char c=getchar();
	while(c<'0' || c>'9')
	{
		if(c=='-')flag=1;
		c=getchar();
	}
	while(c>='0' && c<='9')
	{
		res=res*10+c-'0';
		c=getchar();
	}
	if(flag)return -res;
	else return res;
}

bool is_prime(int a)
{
	for(int i=2;i<=sqrt(a)+0.5;++i)
	{
		if(a%i==0)return 0;
	}
	return 1;
}

void init()
{
	int maxm=1000000;
	prime[2]=1;
	for(int i=3;i<=maxm;++i)
		prime[i]=is_prime(i);
	for(int i=1;i<=maxm;++i)
		sum[i]=sum[i-1]+prime[i];
}

int main()
{
	n=getint();
	m=getint();
	init();
	while(n--)
	{
		l=getint();
		r=getint();
		if(l<1 || l>m || r<1 || r>m)
		{
			printf(NO);
			continue;
		}
		cnt=sum[r]-sum[l-1];
		printf("%d\n",cnt);
	}
	return 0;
}
