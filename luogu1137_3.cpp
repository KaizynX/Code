#include <cstdio>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;

int n, m, f[Maxn];
vector<int> e[Maxn];

bitset<Maxn> dfs(int cur)
{
	if(f[cur]) return;
	bitset<Maxn> now;
	now[cur] = 1;
	for(vector<int>::iterator it = e[cur].begin(); it != e[cur].end(); ++it)
		now[cur] |= dfs(*it);
	f[cur] = now.count();
	return now;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++i) b[i][i] = 1;
	for(int i = 0, x, y; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		e[y].push_back(x);
	}
	for(int i = 1; i <= n; ++i)
	{
		dfs(i);
		printf("%d\n", f[i]);
	}
	return 0;
}
