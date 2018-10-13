#include <bits/stdc++.h>

using namespace std;

const int Maxn = 107;

int n, ans, a[Maxn][Maxn], s[Maxn][Maxn];

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			scanf("%d", &a[i][j]), s[i][j] = s[i][j-1]+a[i][j];
	for(int l = 1; l <= n; ++l)
		for(int r = l; r <= n; ++r)
			for(int i = 1, cur = 0; i <= n; ++i)
				ans = max(ans, (cur = max(0, cur+s[i][r]-s[i][l-1])));
	return printf("%d\n", ans)&0;
}
