#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;
const int INF = 1e9;

int n, m;
int f[Maxn<<1], lenf;
int v[Maxn<<1], fir[Maxn], nex[Maxn<<1], l[Maxn<<1], r[Maxn<<1], tot;
vector<pair<int, int> > pp[Maxn];
int que[Maxn<<1], tail, head, inqp[Maxn];

inline void add_edge(int u, int v, int l, int r)
{
    v[++tot] = v;
    l[tot] = l; r[tot] = r;
    nex[tot] = fir[u];
    fir[u] = tot;
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1, _u, _v, _l, _r; i <= m; ++i)
    {
        scanf("%d%d%d%d", &_u, &_v, &_l, &_r);
        add_edge(u, v, l, r);
        add_edge(v, u, l, r);
        f[lenf++] = _l;
        f[lenf++] = _r;
    }
    // ÀëÉ¢»¯
    sort(f, f+lenf);
    lenf = unique(f, f+lenf)-f;
    for(int i = 1; i <= tot; ++i)
    {
        l[i] = lower_bound(f, f+lenf, l[i])-f;
        r[i] = lower_bound(f, f+lenf, r[i])-f;
    }
    // bfs
    que[++tail] = 1;
    inq[1] = 1;
    while(head < tail)
    {
        int cur = que[++head];
    }
    return 0;
}
