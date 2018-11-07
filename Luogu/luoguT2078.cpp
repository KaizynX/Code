#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, k;
int a[Maxn], b[Maxn], id[Maxn], vis[Maxn];

void dfs(int cur, int cnt)
{
    if(vis[cur])
    {
        int nex = k%cnt;
        for(int i = 0; i < cnt; ++i)
            b[id[(i+nex)%cnt]] = id[i];
        return;
    }
    vis[cur] = 1;
    id[cnt] = cur;
    dfs(a[cur], cnt+1);
}

int main()
{
    scanf("%d%d", &n, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d", a+i);
    for(int i = 1; i <= n; ++i)
        if(!vis[i]) dfs(i, 0);
    for(int i = 1; i <= n; ++i)
        printf("%d ", b[i]);
    return 0;
}
