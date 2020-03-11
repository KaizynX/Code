/*
 * @Author: Kaizyn
 * @Date: 2020-03-10 17:25:36
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-10 20:31:24
 * @FilePath: \Code\HDU\hdu4366_3.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e4+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <typename T, typename U = greater<T>>
struct SegmentTree
{
    void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
    void modify(const int &x, const T &k) { _modify(x, k, 1, n); }
    T query(const int &l, const int &r) { return _query(l, r, 1, n); }
private :
    U cmp = U();
    int n;
    T tr[N<<2], init_val = cmp(0, 1) ? INF : -INF;
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
    void push_up(const int &i) { tr[i] = mv(tr[i<<1], tr[i<<1|1]); }
    void _build(const int &l, const int &r, const T &k, const int &i = 1) {
        if (l == r) { tr[i] = k; return; }
        int mid = (l+r)>>1;
        _build(l, mid, i<<1);
        _build(mid+1, r, i<<1|1);
        push_up(i);
    }
    void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) {
            tr[i] = k;
            return;
        }
        int mid = (trl+trr)>>1;
        if (x <= mid) _modify(x, k, trl, mid, i<<1);
        else _modify(x, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) return tr[i];
        int mid = (trl+trr)>>1;
        T res = init_val;
        if (l <= mid) res = mv(res, _query(l, r, trl, mid, i<<1));
        if (r >  mid) res = mv(res, _query(l, r, mid+1, trr, i<<1|1));
        return res;
    }
};

struct Node
{
    int id, abi, loy, l, r, dfn;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.abi > n2.abi;
    }
};

int n, m, tot;
int res[N];
Node a[N];
vector<int> e[N];
map<int, int> mp;
SegmentTree<int> ST;

void dfs(const int &u)
{
    a[u].dfn = ++tot;
    for (int v : e[u]) dfs(v);
    a[u].l = a[u].dfn+1;
    a[u].r = tot;
}

inline void solve()
{
    cin >> n >> m;
    mp.clear();
    for (int i = 0; i < n; ++i) vector<int>().swap(e[i]);
    a[0].id = 0; a[0].abi = a[0].loy = 1;
    mp[1] = 0;
    mp[0] = -1;
    for (int i = 1, fa; i < n; ++i) {
        cin >> fa >> a[i].loy >> a[i].abi;
        a[i].abi += 2; a[i].loy += 2;
        mp[a[i].loy] = i;
        a[i].id = i;
        e[fa].emplace_back(i);
    }
    tot = 0;
    dfs(0);
    sort(a, a+n);
    ST.build(n);
    for (int i = 0, j; i < n; ) {
        j = i;
        while (j < n && a[i].abi == a[j].abi) {
            if (a[j].l > a[j].r) res[a[j].id] = -1;
            else res[a[j].id] = mp[ST.query(a[j].l, a[j].r)];
            ++j;
        }
        while (i < j) {
            ST.modify(a[i].dfn, a[i].loy);
            ++i;
        }
    }
    for (int i = 1, x; i <= m; ++i) {
        cin >> x;
        cout << res[x] << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}