#include <iostream>
#include <cstdio>

#define DEBUG

using namespace std;

const int Maxn = 52;

int n, m;
int f[Maxn][Maxn], a[Maxn][Maxn];

int main()
{
	scanf("%d%d", &m, &n);
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n ; ++j)
			scanf("%d",&a[i][j]);
	for(int k = 2; k <= n+m; ++k) // k == x1 + y1 == x2 + y2
		for(int x1 = min(k-1, m); x1 && k-x1 <= n; --x1) // y >= 1 --> x <= k-1, && x <= m
			for(int x2 = min(k-1, m); x2 && k-x2 <= n; --x2) // && y <= n --> k - x <= n
			{
				f[x1][x2] = max( max(f[x1][x2], f[x1-1][x2-1]),
						         max(f[x1-1][x2], f[x1][x2-1]))
					        + a[x1][k-x1] + a[x2][k-x2];
				if(x1 == x2) f[x1][x2] -= a[x1][k-x1];
#ifdef DEBUG
				printf("%d %d %d %d %d\n",x1, k-x1, x2, k-x2, f[x1][x2]);
#endif
			}
	printf("%d\n",f[m][m]);
	return 0;
}
