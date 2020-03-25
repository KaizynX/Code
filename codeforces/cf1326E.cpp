/*
 * @Author: Kaizyn
 * @Date: 2020-03-24 16:13:21
 * @LastEditTime: 2020-03-24 16:32:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 3e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <typename T, typename U = greater<T>>
struct SegmentTree
{
    U cmp = U();
    int n;
    T tr[N<<2], lazy[N<<2], init_val = cmp(0, 1) ? INF : -INF;
    SegmentTree(){}
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
    void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
    template <typename TT>
    void build(const TT a[], const int &_n) { n = _n; _build(a, 1, n); }
    void modify(const int &x, const T &k) { _modify(x, k, 1, n); }
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
    void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
        lazy[i] = 0;
        if (l == r) { tr[i] = k; return; }
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
    void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) {
            tr[i] = k;
            return;
        }
        push_down(i);
        int mid = (trl+trr)>>1;
        if (x <= mid) _modify(x, k, trl, mid, i<<1);
        else _modify(x, k, mid+1, trr, i<<1|1);
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

struct Node
{
    int id, val;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.val > n2.val;
    }
};

int n;
int q[N], res[N];
Node a[N];
SegmentTree<int> BIT;

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i].val, a[i].id = i;
    for (int i = 1; i <= n; ++i) cin >> q[i];

    BIT.build(n);
    sort(a+1, a+n+1);
    for (int i = 1, x = 1; i <= n; ++i) {
        while (BIT.query(1, n) <= 0) {
            for (int i = x; x <= n && a[x].val == a[i].val; ++x) {
                BIT.add(1, a[x].id, 1);
            }
        }
        res[i] = a[x-1].val;
        cout << a[x-1].val << " \n"[i==n];
        BIT.add(1, q[i], -1);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}