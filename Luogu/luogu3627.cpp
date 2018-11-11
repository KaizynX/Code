#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e5+7;

int n, m, s, p;
int a[Maxn], w[Maxn], bar_p[Maxn], bar_c[Maxn];
int ver[Maxn], fir[Maxn], nex[Maxn];
int dfn[Maxn], low[Maxn], vis[Maxn], col[Maxn], _col, _dfn;
int stk[Maxn], sz;

void tarjan(int cur)
{
    dfn[cur] = low[cur] = ++_dfn;
    vis[cur] = 1;
    stk[++sz] = cur;
    for(int i = fir[cur], to; i; i = nex[i])
    {
        to = ver[i];
        if(!dfn[to])
        {
            tarjan(to);
            low[cur] = min(low[cur], low[to]);
        }
        low[cur] = min(low[cur], dfn[to]);
    }
    if(dfn[cur] == low[cur])
    {
        ++_col;
        do
        {
            if(bar_p[stk[sz]]) bar_c[_col] = 1;
            col[stk[sz]] = _col;
            w[_col] += a[stk[sz]];
        } while(stk[sz--] != cur);
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1, u, v; i <= m; ++i)
    {
        scanf("%d%d", &u, &v);
        ver[i] = v;
        nex[i] = fir[u];
        fir[u] = i;
    }
    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    scanf("%d%d", &s, &p);
    for(int i = 1, b; i <= p; ++i)
    {
        scanf("%d", &b);
        bar_p[b] = 1;
    }

    for(int i = 1; i <= n; ++i)
        if(!dfn[i]) tarjan(i);
    return 0;
}
