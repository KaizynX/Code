#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 2e3+7;
const int Maxm = 5e5+7;

int n, m, k, tot, r[Maxn];
long long res[Maxm];

struct Line
{
    int ki, b, rank;
    long long y;
    inline long long calc(int x) { return y = (long long)x*ki+b; }
    inline bool operator < (const Line &l) const { return y < l.y; }
} a[Maxn];

struct Point
{
    int i, j, x;
    inline int calc() { return x = (a[i].b-a[j].b)/(a[j].ki-a[i].ki)+1; }
    bool operator < (const Point &b) const { return x == b.x ? i < b.i : x < b.x; }
} p[Maxn*Maxn/2];

struct Query
{
    int x, num;
    bool operator < (const Query &b) const { return x < b.x; }
} q[Maxm];

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d", &a[i].ki, &a[i].b);
    for(int i = 1; i <= m; ++i)
    {
        scanf("%d", &q[i].x);
        q[i].num = i;
    }
    sort(q+1, q+m+1);
    for(int i = 1; i <= n; ++i)
        a[i].calc(p[1].x);
    sort(a+1, a+n+1);
    for(int i = 1; i <= n; ++i)
        a[i].rank = r[i] = i;
    for(int i = 1; i < n; ++i)
        for(int j = i+1; j <= n; ++j)
            if(a[i].ki != a[j].ki && a[i].calc(q[m].x) >= a[j].calc(q[m].x))
            {
                p[++tot].i = i; p[tot].j = j;
                if(p[tot].calc() < q[1].x) --tot;
            }
    sort(p+1, p+tot+1);
    for(int i = 1, cur = 1; i <= m; ++i)
    {
        while(cur <= tot && p[cur].x <= q[i].x)
        {
            a[p[cur].i].rank++;
            a[p[cur].j].rank--;
            r[a[p[cur].i].rank] = p[cur].i;
            r[a[p[cur].j].rank] = p[cur].j;
            cur++;
        }
        res[q[i].num] = a[r[k]].calc(q[i].x);
    }
    for(int i = 1; i <= m; ++i)
        printf("%lld\n", res[i]);
    return 0;
}

