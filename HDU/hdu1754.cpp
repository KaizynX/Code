#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int INF = 1e9+7;

template <typename T, typename U = greater<T>>
struct SegmentTree
{
    U cmp = U();
    int n;
    T tr[N<<2], lazy[N<<2], init_val = cmp(0, 1) ? INF : -INF;
    SegmentTree(){}
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
    void build(const int &_n) { n = _n; _build(1, n); }
    template <typename TT>
    void build(const TT a[], const int &_n) { n = _n; _build(a, 1, n); }
    void modify(const int &x, const T &k) { add(x, k-query(x)); }
    void add(const int &x, const T &k) { _add(x, x, k, 1, n); }
    void add(const int &l, const int &r, const T &k) { _add(l, r, k, 1, n); }
    T query(const int &x) { return _query(x, x, 1, n); }
    T query(const int &l, const int &r) { return _query(l, r, 1, n); }
private :
    void push_up(const int &i) { tr[i] = mv(tr[i<<1], tr[i<<1|1]); }
    void push_down(const int &i) {
        if (!lazy[i]) return;
        tr[i<<1] += lazy[i];
        tr[i<<1|1] += lazy[i];
        lazy[i<<1] += lazy[i];
        lazy[i<<1|1] += lazy[i];
        lazy[i] = 0;
    }
    void _build(const int &l, const int &r, const int &i = 1) {
        lazy[i] = 0;
        if (l == r) { tr[i] = 0; return; }
        int mid = (l+r)>>1;
        _build(l, mid, i<<1);
        _build(mid+1, r, i<<1|1);
        push_up(i);
    }
    template <typename TT>
    void _build(const TT a[], const int &l, const int &r, const int &i = 1) {
        lazy[i] = 0;
        if (l == r) { tr[i] = a[l]; return; }
        int mid = (l+r)>>1;
        _build(a, l, mid, i<<1);
        _build(a, mid+1, r, i<<1|1);
        push_up(i);
    }
    void _add(const int &l, const int &r, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) {
            tr[i] += k;
            lazy[i] += k;
            return;
        }
        push_down(i);
        int mid = (trl+trr)>>1;
        if (l <= mid) _add(l, r, k, trl, mid, i<<1);
        if (r >  mid) _add(l, r, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) return tr[i];
        push_down(i);
        int mid = (trl+trr)>>1;
        T res = init_val;
        if (l <= mid) res = mv(res, _query(l, r, trl, mid, i<<1));
        if (r >  mid) res = mv(res, _query(l, r, mid+1, trr, i<<1|1));
        return res;
    }
};

int n, m;
int a[N];
SegmentTree<int, greater<int>> ST;

int main()
{
    char op;
    int n, m, x, y;
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        ST.build(a, n);
        while (m--) {
            scanf("%*[ \n]%c%d%d", &op, &x, &y);
            if (op == 'U') ST.modify(x, y);
            else if (op == 'Q') printf("%d\n", ST.query(x, y));
        }
    }
    return 0;
}
