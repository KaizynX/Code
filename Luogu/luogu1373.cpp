#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxk = 20;
const int Maxn = 807;
const int ZERO = 20;
const int MOD = 1e9+7;

int n, m, k;
int a[Maxn][Maxn];
long long ans;
long long dp[Maxn][Maxn][Maxk<<1];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	memset(dp, -1, sizeof dp);
	for(int j = 1; j <= n; ++j) dp[j][1][0] = 0;
	for(int j = 1; j <= m; ++j) dp[1][j][0] = 0;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);

	for(int i = 1, tmp; i <= n+1; ++i)
	{
		for(int j = 1; j <= m+1; ++j)
		{
			if(i+j <= 2) continue;

			if(j > 2)
			{
				// the differ between a & uim
				tmp = a[i][j-2]-a[i][j-1];
				for(int ki = ZERO-k; ki <= ZERO+k; ++ki)
					// there is a way to get ki before
					if(dp[i][j-2][ki] != -1)
					{
						long long &cur = dp[i][j][(ki+tmp)%(k+1)];
						if(cur == -1) cur = 0;
						cur = (cur+dp[i][j-1][ki])%MOD;
					}
			}
			// just start from it
			dp[i][j][tmp%(k+1)] += 1;

			if(i > 2)
			{
				tmp = a[i-2][j]-a[i-1][j];
				for(int ki = ZERO-k; ki <= ZERO+k; ++ki)
					if(dp[i-2][j][ki] != -1)
					{
						long long &cur = dp[i][j][(ki+tmp)%(k+1)];
						if(cur == -1) cur = 0;
						cur += (cur+dp[i][j-1][ki])%MOD;
					}
			}
			dp[i][j][tmp%(k+1)] += 1;

			tmp = a[i-1][j-1]-a[i-1][j];
			for(int ki = ZERO-k; ki <= ZERO+k; ++ki)
				if(dp[i-1][j-1][ki] != -1)
				{
					long long &cur = dp[i][j][(ki+tmp)%(k+1)];
					if(cur == -1) cur = 0;
					cur += (cur+dp[i][j-1][ki])%MOD;
				}
			dp[i][j][tmp%(k+1)] += 1;

			tmp = a[i-1][j-1]-a[i][j-1];
			for(int ki = ZERO-k; ki <= ZERO+k; ++ki)
				if(dp[i-1][j-1][ki] != -1)
				{
					long long &cur = dp[i][j][(ki+tmp)%(k+1)];
					if(cur == -1) cur = 0;
					cur += (cur+dp[i][j-1][ki])%MOD;
				}
			dp[i][j][tmp%(k+1)] += 1;

			ans = (ans+dp[i][j][0])%MOD;
		}
	}
	printf("%lld\n", ans);
	return 0;
}
