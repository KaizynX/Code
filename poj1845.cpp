#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int Mo = 9901;
const int Maxn = 10007;

int a, b, ans;
// a   = p[1]^c[1] +...+ p[n]^c[n]
// a^b = p[1]*c[1]*b +...+ p[n]^(c[n]*b)
int p[Maxn], c[Maxn], cnt;

inline int quickm(int p, int c) // p^c
{
	int res = 1;
	while(c)
	{
		if(c & 1) res = res * p % Mo;
		c >>= 1;
		p = p * p % Mo;
	}
	return res;
}

int calc(int p, int c) // p^0 +...+ p^c
{
	if(c == 0) return 1;

	if(c & 1)
	{
		// == (p^0+..+p^(c-1)/2)+(p^(c+1)/2+..+p^c) 
		return (1 + quickm(p,(c+1)/2)) * calc(p,(c-1)/2) % Mo; 
	}
	else
	{
		return ( (1 + quickm(p,c/2+1)) * calc(p,c/2-1) + quickm(p,c/2) ) % Mo;
	}
}

int main()
{
	while(cin >> a >> b)
	{
		cnt = 0;
		// i < sqrt(a)
		for(int i = 2; i*i <= a; ++i)
		{
			if(a % i == 0)
			{
				p[++cnt] = i;
				c[cnt] = 0;
				while(a % i == 0)
				{
					++c[cnt];
					a /= i;
				}
			}
		}
		if(a > 1)
		{
			p[++cnt] = a;
			c[cnt] = 1;
		}
		// ans = (p[1]^0 + p[1]^1 +...+p[1]^(c[1]*b))*..*(p[n]^0+...+p[n]^(c[n]*b))
		ans = 1;
		for(int i = 1; i <= cnt; ++i)
		{
			ans = ans * calc(p[i],c[i]*b) % Mo;
		}
		printf("%d\n",ans);
	}
	return 0;
}
