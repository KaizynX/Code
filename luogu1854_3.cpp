#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e2+7;

int n, m;
int a[Maxn][Maxn], dp[Maxn][Maxn], pre[Maxn][Maxn];

void print(int th, int pos)
{
	if(th == 0) return;
	print(th-1, pre[th][pos]);
	printf("%d ", pos);
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for(int i = 1; i <= m-n+1; ++i)
		dp[1][i] = a[1][i];
	for(int i = 2; i <= n; ++i)
		for(int j = i; j <= m-n+i; ++j)
			for(int k = 1; k < j; ++k)
				if(dp[i-1][k]+a[i][j] > dp[i][j])
				{
					dp[i][j] = dp[i-1][k]+a[i][j];
					pre[i][j] = k;
				}
	int ans = 0;
	for(int i = n; i <= m; ++i)
		if(dp[n][i] > dp[n][ans])
			ans = i;
	printf("%d\n", dp[n][ans]);
	print(n, ans);
	return 0;
}
