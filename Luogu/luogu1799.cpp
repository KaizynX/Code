#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e3+7;

int n, ans;
int dp[Maxn][Maxn];
// dp[i][j] at i'th pos del j nums

int main()
{
	scanf("%d", &n);
	for(int i = 1, a; i <= n; ++i)
	{
		scanf("%d", &a);
		for(int j = 0; j <= i; ++j)
		{
			dp[i][j] = dp[i-1][j-1]; // delete this
			if(j <= i-1)
				dp[i][j] = max(dp[i][j], dp[i-1][j]+(a == i-j));
			if(i == n) ans = max(ans, dp[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}
