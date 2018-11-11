#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 5e5+7;

int n, m, s, p, ans;
int a[Maxn], w[Maxn], bar_p[Maxn], bar_c[Maxn];
int u[Maxn], v[Maxn];
vector<int> pe[Maxn], ce[Maxn];
int dfn[Maxn], low[Maxn], vis_p[Maxn], col[Maxn], _col, _dfn;
int stk[Maxn], sz;
int vis_c[Maxn], mem[Maxn];

void tarjan(int cur)
{
    dfn[cur] = low[cur] = ++_dfn;
    vis_p[cur] = 1;
    stk[++sz] = cur;
    for(vector<int>::iterator it = pe[cur].begin(); it != pe[cur].end(); ++it)
    {
        if(!dfn[*it])
        {
            tarjan(*it);
            low[cur] = min(low[cur], low[*it]);
        }
        if(vis_p[*it]) low[cur] = min(low[cur], dfn[*it]);
    }
    if(dfn[cur] == low[cur])
    {
        ++_col;
        do
        {
            if(bar_p[stk[sz]]) bar_c[_col] = 1;
            col[stk[sz]] = _col;
            w[_col] += a[stk[sz]];
            vis_p[stk[sz]] = 0;
        } while(stk[sz--] != cur);
    }
}

inline void suo_dian()
{
    for(int i = 1, cu, cv; i <= m; ++i)
    {
        cu = col[u[i]]; cv = col[v[i]];
        if(cu == cv) continue;
        ce[cu].push_back(cv);
    }
}

int dfs(int cur)
{
    if(vis_c[cur]) return (mem[cur] || bar_c[cur]) ? mem[cur]+w[cur] : 0;
    vis_c[cur] = 1;
    for(vector<int>::iterator it = ce[cur].begin(); it != ce[cur].end(); ++it)
        if(!vis_c[*it])
            mem[cur] = max(mem[cur], dfs(*it));
    return (mem[cur] || bar_c[cur]) ? mem[cur]+w[cur] : 0;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d%d", u+i, v+i);
        pe[u[i]].push_back(v[i]);
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
    suo_dian();
#ifdef DEBUG
    for(int i = 1; i <= n; ++i)
        printf("%d ", dfn[i]);
    putchar('\n');
    for(int i = 1; i <= n; ++i)
        printf("%d ", col[i]);
    putchar('\n');
    for(int i = 1; i <= _col; ++i)
        printf("%d ", w[i]);
    putchar('\n');
    for(int i = 1; i <= _col; ++i)
        printf("%d ", bar_c[i]);
    putchar('\n');
#endif
    printf("%d\n", dfs(col[s]));
    return 0;
}
