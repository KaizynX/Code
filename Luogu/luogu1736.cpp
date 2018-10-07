#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 2507;

int n, m, ans;
int a[Maxn][Maxn];
int f[Maxn][Maxn][2];

// [0] 1 0 0  [1] 0 0 1
//     0 1 0      0 1 0
//     0 0 1      1 0 0

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= m; ++j)
			scanf("%d", &a[i][j]);
	for(int j = 1; j <= m; ++j)
	{
		for(int i = 1; i <= n; ++i)
		{
			if(!a[i][j]) f[i][j][0] = f[i][j][1] = 0;
			else
			{
				f[i][j][0] = f[i-1][j-1][0]+1;
				f[i][j][1] = f[i+1][j-1][1]+1;
				ans = max(ans, max(f[i][j][0], f[i][j][1]));
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
