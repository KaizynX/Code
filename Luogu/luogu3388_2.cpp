#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e4+7;
const int Maxm = 1e5+7;

int n, m, ans;
int dfn[Maxn], low[Maxn], flag[Maxn], cnt;
vector<int> e[Maxn];

void tarjan(int cur, int fa)
{
	int cld = 0;
	dfn[cur] = low[cur] = ++cnt;
	for(vector<int>::iterator it = e[cur].begin(); it != e[cur].end(); ++it)
	{
		if(!dfn[*it])
		{
			cld++;
			tarjan(*it, fa);
			low[cur] = min(low[cur], low[*it]);
			if(cur != fa && low[*it] >= dfn[cur])
				flag[cur] = 1;
		}
		low[cur] = min(low[cur], dfn[*it]);
	}
	if(cur == fa && cld >= 2)
		flag[cur] = 1;
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1, u, v; i <= m; ++i)
	{
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
		e[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) tarjan(i, i);

	for(int i = 1; i <= n; ++i)
		if(flag[i]) ans++;
	printf("%d\n", ans);
	for(int i = 1; i <= n; ++i)
		if(flag[i]) printf("%d ", i);
	return 0;
}
