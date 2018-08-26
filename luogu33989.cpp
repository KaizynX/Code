#include <cmath>
#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e5+7;

int n, m;
double a[Maxn];

struct Tree
{
    int l, r;
    double v, tag;
    Tree(){ l = 0; r = 0; v = 0; tag = 1; }
} tr[Maxn<<2];

inline void build_tree(int, int, int);
inline void update_tree(int, int, int, double);
inline double query_tree(int, int, int);
inline int ls(int x) { return x<<1; }
inline int rs(int x) { return x<<1|1; }
inline void pushup(int i) { tr[i].v = tr[ls(i)].v*tr[rs(i)].v; }
inline void pushdown(int);

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i) scanf("%lf", a+i);
    build_tree(1, 1, n);
    for(int i = 1, op, x, y; i <= m; ++i)
    {
        scanf("%d %d %d", &op, &x, &y);
        if(op == 0) printf("%.6f\n", query_tree(1, x, y));
        else
        {
            double t; scanf("%lf", &t);
            update_tree(1, x, y, t);
        }
    }
    return 0;
}

inline void build_tree(int i, int l, int r)
{
    if(l == r) { tr[i].v = 1.0-a[l]; return; }
    int mid = (l+r)>>1;
    build_tree(ls(i), l, mid);
    build_tree(rs(i), mid+1, r);
    pushup(i);
}

inline void pushdown(int i)
{
    int len = tr[i].r-tr[i].l+1;
    tr[ls(i)].tag *= tr[i].tag;
    tr[rs(i)].tag *= tr[i].tag;
    tr[ls(i)].v *= pow(tr[i].tag, len/2);
    tr[rs(i)].v *= pow(tr[i].tag, (len+1)/2);
    tr[i].tag = 1;
}

inline void update_tree(int i, int l, int r, double t)
{
    if(tr[i].l >= l && tr[i].r <= r)
    {
        tr[i].v *= pow(tr[i])
    }
}
