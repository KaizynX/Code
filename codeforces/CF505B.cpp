#include <cstdio>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 150007;

int n;
long long ans = 1;
int a[Maxn][2];

inline long long gcd(long long a, long long b)
{
	long long tmp;
	while(b)
	{
		tmp = a;
		a = b;
		b = tmp%b;
	}
	return a;
}

int main()
{
	long long tmp1, tmp2;
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i][0], &a[i][1]);
	if(n == 1) 
	{
		ans = gcd(a[1][0], a[1][1]);
		if(ans == 1) ans = -1;
		printf("%I64d\n", ans);
		return 0;
	}
	for(int i = 0; i < 2; ++i)
		for(int j = 0; j < 2; ++j)
		{
			// ans = max(ans, gcd(a[1][i], a[2][j]));
			tmp1 = gcd(a[1][i], a[2][j]);
			ans *= tmp1/gcd(ans, tmp1);
		}
	for(int i = 3; i <= n; ++i)
	{
		tmp1 = gcd(ans, a[i][0]);
		tmp2 = gcd(ans, a[i][1]);
		tmp1 = ans*tmp1/gcd(ans, tmp1);
		tmp2 = ans*tmp2/gcd(ans, tmp2);
		ans = tmp1*tmp2/gcd(tmp1, tmp2);
#ifdef DEBUG
		printf("%I64d\n", ans);
#endif
		if(ans == 1) break;
	}
	if(ans == 1)
	{
		puts("-1");
		return 0;
	}
	for(long long i = 2; i*i <= ans; ++i)
	{
		if(ans%i == 0)
		{
			printf("%I64d\n", i);
			return 0;
		}
	}
	return 0;
}
