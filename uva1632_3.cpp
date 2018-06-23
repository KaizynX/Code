#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int Maxn = 1e5 + 7;
const int INF = 1 << 30;

int n;
int x[Maxn], t[Maxn];
int f[2][Maxn][2];

// f[len][l][end]
// in area [l, start+len-1], end at [0] -- left, [1] -- right

int main()
{
	while(scanf("%d", &n) == 1)
	{
		memset(f, 0, sizeof f);
		for(int i = 1; i <= n; ++i)
			scanf("%d%d", x+i, t+i);
		// f[1][i][01] = 0
		for(int k = 2; k <= n; ++k)
			for(int l = 1, r; l <= n-k+1; ++l)
			{
				r = l + k - 1;
				f[k&1][l][0] = min(f[(k-1)&1][l+1][0] + x[l+1]-x[l], f[(k-1)&1][l+1][1] + x[r]-x[l]);
				f[k&1][l][1] = min(f[(k-1)&1][l][1] + x[r]-x[r-1], f[(k-1)&1][l][0] + x[r]-x[l]);
				if(f[k&1][l][0] >= t[l]) f[k&1][l][0] = INF;
				if(f[k&1][l][1] >= t[r]) f[k&1][l][1] = INF;
			}
		int ans = min(f[n&1][1][0], f[n&1][1][1]);
		if(ans >= INF) puts("No solution");
		else printf("%d\n", ans);
	}
	return 0;
}
