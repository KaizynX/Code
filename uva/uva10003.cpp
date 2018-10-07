#include <cstdio>
#include <iostream>

using namespace std;

const int Maxl = 1e3+7;
const int Maxn = 60;
const int INF = 0x3f3f3f3f;

int L, n;
int a[Maxn];
int f[Maxn][Maxn];

int main()
{
	while(scanf("%d", &L) && L)
	{
		scanf("%d", &n);
		for(int i = 1; i <= n; ++i)
			scanf("%d", a+i);
		a[0] = 0; a[n+1] = L;
		for(int len = 2; len <= n+1; ++len)
			for(int i = 0, j; i+len <= n+1; ++i)
			{
				j = i+len;
				f[i][j] = INF;
				for(int k = i+1; k < j; ++k)
					f[i][j] = min(f[i][j], f[i][k]+f[k][j]+a[j]-a[i]);
			}
		printf("The minimum cutting is %d.\n", f[0][n+1]);
	}
	return 0;
}
