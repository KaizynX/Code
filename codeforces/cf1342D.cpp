/*
 * @Author: Kaizyn
 * @Date: 2020-04-26 22:34:31
 * @LastEditTime: 2020-04-26 23:41:38
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
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
        _build(l, mid, k, i<<1);
        _build(mid+1, r, k, i<<1|1);
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

int n, k;
int m[N], c[N];
SegmentTree<int> ST;
vector<int> res[N];
vector<int> id[N];

inline void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> m[i];
    for (int i = 1; i <= k; ++i) cin >> c[i];

    int cnt = 0;
    ST.build(k, 0);
    sort(m+1, m+n+1);
    reverse(m+1, m+n+1);
    for (int i = 1, j, p; i <= n; ++i) {
        j = ST.query(m[i], k);
        if (!j) {
            p = cnt++;
            j = k;
        }
        else {
            p = id[j].back();
            id[j].pop_back();
            if (id[j].size() == 0) ST.modify(j, 0);
        }
        res[p].emplace_back(m[i]);
        while (j && (int)res[p].size() >= c[j]) --j;
        id[j].emplace_back(p);
        if (j && id[j].size() == 1) ST.modify(j, j);
    }
    cout << cnt << endl;
    for (int i = 0, p; i <= k; ++i) {
        while (id[i].size()) {
            p = id[i].back();
            id[i].pop_back();
            cout << res[p].size() << " ";
            for (int &j : res[p]) cout << j << " ";
            cout << endl;
        }
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