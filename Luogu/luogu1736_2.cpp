#include <cstdio>
#include <iostream>
#define DEBUG

using namespace std;

const int Maxn = 2507;

int n, m, ans;
int a[Maxn][Maxn], st[Maxn][Maxn], sv[Maxn][Maxn];
int f[Maxn][Maxn][2];

// [0] 1 0 0  [1] 0 0 1
//     0 1 0      0 1 0
//     0 0 1      1 0 0

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
		{
			scanf("%d", &a[i][j]);
			st[i][j] = st[i][j-1]+a[i][j];
		}
	for(int j = 1; j <= m; ++j)
		for(int i = 1; i <= n; ++i)
			sv[i][j] = sv[i-1][j]+a[i][j];

	for(int j = 1, tmp; j <= m; ++j)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(a[i][j])
			{
				f[i][j][0] = f[i][j][1] = 1;

				tmp = f[i-1][j-1][0];
				if(st[i][j-1]-st[i][j-tmp-1] == 0
				&& sv[i-1][j]-sv[i-tmp-1][j] == 0)
					f[i][j][0] = tmp+1;

				tmp = f[i+1][j-1][1];
				if(st[i][j-1]-st[i][j-tmp-1] == 0
				&& sv[i+tmp][j]-sv[i][j] == 0)
					f[i][j][1] = tmp+1;

				ans = max(ans, max(f[i][j][0], f[i][j][1]));
			}
		}
	}
	printf("%d\n", ans);
#ifdef DEBUG
	putchar('\n');
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
			printf("%3d", f[i][j][0]);
		putchar('\n');
	}
	putchar('\n');
	for(int i = 1; i <= n; ++i)
	{
		for(int j = 1; j <= m; ++j)
			printf("%3d", f[i][j][1]);
		putchar('\n');
	}
#endif
	return 0;
}
