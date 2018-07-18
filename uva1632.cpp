#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#define NO "No solution"

using namespace std;

const int Maxn = 1e4 + 7;
const int INF = 0x3f3f3f3f;

int n;
int f[Maxn][Maxn][2];
/* after taking the [l, r], must stay at l or j
 * f[l][r][0] stay at l
 * f[l][r][1] stay at r
 * f[l][r][0] = min( f[l+1][r][0] + dis(l, l+1), f[l+1][r][1] + dis(l, r)   )
 * f[l][r][1] = min( f[l][r-1][0] + dis(l, r),   f[l][r-1][1] + dis(r-1, r) )
 */

struct Treasure
{
	int x, t;
} a[Maxn];
// a[j].x > a[i].x (j > i)
inline int dis(int i, int j) { return a[j].x - a[i].x; }

int main()
{
	while(scanf("%d", &n) == 1)
	{
		for(int i = 1; i <= n; ++i)
			scanf("%d%d", &a[i].x, &a[i].t);
		// memset(f, 0, sizeof f); // f[i][i][] = 0
		for(int i = 1; i <= n; ++i)
			f[i][i][0] = f[i][i][1] = a[i].t < 0 ? INF : 0;
		for(int k = 2; k <= n; ++k)
			for(int l = 1, r; l <= n-k+1; ++l)
			{
				r = l + k - 1;
				f[l][r][0] = min(f[l+1][r][0] + dis(l, l+1), f[l+1][r][1] + dis(l, r));
				f[l][r][1] = min(f[l][r-1][1] + dis(r-1, r), f[l][r-1][0] + dis(l, r));
				if(f[l][r][0] > a[l].t) f[l][r][0] = INF;
				if(f[l][r][1] > a[r].t) f[l][r][1] = INF;
			}
		int ans = min(f[1][n][0], f[1][n][1]);
		if(ans >= INF) puts(NO);
		else printf("%d\n", ans);
	}
	return 0;
}
