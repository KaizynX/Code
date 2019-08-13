#include <bits/stdc++.h>

using namespace std;

const int Maxn =  2e3+7;

int T, n, m;
int posx[Maxn], f[Maxn];
long long res;

struct Point
{
    int x, y, w, xx, yy;
} a[Maxn];

inline bool cmpx(const Point &p1, const Point &p2) { return p1.x < p2.x; }
inline bool cmpy(const Point &p1, const Point &p2) { return p1.y < p2.y; }

struct Tree
{
    int l, r;
    long long s = 0, ls = 0, rs = 0, ms = 0;
} tr[Maxn<<2];

inline void push_up(int i)
{
    tr[i].s = tr[i<<1].s+tr[i<<1|1].s;
    tr[i].ls = max(tr[i<<1].ls, tr[i<<1].s+tr[i<<1|1].ls);
    tr[i].rs = max(tr[i<<1|1].rs, tr[i<<1|1].s+tr[i<<1].rs);
    tr[i].ms = max(tr[i<<1].rs+tr[i<<1|1].ls, max(tr[i<<1].ms, tr[i<<1|1].ms));
}

void build_tree(int i, int l, int r)
{
    tr[i].l = l; tr[i].r = r;
    tr[i].s = tr[i].ls = tr[i].rs = tr[i].ms = 0;
    if (l == r) {
        f[l] = i;
        return;
    }
    int mid = (l+r)/2;
    build_tree(i<<1, l, mid);
    build_tree(i<<1|1, mid+1, r);
}

inline void update_leaf(int i, int w)
{
    tr[i].ls = tr[i].rs = tr[i].ms = (tr[i].s += w);
}

void update_tree(int y, int w)
{
    int i = f[y];
    update_leaf(i, w);
    for(i >>= 1 ; i; i >>= 1)
        push_up(i);
}

int main()
{
    scanf("%d", &T);
    while(T--) {
        res = 0;
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d%d%d", &a[i].x, &a[i].y, &a[i].w);

        sort(a+1, a+n+1, cmpy);
        a[1].yy = 1;
        for(int i = 2; i <= n; ++i)
            a[i].yy = a[i-1].yy+(a[i].y == a[i-1].y ? 0 : 1);
        m = a[n].yy;

        sort(a+1, a+n+1, cmpx);
        a[1].xx = 1;
        for(int i = 2; i <= n; ++i)
            a[i].xx = a[i-1].xx+(a[i].x == a[i-1].x ? 0 : 1);
        for(int i = 1; i <= a[n].xx; ++i)
            posx[i] = 0;
        for(int i = 1; i <= n; ++i)
            if (!posx[a[i].xx]) posx[a[i].xx] = i;
        posx[a[n].xx+1] = n+1;

        // i -> up x, j -> down x
        for(int i = 1; i <= a[n].xx; ++i) {
            build_tree(1, 1, m);
            for(int j = i; j <= a[n].xx; ++j) {
                for(int k = posx[j]; k < posx[j+1]; ++k)
                    update_tree(a[k].yy, a[k].w);
                res = max(res, tr[1].ms);
            }
        }
        printf("%lld\n", res);
    }
    return 0;
}
