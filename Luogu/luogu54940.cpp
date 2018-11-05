#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e6+7;
const int MOD = 1e8+7;

int n, T;
int tot, ver[Maxn<<1], fir[Maxn], nex[Maxn<<1];
struct Tree
{
    long long k, v;
} tr[Maxn];

inline void add_edge(int u, int v)
{
    ver[++tot] = v; nex[tot] = fir[u]; fir[u] = tot;
}

inline int _pow(int x)
{
    return T == 0 ? 1 : x;
}

void exgcd(int a, int b, int &x, int &y)
{
    if(!b) { x = 1; y = 0; return; }
    exgcd(b, a%b, y, x);
    y -= a/b*x;
}

inline int mul_inverse(int a)
{
    int x, y;
    exgcd(a, MOD, x, y);
    return (x%MOD+MOD)%MOD;
}

void treedp(int cur, int fa)
{
    int child = 0;
    Tree &now = tr[cur];
    now.k = 1;
    for(int i = fir[cur], to; i; i = nex[i])
    {
        to = ver[i];
        if(to == fa) continue;
        child++;
        treedp(to, cur);
        now.k = (now.k*tr[to].k)%MOD;
    }
    if(!child)
    {
        now.k = 2;
        now.v = _pow(cur);
        return;
    }
    for(int i = fir[cur], to; i; i = nex[i])
    {
        to = ver[i];
        if(to == fa) continue;
        now.v = (now.v+tr[to].v*mul_inverse(tr[to].k))%MOD;
    }
    now.v = (now.v*now.k)%MOD;
    now.k++;
    now.v += _pow(cur);
}

int main()
{
    scanf("%d%d", &n, &T);
    for(int i = 1, u, v; i < n; ++i)
    {
        scanf("%d%d", &u, &v);
        add_edge(u, v);
        add_edge(v, u);
    }
    treedp(1, 0);
    printf("%d\n", (int)(tr[1].v%MOD));
    return 0;
}
