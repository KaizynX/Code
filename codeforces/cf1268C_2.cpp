#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;

int n;
int a[N], p[N], mv[N], st[N];
long long res[N];

struct SegmengTree
{
    typedef int T;
    struct TreeNode
    {
        int l, r;
        T sum;
    } tr[N<<2];
    void push_up(int i) {
        tr[i].sum = tr[i<<1].sum+tr[i<<1|1].sum;
    }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) {
            tr[i].sum = mv[l];
            return;
        }
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    void update(int i, int p, T x) {
        if (tr[i].l == p && tr[i].r == p) {
            tr[i].sum = x;
            return;
        }
        int mid = (tr[i].l+tr[i].r)>>1;
        if (p <= mid) update(i<<1, p, x);
        else update(i<<1|1, p, x);
        push_up(i);
    }
    T query(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].sum;
        int mid = (tr[i].l+tr[i].r)>>1;
        T res = 0;
        if (l <= mid) res += query(i<<1, l, r);
        if (r >  mid) res += query(i<<1|1, l, r);
        return res;
    }
} ST;

struct BinaryIndexedTree
{
    // set your type
    typedef int T;
    T tr[N];
    BinaryIndexedTree() { memset(tr, 0, sizeof tr); }
    inline void clear() { for (int i = 1; i <= n; ++i) tr[i] = 0; }
    inline void update(int x, T v) { for ( ; x <= n; x += x&-x) tr[x] += v; }
    inline void update(int x, int y, T v) { update(x, v); update(y+1, -v); }
    inline T query(int x) { T res = 0; for ( ; x; x -= x&-x) res += tr[x]; return res; }
    inline T query(int x, int y) { return query(y)-query(x-1); }
} BIT;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        p[a[i]] = i;
    }

    for (int i = 1; i <= n; ++i) {
        st[i] = BIT.query(p[i], n);
        mv[p[i]] = min(st[i], BIT.query(1, p[i]));
#ifdef DEBUG
        cout << "(" << BIT.query(1, p[i]) << ", " << st[i] << ") ";
#endif
        BIT.update(p[i], 1);
        res[i] = res[i-1]+st[i];
    }
    ST.build(1, 1, n);
    for (int i = 1, l = p[1], r = p[1]; i <= n; ++i) {
        ST.update(1, p[i], 0);
        l = min(l, p[i]);
        r = max(r, p[i]);
        res[i] += ST.query(1, l, r);
    }
    for (int i = 1; i <= n; ++i)
        cout << res[i] << " \n"[i==n];
    return 0;
}
