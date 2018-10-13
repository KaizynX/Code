#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e3+7;
const int Maxm = 5e4+7;

int n, m, ans, res;
int dfn[Maxn], low[Maxn], col[Maxn], _dfn, _col;
int vis[Maxn], stk[Maxn], sz, num[Maxn];
vector<int> e[Maxn];

void tarjan(int cur)
{
	vis[cur] = 1;
	stk[++sz] = cur;
	dfn[cur] = low[cur] = ++_dfn;

	for(vector<int>::iterator it = e[cur].begin(); it != e[cur].end(); ++it)
	{
		if(!dfn[*it])
		{
			tarjan(*it);
			low[cur] = min(low[cur], low[*it]);
		}
		else if(vis[*it])
			low[cur] = min(low[cur], dfn[*it]);
	}

	if(dfn[cur] == low[cur])
	{
		_col++;
		do
		{
			vis[stk[sz]] = 0;
			col[stk[sz]] = _col;
			num[_col]++;
		} while(cur != stk[sz--]);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1, u, v, t; i <= m; ++i)
	{
		scanf("%d%d%d", &u, &v, &t);
		e[u].push_back(v);
		if(t == 2) e[v].push_back(u);
	}

	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) tarjan(i);

	for(int i = 1; i <= n; ++i)
		if(num[col[i]] > num[ans]) ans = col[i];
	for(int i = 1; i <= n; ++i)
		if(col[i] == ans) ++res;
	printf("%d\n", res);
	for(int i = 1; i <= n; ++i)
		if(col[i] == ans) printf("%d ", i);
	return 0;
}
