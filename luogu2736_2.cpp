#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 30;

int n, t, m;
int dp[Maxn][Maxn];

inline int max3(int a, int b, int c)
{
	return max(a, max(b, c));
}

int main()
{
	scanf("%d%d%d", &n, &t, &m);
	for(int i = 1, a; i <= n; ++i)
	{
		scanf("%d", &a);
		for(int j = m; j; --j)
			for(int k = t; k >= a; --k)
			{
				dp[j][k] = max3(dp[j][k],
								dp[j-1][t]+1,
								dp[j][k-a]+1);
			}
	}
	printf("%d\n", dp[m][t]);
	return 0;
}
