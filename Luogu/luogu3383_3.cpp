#pragma GCC diagnostic error "-std=c++11" 
#include <bits/stdc++.h>

using namespace std;

const int Maxn = 2e4+7;
const int Maxm = 1e5+7;

int n, m, ans;
int dfn[Maxn], low[Maxn], _dfn, flag[Maxn];
vector<int> e[Maxn];

void tarjan(int cur, int fa)
{
    dfn[cur] = low[cur] = ++_dfn;
    int child = 0;
    for(auto i : e[cur])
    {
        if(!dfn[i])
        {
            child++;
            tarjan(i, fa);
            low[cur] = min(low[cur], low[i]);
            if(cur != fa && low[i] >= dfn[cur]) flag[cur] = 1;
        }
        low[cur] = min(low[cur], dfn[i]);
    }
    if(cur == fa && child >= 2) flag[cur] = 1;
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
