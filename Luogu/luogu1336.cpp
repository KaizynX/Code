#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 207;
const int Maxm = 30;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, m;
long long dp[2][Maxn], ans = INF;

inline long long quick_pow(int a, int p) // a^p
{
	long long res = 1;
	while(p)
	{
		if(p&1) res *= a;
		a *= a;
		p >>= 1;
	}
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(dp, 0x3f, sizeof dp);
	for(int i = 1, a, b; i <= m; ++i)
	{
		scanf("%d%d", &a, &b);
		// this kind write j
		for(int j = 0; j <= n; ++j)
		{
			long long cost = quick_pow(j, b)*a; // a*j^b
			if(i == 1)
			{
				dp[i&1][j] = cost;
				continue;
			}
			// [1, i-1] had written k
			for(int k = 0; k <= n-j; ++k)
				dp[i&1][k+j] = min(dp[i&1][k+j], dp[(i+1)&1][k]+cost);
		}
		ans = min(ans, dp[i&1][n]);
	}
	printf("%lld\n", ans);
	return 0;
}
