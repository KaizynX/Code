#include <bits/stdc++.h>

using namespace std;

const int Maxn = 5e5+7;
const int Maxm = 2e6+7;
const int INF = 0x3f3f3f3f;

int n, m, k, ans, a[Maxn];
int du[Maxn], u[Maxm], v[Maxm], fir[Maxn], nex[Maxm];
int dfn[Maxn], low[Maxn], col[Maxn], _dfn, _col;
int vis[Maxn], q[Maxn], tail;
int du_col[Maxn], minv[Maxn];

inline void read(int &x)
{
    char c;
    while(!isdigit((c=getchar())));
    x = c-'0';
    while(isdigit((c=getchar())))
        x = (x<<1)+(x<<3) + c-'0';
}

void tarjan(int cur)
{
    dfn[cur] = low[cur] = ++_dfn;
    vis[cur] = 1;
    q[++tail] = cur;
    for(int i = fir[cur], to; i; i = nex[i])
    {
        to = v[i];
        if(!dfn[to])
        {
            tarjan(to);
            low[cur] = min(low[cur], low[to]);
        }
        else if(vis[to])
            low[cur] = min(low[cur], dfn[to]);
    }
    if(low[cur] == dfn[cur])
    {
        _col++;
        do
        {
            col[q[tail]] = _col;
            vis[q[tail]] = 0;
            if(a[q[tail]] < a[minv[_col]]) minv[_col] = q[tail];
        } while(q[tail--] != cur);
    }
}

int main()
{
    read(n); read(m); read(k);
    for(int i = 1; i <= n; ++i) scanf("%d", a+i);
    for(int i = 1; i <= m; ++i)
    {
        read(u[i]); read(v[i]);
        nex[i] = fir[u[i]];
        fir[u[i]] = i;
        du[v[i]]++;
    }

    a[0] = INF;
    for(int i = 1; i <= n; ++i)
        if(!dfn[i]) tarjan(i);
    for(int i = 1; i <= m; ++i)
    {
        int cu = col[u[i]], cv = col[v[i]];
        if(cu != cv) du_col[cv]++;
    }
    for(int i = 1; i <= _col; ++i)
        if(!du_col[i]) a[minv[i]] = 0;

    nth_element(a+1, a+n+1-k, a+n+1);
    reverse(a+1, a+n+1);
    for(int i = 1; i <= k; ++i) ans += a[i];
    printf("%d\n", ans);
    return 0;
}
