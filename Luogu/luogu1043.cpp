#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 52;
const int Maxm = 10;

int n, m;
int a[Maxn<<1], s[Maxn<<1];
int f_max[Maxn<<1][Maxn<<1][Maxm];
int f_min[Maxn<<1][Maxn<<1][Maxm];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		s[i] = s[i-1] + a[i];
	}
	for(int i = n+1; i <= 2*n; ++i)
	{
		a[i] = a[i-n];
		s[i] = s[i-1] + a[i];
	}
	for(int i = 1; i <= n*2; ++i)
	{
		s[i] %= 10;
		if(s[i] < 0) s[i] += 10;
	}

	for(int k = 1; k <= m; ++i)
	{
		for(int len = k; len <= n*2; ++len)
		{
			for(int i = 1, j; i <= n*2-len+1; ++i)
			{
				j = i + len - 1;
			}
		}
	}
	return 0;
}
