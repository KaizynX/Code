#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int Maxn = 8e5+7;
const int INF = 1e8;

int n, m;
int q[2][Maxn], head[2], tail[2];
long long f[Maxn], d[Maxn];

struct Node
{
    int a, b, c, d, k;
    long long v;
    inline void init() { k = min(min(a, b), min(c, d)); }
    bool operator < (const Node &j) const
    {
        if(a != j.a) return a < j.a;
        if(b != j.b) return b < j.b;
        if(c != j.c) return c < j.c;
        return d < j.d;
    }
} x[Maxn];

inline bool cmpa(const Node &i, const Node &j) { return i.a < j.a; }
inline bool cmpb(const Node &i, const Node &j) { return i.b < j.b; }
inline bool cmpc(const Node &i, const Node &j) { return i.c < j.c; }
inline bool cmpd(const Node &i, const Node &j) { return i.d < j.d; }
inline bool cmpk(const Node &i, const Node &j) { return i.k > j.k; }
inline void Discretization();
inline void Delete_same_point();

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        scanf("%d%d%d%d%d", &x[i].a, &x[i].b, &x[i].c, &x[i].d, &x[i].v);
    Discretization();
    Delete_same_point();
    int curi = 1, curk = 0, curd = 0;
    q[0][tail[0]++] = 0;
    while(curi <= n)
    {
        curd++;
        curk = x[curi].k;
        while(curi <= n && x[curi].k == curk)
        {
            q[curd&1][head[curd&1]++] = ++curi;
        }
    }
    return 0;
}

inline void Discretization()
{
    sort(x+1, x+n+1, cmpa);
    x[1].a = 1;
    for(int i = 2, cnt = 1; i <= n; ++i)
    {
        if(x[i].a != x[i-1].a) ++cnt;
        x[i].a = cnt;
    }
    sort(x+1, x+n+1, cmpb);
    x[1].b = 1;
    for(int i = 2, cnt = 1; i <= n; ++i)
    {
        if(x[i].b != x[i-1].b) ++cnt;
        x[i].b = cnt;
    }
    sort(x+1, x+n+1, cmpc);
    x[1].c = 1;
    for(int i = 2, cnt = 1; i <= n; ++i)
    {
        if(x[i].c != x[i-1].c) ++cnt;
        x[i].c = cnt;
    }
    sort(x+1, x+n+1, cmpd);
    x[1].d = 1;
    for(int i = 2, cnt = 1; i <= n; ++i)
    {
        if(x[i].d != x[i-1].d) ++cnt;
        x[i].d = cnt;
    }
}

inline void Delete_same_point()
{
    for(int i = 1; i <= n; ++i) x[i].init();
    sort(x+1, x+n+1);
    for(int i = 2; i <= n; ++i)
    {
        if(x[i].a == x[i-1].a && x[i].b == x[i-1].b && x[i].c == x[i-1].c && x[i].d == x[i-1].d)
        {
            x[i-1].v += x[i].v;
            x[i].k = INF;
        }
    }
    while(x[n].k == INF) n--;
    sort(x+1, x+n+1, cmpk);
}
