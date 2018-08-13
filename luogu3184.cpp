#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;
const int Maxm = 2e5+7;

int n, m, ans;
int ver[Maxm], fir[Maxn], nex[Maxm], din[Maxn], dout[Maxn], f[Maxn];

int dfs(int cur)
{
    if(f[cur]) return f[cur];
    for(int i = fir[cur]; i; i = nex[i])
        f[cur] += dfs(ver[i]);
    return f[cur];
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
        dout[u]++;
        din[v]++;
    }
    for(int i = 1; i <= n; ++i)
        if(!dout[i]) f[i] = 1;
    for(int i = 1; i <= n; ++i)
        if(!din[i] && dout[i]) ans += dfs(i);
    printf("%d\n", ans);
    return 0;
}
