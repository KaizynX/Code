#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, dfn;
long long ans, v[Maxn];
int d[Maxn], t[Maxn], vis[Maxn];

void dfs(int cur, long long sum)
{
    if(vis[cur])
    {
        if(vis[cur] == dfn)
            ans = max(ans, sum-v[cur]);
        return;
    }
    vis[cur] = dfn;
    v[cur] = sum;
    dfs(d[cur], sum+t[cur]);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d", d+i, t+i);
    for(int i = 1; i <= n; ++i)
        if(!vis[i]) ++dfn, dfs(i, 0);
    printf("%lld\n", ans);
    return 0;
}
