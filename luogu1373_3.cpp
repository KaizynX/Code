#include <cstdio>
#include <cstring>
#include <iostream>
// #define DEBUG

using namespace std;

const int Maxk = 20;
const int Maxn = 807;
const int ZERO = 20;
const int MOD = 1e9+7;

int n, m, k;
int a[Maxn][Maxn];
long long ans;
// dp[i][j][ki] get (i, j), can get when differ ki
long long dp[Maxn][Maxn][Maxk<<1];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	// init
	memset(dp, -1, sizeof dp);
	// for(int i = 1; i <= n; ++i) dp[i][0][ZERO] = 1;
	// for(int i = 1; i <= m; ++i) dp[0][i][ZERO] = 1;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
		{
			for(int d1 = 1, x1, y1; d1 <= 2; ++d1)
			{
				if(d1 == 1) x1 = i-1, y1 = j;       // from up 
				else x1 = i, y1 = j-1;              // from left
				if(x1 < 1 || y1 < 1) continue;
				for(int d2 = 1, x2, y2, tmp; d2 <= 2; ++d2)
				{
					if(d2 == 1) x2 = x1-1, y2 = y1; // from up 
					else x2 = x1, y2 = y1-1;        // from left
					// the differ between a & uim
					// a take (x1, y1) and uim take (i, j)
					tmp = (a[x1][y1]-a[i][j])%(k+1);
					for(int ki = ZERO-k; ki <= ZERO+k; ++ki)
						// there is a way to get ki before (x2, y2)
						if(dp[x2][y2][ki] != -1)
						{
							long long &cur = dp[i][j][(ki+tmp)%(k+1)];
							if(cur == -1) cur = 0;
							cur = (cur+dp[x2][y2][ki])%MOD;
						}
					// just start from (x2, y2)
					long long &cur = dp[i][j][ZERO+tmp];
					if(cur == -1) cur = 0;
					cur = (cur+1)%MOD;
				}
			}
			// just end at (i, j)
			long long cur = dp[i][j][ZERO];
			if(cur > 0) ans = (ans+cur)%MOD;
		}
	}
#ifdef DEBUG
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
			printf("%lld ", dp[i][j][ZERO]);
		putchar('\n');
	}
#endif
	printf("%lld\n", ans);
	return 0;
}
