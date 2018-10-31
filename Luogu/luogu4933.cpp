#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const int MOD = 998244353;

int n, ans;
int a[Maxn];

void dfs(int last, int d)
{
	if(++ans >= MOD) ans -= MOD;
	for(int i = last+1; i <= n; ++i)
		if(a[i]-a[last] == d)
			dfs(i, d);
}

int main()
{
	scanf("%d", &n);
	for(int i = 1; i <= n; ++i) scanf("%d", a+i);
	ans += n;
	for(int i = 1; i < n; ++i)
		for(int j = i+1; j <= n; ++j)
			dfs(j, a[j]-a[i]);
	printf("%d\n", ans);
	return 0;
}
