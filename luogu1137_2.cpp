#include <cstdio>
#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;

int n, m, v[Maxn];
bitset<Maxn> b[Maxn];
vector<int> e[Maxn];

void dfs(int cur)
{
	if(v[cur]) return;
	for(vector<int>::iterator it = e[cur].begin(); it != e[cur].end(); ++it)
	{
		dfs(*it);
		b[cur] |= b[*it];
	}
	v[cur] = true;
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
		printf("%d\n", b[i].count());
	}
	return 0;
}
