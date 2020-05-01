/*
 * @Author: Kaizyn
 * @Date: 2020-04-30 10:34:08
 * @LastEditTime: 2020-04-30 15:08:44
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <typename T>
struct LinearBase
{
    int sz = sizeof(T)*8, zero;
    vector<T> b;
    LinearBase(){ init(); }
    void init() {
        zero = 0;
        vector<T>(sz, 0).swap(b);
    }
    void merge(const LinearBase &xj) {
        zero |= xj.zero;
        for (int i : xj.b) if (i) insert(i);
    }
    void insert(T x) {
        for (int i = sz-1; i >= 0; --i) if ((x>>i)&1) {
            if (!b[i]) { b[i] = x; return; }
            x ^= b[i];
        }
        zero = 1;
    }
    T max_xor(T res = 0) {
        for (int i = sz-1; i >= 0; --i)
            if (~(res>>i)&1) res ^= b[i];
            // res = max(res, res^b[i]);
        return res;
    }
    T min_xor() {
        if (zero) return 0;
        for (int i = 0; i < sz; ++i)
            if (b[i]) return b[i];
        return 0;
    }
};

int n, q, dfn;
int v[N], st[N], ed[N], a[N];
vector<int> e[N];

struct SegmentTree {
    struct TreeNode {
        LinearBase<int> v;
        int l, r;
    } tr[N<<2];
    void build(const int &l, const int &r, const int &i = 1) {
        tr[i].l = l; tr[i].r = r;
        if (l == r) {
            tr[i].v.init();
            tr[i].v.insert(a[l]);
            return;
        }
        int mid = (l+r)>>1;
        build(l, mid, i<<1);
        build(mid+1, r, i<<1|1);
        tr[i].v = tr[i<<1].v;
        tr[i].v.merge(tr[i<<1|1].v);
    }
    int query(const int &l, const int &r, const int &x) {
        LinearBase<int> lb = _query(l, r);
        #ifdef DEBUG
        for (auto &i : lb.b) cout << i << " ";
        cout << endl;
        #endif
        int res = lb.max_xor(x);
        if (res == x) res = x^lb.min_xor();
        return res;
    }
    LinearBase<int> _query(const int &l, const int &r, const int &i = 1) {
        if (tr[i].l >= l && tr[i].r <= r) return tr[i].v;
        int mid = (tr[i].l+tr[i].r)>>1;
        LinearBase<int> res;
        if (l <= mid) res.merge(_query(l, r, i<<1));
        if (r >  mid) res.merge(_query(l, r, i<<1|1));
        return res;
    }
} ST;

void dfs(const int &u) {
    st[u] = ++dfn;
    for (const int &v : e[u]) dfs(v);
    ed[u] = dfn;
}

inline void solve()
{
    dfn = 0;
    for (int i = 1; i <= n; ++i) vector<int>().swap(e[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", v+i);
    for (int i = 2, f; i <= n; ++i) {
        scanf("%d", &f);
        e[f].emplace_back(i);
    }
    dfs(1);
    for (int i = 1; i <= n; ++i) a[st[i]] = v[i];
    ST.build(1, n);
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) {
        cout << st[i] << " " << ed[i] << " " << a[i] << endl;
    }
    #endif
    for (int i = 1, u, x; i <= q; ++i) {
        scanf("%d %d", &u, &x);
        printf("%d\n", ST.query(st[u], ed[u], x));
    }
}

signed main()
{
    while (scanf("%d %d", &n, &q) == 2) solve();
    return 0;
}