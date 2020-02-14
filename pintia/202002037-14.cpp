#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const long long INF = 1e18;

int n, q;
long long a[N];

struct Node
{
    int l, r;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.l < n2.l;
    }
} b[N];

struct SegmentTree
{
    struct TreeNode
    {
        int l, r;
        long long v, add;
    } tr[N<<2];
    void push_up(int i) { tr[i].v = min(tr[i<<1].v, tr[i<<1|1].v); }
    void push_down(int i) {
        if (!tr[i].add) return;
        tr[i<<1].v += tr[i].add;
        tr[i<<1|1].v += tr[i].add;
        tr[i<<1].add += tr[i].add;
        tr[i<<1|1].add += tr[i].add;
        tr[i].add = 0;
    }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) {
            tr[i].v = a[l];
            tr[i].add = 0;
            return;
        }
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    long long query(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].v;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        long long res = INF;
        if (l <= mid) res = min(res, query(i<<1, l, r));
        if (r >  mid) res = min(res, query(i<<1|1, l, r));
        return res;
    }
    void update(int i, int l, int r, long long k) {
        if (tr[i].l >= l && tr[i].r <= r) {
            tr[i].v += k;
            tr[i].add += k;
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(i<<1, l, r, k);
        if (r >  mid) update(i<<1|1, l, r, k);
        push_up(i);
    }
} ST;

struct SegmenTree
{
    struct TreeNode
    {
        int l, r;
        long long v = INF, add = INF;
    } tr[N<<2];
    void push_up(int i) { tr[i].v = min(tr[i<<1].v, tr[i<<1|1].v); }
    void push_down(int i) {
        if (tr[i].add == INF) return;
        tr[i<<1].v = min(tr[i<<1].v, tr[i].add);
        tr[i<<1|1].v = min(tr[i<<1|1].v, tr[i].add);
        tr[i<<1].add = min(tr[i<<1].add, tr[i].add);
        tr[i<<1|1].add = min(tr[i<<1|1].add, tr[i].add);
        tr[i].add = INF;
    }
    void build(int i, int l, int r) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) return;
        int mid = (l+r)>>1;
        build(i<<1, l, mid);
        build(i<<1|1, mid+1, r);
        push_up(i);
    }
    long long query(int i, int l, int r) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].v;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        long long res = INF;
        if (l <= mid) res = min(res, query(i<<1, l, r));
        if (r >  mid) res = min(res, query(i<<1|1, l, r));
        return res;
    }
    void update(int i, int l, int r, long long k) {
        if (tr[i].l >= l && tr[i].r <= r) {
            tr[i].v = min(tr[i].v, k);
            tr[i].add = min(tr[i].add, k);
            return;
        }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) update(i<<1, l, r, k);
        if (r >  mid) update(i<<1|1, l, r, k);
        push_up(i);
    }
} ST2;

int main()
{
    cin >> n >> q;
    for (int i = 1; i < n; ++i)
        cin >> a[i];
    ST.build(1, 1, n-1);
    ST2.build(1, 1, n-1);
    for (int i = 1; i <= q; ++i) {
        cin >> b[i].l >> b[i].r;
        if (b[i].l > b[i].r) swap(b[i].l, b[i].r);
        ++b[i].l;
        ST2.update(1, b[i].l, b[i].r, b[i].r);
    }
    sort(b+1, b+q+1);
    long long res = 0;
    for (int i = 1; i <= q; ++i) {
        if (ST2.query(1, b[i].l, b[i].r) < b[i].r) continue;
        long long tmp = ST.query(1, b[i].l, b[i].r);
        res += tmp;
        ST.update(1, b[i].l, b[i].r, -tmp);
    }
    cout << res << endl;
    return 0;
}
