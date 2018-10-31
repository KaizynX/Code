#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e3+7;
const int Maxv = 2e4+7;
const int MOD = 998244353;

int n, ans, maxv, minv = Maxv;
int a[Maxn];
vector<int> v[Maxv];

void dfs(int last, int d)
{
	if(++ans >= MOD) ans -= MOD;
	int now = a[last]+d;
	if(now < minv || now > maxv || !v[now].size()) return;
	for(vector<int>::iterator it = v[now].begin(); it != v[now].end(); ++it)
		if(*it > last) dfs(*it, d);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
	{
		scanf("%d", a+i);
		maxv = max(maxv, a[i]);
		minv = min(minv, a[i]);
		v[a[i]].push_back(i);
	}
	ans += n;
	for(int i = 1; i < n; ++i)
		for(int j = i+1; j <= n; ++j)
			dfs(j, a[j]-a[i]);
	printf("%d\n", ans);
    return 0;
}
