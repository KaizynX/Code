#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e6+7;
const int INF = 1e9;

int n, w;
long long res[MAXN];

struct SegmentTree
{
    typedef int T;
    struct Node
    {
        int l, r, id = 0;
        T lazy = -INF;
    } tr[MAXN<<2];
    
    inline void push_down(int i, int id)
    {
        if (tr[i].l == tr[i].r) return;
        tr[i<<1].lazy = max(tr[i<<1].lazy, tr[i].lazy);
        tr[i<<1|1].lazy = max(tr[i<<1|1].lazy, tr[i].lazy);
    }

    void build(int i, int l, int r)
    {
        tr[i].l = l; tr[i].r = r;
        if (l == r) return;
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
    }

    void update(int i, int l, int r, T v, int id)
    {
        if (tr[i].id != id) {
            push_down(i);
            if (tr[i].l == tr[i].r) {
                res[tr[i].l] += tr[i].lazy;
            }
            tr[i].lazy = -INF;
        }
        tr[i].id = id;
        if (tr[i].l >= l && tr[i].r <= r) {
            tr[i].lazy = max(tr[i].lazy, v);
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(i<<1  , l, r, v, id);
        if (r >  mid) update(i<<1|1, l, r, v, id);
    }

    T query(int i, int x)
    {
        if (tr[i].l == tr[i].r) return tr[i].lazy;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) return query(i<<1, x);
        else return query(i<<1|1, x);
    }
} ST;

int main()
{
    scanf("%d%d", &n, &w);
    ST.build(1, 1, w);
    for (int i = 1, l, a; i <= n; ++i) {
        scanf("%d", &l);
        for (int j = 1; j <= l; ++j) {
            scanf("%d", &a);
            ST.update(1, j, j+(w-l), a, i);
        }
        if (l < w) {
            ST.update(1, 1, (w-l), 0, i);
            ST.update(1, l+1, w, 0, i);
        }
    }
    for (int i = 1; i <= w; ++i) {
        res[i] += ST.query(1, i);
        printf("%lld ", res[i]);
    }
    putchar('\n');
    return 0;
}
