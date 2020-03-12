/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 11:21:40
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 12:03:34
 * @FilePath: \Code\atcoder\abc158F_2.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <typename T, typename U = greater<T>>
struct SegmentTree
{
    U cmp = U();
    int n;
    T tr[N<<2], init_val = cmp(0, 1) ? INF : -INF;
    SegmentTree(){}
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
    void build(const int &_n) { n = _n; _build(1, n); }
    void modify(const int &x, const T &k) { _modify(x, k, 1, n); }
    T query(const int &x) { return _query(x, x, 1, n); }
    T query(const int &l, const int &r) { return _query(l, r, 1, n); }
private :
    void push_up(const int &i) { tr[i] = mv(tr[i<<1], tr[i<<1|1]); }
    void _build(const int &l, const int &r, const int &i = 1) {
        if (l == r) { tr[i] = l; return; }
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
    int x, d;
    Node(){}
    Node(const int _x ,const int _d = 0) : x(_x), d(_d) {}
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.x < n2.x;
    }
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.x >> nd.d;
    }
} a[N];

int n;
int rig[N], dp[N];
SegmentTree<int> ST;

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a+1, a+n+1);
    ST.build(n); // ST.query(i) == i
    dp[n+1] = 1;
    for (int i = n; i; --i) {
        int p = lower_bound(a+i, a+n+1, (Node)(a[i].x+a[i].d))-a-1;
        rig[i] = ST.query(i, p);
        ST.modify(i, rig[i]);
        // i'th is choose or not
        dp[i] = (dp[rig[i]+1]+dp[i+1])%MOD;
    }
    cout << dp[1] << endl;
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