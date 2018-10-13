#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e4+7;
const int Maxm = 5e4+7;

int n, m, ans;
int dfn[Maxn], low[Maxn], _dfn;
int vis[Maxn], stk[Maxn], sz;
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
		int num = 0;
		do
		{
			vis[stk[sz]] = 0;
			++num;
		} while(cur != stk[sz--]);
		if(num > 1) ans++;
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1, u, v; i <= m; ++i)
	{
		scanf("%d%d", &u, &v);
		e[u].push_back(v);
	}
	for(int i = 1; i <= n; ++i)
		if(!dfn[i]) tarjan(i);
	printf("%d\n", ans);
	return 0;
}
