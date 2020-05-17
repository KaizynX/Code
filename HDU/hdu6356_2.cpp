/*
 * @Author: Kaizyn
 * @Date: 2020-05-05 23:27:57
 * @LastEditTime: 2020-05-06 09:58:05
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 998244353;
const int INF = 1<<30;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <typename T, typename U = greater<T>>
struct SegmentTree
{
    SegmentTree(){}
    void build(const int &_n, const T &k = 0) { n = _n; _build(1, n, k); }
    void modify(const int &l, const int &r, const T &k) { _modify(l, r, k); }
    T query(const int &x) { return _query(x); }
private:
    struct TreeNode
    {
        int l, r;
        T v, lazy;
    } tr[N<<2];
    int n;
    T init_val = cmp(0, 1) ? INF : -INF;
    U cmp = U();
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
    void update(const int &i, const T &k) { tr[i].v = mv(tr[i].v, k); tr[i].lazy = mv(tr[i].lazy, k); }
    void push_up(const int &i) { tr[i].v = mv(tr[i<<1].v, tr[i<<1|1].v); }
    void push_down(const int &i) {
        if (tr[i].lazy == init_val) return;
        update(i<<1, tr[i].lazy);
        update(i<<1|1, tr[i].lazy);
        tr[i].lazy = init_val;
    }
    void _build(const int &l, const int &r, const T &k = 0, const int &i = 1) {
        tr[i].lazy = init_val;
        tr[i].l = l; tr[i].r = r;
        if (l == r) { tr[i].v = k; return; }
        int mid = (l+r)>>1;
        _build(l, mid, k, i<<1);
        _build(mid+1, r, k, i<<1|1);
        push_up(i);
    }
    void _modify(const int &l, const int &r, const T &k, const int &i = 1) {
        if (tr[i].l  >= l && tr[i].r <= r) { update(i, k); return; }
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (l <= mid) _modify(l, r, k, i<<1);
        if (r >  mid) _modify(l, r, k, i<<1|1);
        push_up(i);
    }
    T _query(const int &x, const int &i = 1) {
        if (tr[i].l  == x && tr[i].r == x) return tr[i].v;
        push_down(i);
        int mid = (tr[i].l+tr[i].r)>>1;
        if (x <= mid) return _query(x, i<<1);
        else return _query(x, i<<1|1);
    }
};

int n, m;
unsigned X, Y, Z;
SegmentTree<int> ST;

inline unsigned RNG61() {
    static unsigned W;
    X = X^(X<<11);
    X = X^(X>>4);
    X = X^(X<<5);
    X = X^(X>>14);
    W = X^(Y^Z);
    X = Y;
    Y = Z;
    Z = W;
    return Z;
}

inline void solve()
{
    cin >> n >> m >> X >> Y >> Z;
    ST.build(n, 0);
    for (int i = 1, l, r, v; i <= m; ++i) {
        l = RNG61()%n+1;
        r = RNG61()%n+1;
        v = RNG61()%(1<<30);
        if (l > r) swap(l, r);
        ST.modify(l, r, v);
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        res ^= 1ll*i*ST.query(i);
    }
    cout << res << endl;
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