#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e2+7;

int n, m;
int a[Maxn][Maxn];
int f[Maxn][Maxn], last[Maxn][Maxn];

void print(int i, int cur)
{
	if(!i || !cur) return;
	print(i-1, last[i][cur]);
	printf("%d ", cur);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			for(int k = 0; k < j; ++k)
				if(f[i-1][k]+a[i][j] > f[i][j])
				{
					f[i][j] = f[i-1][k]+a[i][j];
					last[i][j] = k;
				}
	int ans = 0;
	for(int i = 1; i <= m; ++i)
		if(f[n][ans] < f[n][i])
			ans = i;
	printf("%d\n", f[n][ans]);
	print(n, ans);
	return 0;
}
