#include <cstdio>
#include <iostream>
using namespace std;
const int Maxn = 2000;

int t,k,n,m;//k=[2-21]
int a[Maxn+5][2];//´æ´¢n,m
int c[Maxn+5][Maxn+5];//C[n,m]
int s[Maxn+5][Maxn+5];//sum of answer from [0,0] to [n,m]

inline void in();
inline void out();
inline void init()
{
	for(n=1;n<=Maxn;++n)
	{
		for(m=1;m<=n;++m)
		{
			if(m==1)c[n][m]=n%k;
			else if(m==n)c[n][m]=1;
			else c[n][m]=(c[n-1][m]+c[n-1][m-1])%k;
			//   c[n][m]= c[n-1][m]+c[n-1][m-1]
		}
	}
	for(n=1;n<=Maxn;++n)
	{
		for(m=1;m<=Maxn;++m)
		{
			s[n][m]=s[n-1][m]+s[n][m-1]-s[n-1][m-1];
			if(n>=m && c[n][m]%k==0)
				s[n][m]++;
		}
	}
}

int main()
{
	in();
	init();
	out();
	return 0;
}

inline void in()
{
	scanf("%d%d",&t,&k);
}


inline void out()
{
	for(int i=1;i<=t;++i)
	{
		scanf("%d%d",&n,&m);
		printf("%d\n",s[n][m]);
	}
}
