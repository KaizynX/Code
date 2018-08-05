#include <iostream>
#include <cassert>
#define DEBUG

using namespace std;

const int Maxn = 1e5+7;

int n, sum, c[Maxn], s[Maxn], maxs[Maxn];
int e[Maxn<<1], d[Maxn<<1], fir[Maxn], nex[Maxn<<1], tot;

inline void add(int u, int v, int a)
{
    e[++tot] = v;
    d[tot] = a;
    nex[tot] = fir[u];
    fir[u] = tot;
}

void treedp(int cur, int fa)
{
    s[cur] = c[cur];
    for(int i = fir[cur]; i; i = nex[i])
    {
        if(e[i] == fa) continue;
        treedp(e[i], cur);
        s[cur] += s[e[i]];
        maxs[cur] = max(maxs[cur], s[e[i]]);
    }
    maxs[cur] = max(maxs[cur], sum-s[cur]);
}

long long dfs(int cur, int fa, int depth)
{
    long long res = (long long)c[cur]*depth;
    for(int i = fir[cur]; i; i = nex[i])
    {
        if(e[i] != fa)
            res += dfs(e[i], cur, depth+d[i]);
    }
    return res;
}

int main()
{
#ifdef DEBUG
    freopen("testdata.in", "r", stdin);
#endif
    ios::sync_with_stdio(false);
#ifndef DEBUG
    cin.tie(NULL);
    cout.tie(NULL);
#endif
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> c[i];
        sum += c[i];
    }
    for(int i = 1, u, v, a; i < n; ++i)
    {
#ifdef DEBUG
        assert(cin >> u >> v >> a);
#elif
        cin >> u >> v >> a;
#endif
        add(u, v, a);
        add(v, u, a);
    }
    treedp(1, 0);
    int root = 1;
    for(int i = 2; i <= n; ++i)
    {
        if(maxs[i] < maxs[root])
            root = i;
    }
    cout << dfs(root, 0, 0) << endl;
    return 0;
}
