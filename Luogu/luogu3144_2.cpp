#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 3e3+7;

int n, m;
int tot, ver[Maxn<<1], fir[Maxn], nex[Maxn<<1];
int cnt, a[Maxn], open[Maxn], res[Maxn], fa[Maxn];

inline void add(int u, int v)
{
    ver[++tot] = v;
    nex[tot] = fir[u];
    fir[u] = tot;
}

int getf(int s)
{
    return fa[s] == s ? s : fa[s] = getf(fa[s]);
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
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", a+i);
        fa[i] = i;
    }
    for(int i = n, cur; i; --i)
    {
        cur = a[i];
        open[cur] = true;
        cnt++;
        for(int j = fir[cur], to; j; j = nex[j])
        {
            to = ver[j];
            if(!open[to]) continue;
            int fx = getf(cur), fy = getf(to);
            if(fx != fy)
            {
                fa[fx] = fy;
                cnt--;
            }
        }
        res[i] = cnt;
    }
    for(int i = 1; i <= n; ++i)
        puts(res[i] == 1 ? "YES" : "NO");
    return 0;
}
