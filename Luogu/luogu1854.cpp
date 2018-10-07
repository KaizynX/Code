#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e2+7;

int n, m;
int a[Maxn][Maxn], f[Maxn][Maxn], nex[Maxn][Maxn];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for(int i = n; i; --i)
		for(int j = 1; j <= m; ++j)
			for(int k = j+1; k <= m+1; ++k)
				if(f[i+1][k]+a[i][j] > f[i][j])
				{
					f[i][j] = f[i+1][k]+a[i][j];
					nex[i][j] = k;
				}
	int ans = 0;
	for(int i = 1; i <= m; ++i)
		if(f[1][ans] < f[1][i])
			ans = i;
	printf("%d\n", f[1][ans]);
	for(int i = 1; i <= n; ++i)
	{
		printf("%d ", ans);
		ans = nex[i][ans];
	}
	putchar('\n');
	return 0;
}
