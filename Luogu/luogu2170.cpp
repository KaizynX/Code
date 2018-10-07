#include <iostream>

using namespace std;

const int Maxn = 2e4+7;

int n, m, k, ans;
int fa[Maxn], num[Maxn];
int f[Maxn], a[Maxn], cnt;

int getf(int s)
{
    return fa[s] == s ? s : fa[s] = getf(fa[s]);
}

inline void init()
{
    for(int i = 1; i <= n; ++i)
    {
        fa[i] = i;
        num[i] = 1;
    }
}

inline void co(int u, int v)
{
    int fu = getf(u), fv = getf(v);
    if(fu == fv) return;
    if(num[fu] >= num[fv])
    {
        fa[fv] = fu;
        num[fu] += num[fv];
    }
    else
    {
        fa[fu] = fv;
        num[fv] += num[fu];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m >> k;
    init();
    for(int i = 0, u, v; i < k; ++i)
    {
        cin >> u >> v;
        co(u, v);
    }
    for(int i = 1; i <= n; ++i)
    {
        if(getf(i) == i)
            a[++cnt] = num[i];
    }
    for(int i = 1; i <= cnt; ++i)
    {
        for(int v = m; v >= a[i]; --v)
            f[v] = max(f[v], f[v-a[i]]+a[i]);
    }
    ans = f[m];
    for(int i = 1; i <= n; ++i) f[i] = n;
    for(int i = 1; i <= cnt; ++i)
    {
        for(int v = m; v <= n-a[i]; ++v)
            f[v] = min(f[v], f[v+a[i]]-a[i]);
    }
    if(f[m]-m < m-ans) ans = f[m];
    cout << ans << endl;
    return 0;
}
