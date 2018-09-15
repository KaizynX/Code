#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e4+7;
const int Maxm = 5e2+7;

int n, m, a;
int dp[Maxn][Maxm];
// dp[i][j] when come to minite i with j tired

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
	{
		scanf("%d", &a);
		// just rest
		dp[i][0] = max(dp[i][0], dp[i-1][0]);
		// in i'th minite has at last i-1 tired
		for(int j = 0; j <= min(i-1, m); ++j)
		{
			// run
			if(j+1 <= m)
				dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j]+a);
			// start to rest
			if(j && i+j <= n+1)
				dp[i+j][0] = max(dp[i+j][0], dp[i][j]);
		}
	}
	printf("%d\n", max(dp[n][0], dp[n+1][0]));
	return 0;
}
