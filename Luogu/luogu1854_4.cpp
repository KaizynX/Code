#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e2+7;

int n, m;
int a[Maxn][Maxn], dp[Maxn][Maxn], nex[Maxn][Maxn];

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for(int i = n; i <= m; ++i)
		dp[n][i] = a[n][i];
	for(int i = n-1; i; --i)
		for(int j = i; j <= m-n+i; ++j)
			//for(int k = max(i+1, j+1); k <= m; ++k)
			for(int k = m; k >= max(i+1, j+1); --k)
				if(dp[i+1][k]+a[i][j] > dp[i][j])
				{
					dp[i][j] = dp[i+1][k]+a[i][j];
					nex[i][j] = k;
				}
	int ans = 0;
	for(int i = 1; i <= m-n+1; ++i)
		if(dp[1][i] > dp[1][ans])
			ans = i;
	printf("%d\n%d", dp[1][ans], ans);
	for(int i = 1; i < n; ++i)
		printf(" %d", (ans = nex[i][ans]));
	putchar('\n');
	return 0;
}
