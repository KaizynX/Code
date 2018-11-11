#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 307;

long long ans;
int n, tot;
int h[Maxn], fa[Maxn];

struct Edge
{
    int x, y, v;
    bool operator < (const Edge &b) const
    {
        return v > b.v;
    }
} e[Maxn*Maxn];

int getf(int s)
{
    return s == fa[s] ? s : fa[s] = getf(fa[s]);
}

int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        scanf("%d", h+i);
        for(int j = 0; j < i; ++j)
        {
            e[++tot].v = abs(h[i]-h[j]);
            e[tot].x = i;
            e[tot].y = j;
        }
    }

    sort(e+1, e+tot+1);
    for(int i = 0; i <= n; ++i) fa[i] = i;
    for(int i = 1, cnt; i <= tot; ++i)
    {
        int fx = getf(e[i].x), fy = getf(e[i].y);
        if(fx != fy)
        {
            fa[fx] = fy;
            ans += e[i].v*e[i].v;
            if(++cnt == n) break;
        }
    }
    printf("%lld\n", ans);
    return 0;
}
