#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int Maxn = 5e5+7;
const int Maxm = 2e6+7;

int n, m, k, ans;
int du[Maxn], u[Maxm], v[Maxm], fir[Maxn], nex[Maxm];
int dfn[Maxn], low[Maxn], col[Maxn], _dfn, _col;
int vis[Maxn], num[Maxn], q[Maxn], tail;
int du_col[Maxn];

struct Node
{
    int v, id;
    bool operator < (const Node &b) const { return v > b.v; }
} a[Maxn];

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
        int sum = 0;
        _col++;
        do
        {
            sum++;
            col[q[tail]] = _col;
            vis[q[tail]] = 0;
        } while(q[tail--] != cur);
        num[_col] = sum;
    }
}

int main()
{
    read(n); read(m); read(k);
    for(int i = 1; i <= n; ++i) scanf("%d", &a[i].v), a[i].id = i;
    for(int i = 1; i <= m; ++i)
    {
        read(u[i]); read(v[i]);
        nex[i] = fir[u[i]];
        fir[u[i]] = i;
        du[v[i]]++;
    }

    for(int i = 1; i <= n; ++i)
        if(!dfn[i]) tarjan(i);
    for(int i = 1; i <= m; ++i)
    {
        int cu = col[u[i]], cv = col[v[i]];
        if(cu != cv) du_col[cv]++;
    }

#ifdef DEBUG
    for(int i = 1; i <= n; ++i)
        printf("col[%d]=%d\n", i, col[i]);
    for(int i = 1; i <= _col; ++i)
        printf("du[%d]=%d\n", i, du_col[i]);
#endif

    sort(a+1, a+n+1);
    for(int i = 1, cnt = 0, now; i <= n; ++i)
    {
        now = a[i].id;
        if(!du[now]) continue;
        if(du_col[col[now]] || --num[col[now]])
        {
#ifdef DEBUG
            printf("%d %d\n", col[now], num[col[now]]);
#endif
            ans += a[i].v;
            if(++cnt == k) break;
        }
    }
    printf("%d\n", ans);
    return 0;
}
