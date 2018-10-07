#include <cstdio>
#include <cstring>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxk = 20;
const int Maxn = 807;
const int ZERO = 20;
const int MOD = 1e9+7;

int n, m, k;
int a[Maxn][Maxn];
long long ans;
// dp[i][j][ki] before get (i, j), can get when differ ki
long long dp[Maxn][Maxn][Maxk<<1];

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	// init
	memset(dp, -1, sizeof dp);
	// for(int i = 1; i <= n; ++i) dp[i][1][ZERO] = 1;
	// for(int i = 1; i <= m; ++i) dp[1][i][ZERO] = 1;

	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);

	for(int i = 1; i <= n+1; ++i)
	{
		for(int j = 1; j <= m+1; ++j)
		{
			for(int d = 1, x1, x2, y1, y2, tmp; d <= 4; ++d)
			{
				// four ways
				if(d == 1) x1 = i, x2 = i, y1 = j-2, y2 = j-1; 
				else if(d == 2) x1 = i-2, x2 = i-1, y1 = j, y2 = j; 
				else if(d == 3) x1 = i-1, x2 = i-1, y1 = j-1, y2 = j; 
				else if(d == 4) x1 = i-1, x2 = i, y1 = j-1, y2 = j-1;
				// x1 <= x2, y1 <= y2
				if(x1 < 1 || y1 < 1 || x2 > n || y2 > m) continue;
#ifdef DEBUG
				printf("(x, y):%d %d %d %d\n", x1, y1, x2, y2);
#endif
				// the differ between a & uim
				// a take (x1, y1) and uim take (x2, y2)
				tmp = (a[x1][y1]-a[x2][y2])%(k+1);
				for(int ki = ZERO-k; ki <= ZERO+k; ++ki)
					// there is a way to get ki before (x1, y1)
					if(dp[x1][y1][ki] != -1)
					{
						long long &cur = dp[i][j][(ki+tmp)%(k+1)];
						if(cur == -1) cur = 0;
						cur = (cur+dp[x1][y1][ki])%MOD;
#ifdef DEBUG
						printf("dp[%d][%d][%d]=%lld\n", i, j, ki-ZERO, cur);
#endif
					}
				// just start from (x1, y1)
				// if(x1 == 1 || y1 == 1) continue;
				long long &cur = dp[i][j][tmp+ZERO];
				if(cur == -1) cur = 0;
				cur = (cur+1)%MOD;
			}
			// just end at (i, j)
			long long cur = dp[i][j][ZERO];
			if(cur > 0) ans = (ans+cur)%MOD;
#ifdef DEBUG
			printf("ans=%lld\n", ans);
#endif
		}
	}
	printf("%lld\n", ans);
	return 0;
}
