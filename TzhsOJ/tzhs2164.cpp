#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

const int Maxn = 1e3+7;
const int Maxm = 1e4+7;

int n, m, k, ans;
int fa[Maxn];

struct Node
{
    int x, y, v;
    bool operator < (const Node &b) const
    {
        return v < b.v;
    }
} e[Maxm];

inline int getf(int s)
{
    return fa[s] == s ? s : fa[s] = getf(fa[s]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    if(n == k)
    {
        puts("0");
        return 0;
    }
    if(n < k || n-m > k)
    {
        puts("No Answer");
        return 0;
    }
    for(int i = 0; i < m; ++i) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].v);
    for(int i = 1; i <= n; ++i) fa[i] = i;
    sort(e, e+m);
    for(int i = 0, fx, fy; i < m; ++i)
    {
        fx = getf(e[i].x); fy = getf(e[i].y);
        if(fx != fy)
        {
            fa[fx] = fy;
            ans += e[i].v;
            if(--n <= k)
            {
                printf("%d\n", ans);
                return 0;
            }
        }
    }
    puts("No Answer");
    return 0;
}
