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
    inline void calc(int x)
    {
        y = (long long)x*ki+b;
    }
} a[Maxn];

struct Point
{
    int i, j, x;
    inline void calc()
    {
        if(a[i].ki == a[j].ki) --tot;
        else x = floor((double)(a[i].b-a[j].b)/(a[j].ki-a[i].ki));
    }
    bool operator < (const Point &b) const
    {
        return x < b.x;
    }
} p[Maxn*Maxn/2];

struct Query
{
    int x, num;
    bool operator < (const Query &b) const
    {
        return x < b.x;
    }
} q[Maxm];

inline bool cmp(int i, int j)
{
    return a[i].y < a[j].y;
}

template <typename T> inline void read(T &x)
{
    char c; T tag = 1;
    while((c=getchar()) < '0' || c > '9') if(c == '-') tag = -1;
    x = c-'0';
    while((c=getchar()) >= '0' && c <= '9') x = (x<<1)+(x<<3) + c-'0';
    x *= tag;
}

template <typename T> void put(T x)
{
    if(x < 0)
    {
        putchar('-');
        x = -x;
    }
    if(x/10) put(x/10);
    putchar(x%10+'0');
}

inline void _swap(int i, int j)
{
    int ri = a[i].rank, rj = a[j].rank;
    swap(r[ri], r[rj]);
    swap(a[i].rank, a[j].rank);
}

int main()
{
    read(n); read(m); read(k);
    for(int i = 1; i <= n; ++i)
        read(a[i].ki), read(a[i].b);
    for(int i = 1; i <= m; ++i)
        read(q[i].x), q[i].num = i;
    sort(q+1, q+m+1);
    for(int i = 1; i < n; ++i)
        for(int j = i+1; j <= n; ++j)
        {
            p[++tot].i = i; p[tot].j = j;
            p[tot].calc();
        }
    sort(p+1, p+tot+1);
    for(int i = 1; i <= n; ++i)
        a[i].calc(p[1].x-1), r[i] = i;
    sort(r+1, r+n+1, cmp);
    for(int i = 1; i <= n; ++i)
        a[r[i]].rank = i;
    for(int i = 1, cur = 1; i <= m; ++i)
    {
        while(cur <= tot && p[cur].x < q[i].x)
            _swap(p[cur].i, p[cur].j), ++cur;
        a[r[k]].calc(q[i].x);
        res[q[i].num] = a[r[k]].y;
    }
    for(int i = 1; i <= m; ++i)
        put(res[i]), putchar('\n');
    return 0;
}
