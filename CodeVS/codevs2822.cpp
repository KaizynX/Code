#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e4+7;
const int Maxm = 5e4+7;

int n, m;
int dfn[Maxn], low[Maxn], col[Maxn], _dfn, _col;
int vis[Maxn], stk[Maxn], sz, num[Maxn], du[Maxn];
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
    for(int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        e[u].push_back(v);
    }

    for(int i = 1; i <= n; ++i)
        if(!dfn[i]) tarjan(i);

	int res = 0;
	for(int i = 1; i <= _col; ++i)
		if(num[i] > 1) res++;
	printf("%d\n", res);

    for(int i = 1; i <= n; ++i)
        for(vector<int>::iterator it = e[i].begin(); it != e[i].end(); ++it)
            if(col[i] != col[*it]) du[col[i]]++;

	int ans, ans_num = 0;
    for(int i = 1; i <= _col; ++i)
        if(!du[i]) ans_num++, ans = i;
    if(ans_num == 1 && num[ans] > 1)
	{
		for(int i = 1; i <= n; ++i)
			if(col[i] == ans) printf("%d ", i);
	}
    else puts("-1");
    return 0;
}
