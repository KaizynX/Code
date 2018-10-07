#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 3e3+7;

int n, m;
int tot, ver[Maxn<<1], fir[Maxn], nex[Maxn<<1];
int cnt, vis[Maxn], close[Maxn];
int head, tail, q[Maxn];

inline void add(int u, int v)
{
    ver[++tot] = v;
    nex[tot] = fir[u];
    fir[u] = tot;
}

void bfs(int root)
{
    int cur;
    cnt = 1;
    memset(vis, 0, sizeof vis);
    head = tail = 0;
    q[++tail] = root;
    vis[root] = true;
    while(head < tail)
    {
        cur = q[++head];
        for(int i = fir[cur], to; i; i = nex[i])
        {
            to = ver[i];
            if(vis[to] || close[to]) continue;
            q[++tail] = to;
            vis[to] = true;
            ++cnt;
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 0, u, v; i < m; ++i)
    {
        scanf("%d%d", &u, &v);
        add(u, v);
        add(v, u);
    }
    for(int i = 0, a; i < n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            if(!close[j])
            {
                bfs(j);
                break;
            }
        puts(cnt == n-i ? "YES" : "NO");
        scanf("%d", &a);
        close[a] = true;
    }
    return 0;
}
