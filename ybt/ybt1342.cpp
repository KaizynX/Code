#include <bits/stdc++.h>

using namespace std;

const int Maxn = 107;
const int INF = 0x3f3f3f3f;

int n, m, s, t;
double d[Maxn][Maxn];

struct Node
{
	int x, y;
} a[Maxn];

inline double dis(int i, int j)
{
	return sqrt((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y));
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		scanf("%d%d", &a[i].x, &a[i].y);
	scanf("%d", &m);

	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= n; ++j)
			d[i][j] = INF;
		d[i][i] = 0;
	}

	for(int i = 1, x, y; i <= m; ++i)
	{
		scanf("%d%d", &x, &y);
		d[x][y] = d[y][x] = dis(x, y);
	}

	for(int k = 1; k <= n; ++k)
		for(int i = 1; i <= n; ++i)
			for(int j = 1; j <= n; ++j)
				d[i][j] = min(d[i][j], d[i][k]+d[k][j]);

	scanf("%d%d", &s, &t);
	printf("%.2f\n", d[s][t]);
	return 0;
}
