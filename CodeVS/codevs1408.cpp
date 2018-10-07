#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 3e3 + 7;

int n, ans;
int a[Maxn], b[Maxn];
int f[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	for(int i = 1; i <= n; ++i) scanf("%d", b+i);
	for(int i = 1, maxl; i <= n; ++i)
	{
		maxl = 0;
		for(int j = 1; j <= n; ++j)
		{
			if(a[i] > b[j]) maxl = max(maxl, f[i-1][j]);
			if(a[i] == b[j]) f[i][j] = maxl + 1;
			else f[i][j] = f[i-1][j];
		}
	}
	for(int i = 1; i <= n; ++i) ans = max(ans, f[n][i]);
	printf("%d\n", ans);
	return 0;
}
