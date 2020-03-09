#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

template <typename T>
struct SegmentTree
{
    int sz;
    T tr[N<<2], lazy[N<<2], tag[N<<2];
    SegmentTree(){}
    void build(const int &n, const T &k = 0) { sz = n; _build(1, n, k); }
    template <typename TT>
    void build(const TT a[], const int &n) { sz = n; _build(a, 1, n); }
    void update(const int &x, const T &k) { _update(x, x, k, 1, sz); }
    void update(const int &l, const int &r, const T &k) { _update(l, r, k, 1, sz); }
    T query(const int &x) { return _query(x, x, 1, sz); }
    T query(const int &l, const int &r) { return _query(l, r, 1, sz); }
private :
    void push_up(const int &i) { tr[i] = tr[i<<1]+tr[i<<1|1]; }
    void push_down(const int &i, const int &len) {
        if (!tag[i]) return;
        tr[i<<1] = lazy[i]*(len-len/2);
        tr[i<<1|1] = lazy[i]*(len/2);
        lazy[i<<1] = lazy[i<<1|1] = lazy[i];
        tag[i<<1] = tag[i<<1|1] = 1;
        tag[i] = 0;
    }
    void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
        lazy[i] = tag[i] = 0;
        if (l == r) { tr[i] = k; return; }
        int mid = (l+r)>>1;
        _build(l, mid, k, i<<1);
        _build(mid+1, r, k, i<<1|1);
        push_up(i);
    }
    template <typename TT>
    void _build(const TT a[], const int &l, const int &r, const int &i = 1) {
        lazy[i] = tag[i] = 0;
        if (l == r) { tr[i] = a[l]; return; }
        int mid = (l+r)>>1;
        _build(a, l, mid, i<<1);
        _build(a, mid+1, r, i<<1|1);
        push_up(i);
    }
    void _update(const int &l, const int &r, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) {
            tr[i] = k*(trr-trl+1);
            lazy[i] = k;
            tag[i] = 1;
            return;
        }
        push_down(i, trr-trl+1);
        int mid = (trl+trr)>>1;
        if (l <= mid) _update(l, r, k, trl, mid, i<<1);
        if (r >  mid) _update(l, r, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) return tr[i];
        push_down(i, trr-trl+1);
        int mid = (trl+trr)>>1;
        T res = 0;
        if (l <= mid) res += _query(l, r, trl, mid, i<<1);
        if (r >  mid) res += _query(l, r, mid+1, trr, i<<1|1);
        return res;
    }
};

SegmentTree<int> ST;

inline int solve()
{
    int n, q, x, y, z;
    scanf("%d%d", &n, &q);
    ST.build(n, 1);
    while (q--) {
        scanf("%d %d %d", &x, &y, &z);
        ST.update(x, y, z);
    }
    return ST.query(1, n);
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case %d: The total value of the hook is %d.\n", i, solve());
    }
    return 0;
}
