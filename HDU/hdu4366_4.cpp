/*
 * @Author: Kaizyn
 * @Date: 2020-03-10 20:07:40
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-10 21:04:33
 * @FilePath: \Code\HDU\hdu4366_4.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int INF = 0x3f3f3f3f;

template <typename T>
struct SegmentTree
{
    void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
    void modify(const int &x, const T &k) { _modify(x, k, 1, n); }
    T query(const int &l, const int &r) { return l > r ? -1 : _query(l, r, 1, n); }
private :
    int n;
    T tr[N<<2];
    void push_up(const int &i) { tr[i] = max(tr[i<<1], tr[i<<1|1]); }
    void _build(const int &l, const int &r, const T &k, const int &i = 1) {
        if (l == r) { tr[i] = k; return; }
        int mid = (l+r)>>1;
        _build(l, mid, i<<1);
        _build(mid+1, r, i<<1|1);
        push_up(i);
    }
    void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) { tr[i] = k; return; }
        int mid = (trl+trr)>>1;
        if (x <= mid) _modify(x, k, trl, mid, i<<1);
        else _modify(x, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    T _query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) return tr[i];
        int mid = (trl+trr)>>1;
        T res = -1;
        if (l <= mid) res = max(res, _query(l, r, trl, mid, i<<1));
        if (r >  mid) res = max(res, _query(l, r, mid+1, trr, i<<1|1));
        return res;
    }
};

struct Node
{
    int id, abi, loy, l, r, dfn;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.abi == n2.abi ? n1.id < n2.id : n1.abi > n2.abi;
    }
};

int n, m, tot;
int res[N];
Node a[N];
vector<int> e[N];
map<int, int> mp;
SegmentTree<int> ST;

inline void init()
{
    tot = 0;
    mp.clear();
    ST.build(n, -1);
    memset(res, -1, sizeof res);
    for (int i = 0; i <= n; ++i) vector<int>().swap(e[i]);
}

void dfs(const int &u)
{
    a[u].dfn = tot++;
    for (int v : e[u]) dfs(v);
    a[u].l = a[u].dfn+1;
    a[u].r = tot-1;
}

inline void solve()
{
    cin >> n >> m;
    init();
    for (int i = 1, fa; i < n; ++i) {
        cin >> fa >> a[i].loy >> a[i].abi;
        a[i].id = i;
        e[fa].emplace_back(i);
        mp[a[i].loy] = i;
    }
    dfs(0);
    sort(a+1, a+n);
    mp[-1] = -1;
    for (int i = 1; i < n; ++i) {
        ST.modify(a[i].dfn, a[i].loy);
        res[a[i].id] = mp[ST.query(a[i].l, a[i].r)];
    }
    for (int i = 1, x; i <= m; ++i) {
        cin >> x;
        cout << res[x] << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}