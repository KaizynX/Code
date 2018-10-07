#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;

int n, m;
int f[Maxn];
vector<int> e[Maxn];

int dfs(int cur)
{
	if(f[cur]) return f[cur];
	f[cur] = 1;
	for(vector<int>::iterator it = e[cur].begin(); it != e[cur].end(); ++it)
		f[cur] += dfs(*it);
	return f[cur];
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 0, x, y; i < m; ++i)
	{
		scanf("%d%d", &x, &y);
		e[y].push_back(x);
	}
	for(int i = 1; i <= n; ++i)
		printf("%d\n", dfs(i));
	return 0;
}
