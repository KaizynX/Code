/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 12:25:55
 * @LastEditTime: 2020-04-12 14:10:08
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e5+7;
const int MOD = 998244353;
const long long INF = 1e18;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <typename T>
struct SegmentTree
{
    int sz;
    T tr[N<<2], lazy[N<<2];
    SegmentTree(){}
    void build(const int &n, const T &k = 0) { sz = n; _build(1, n, k); }
    void modify(const int &x, const T &k) { _modify(x, k, 1, sz); }
    void add(const int &x, const T &k) { _add(x, x, k, 1, sz); }
    void add(int l, int r, const T &k) { if (l > r) swap(l, r); _add(l, r, k, 1, sz); }
    T query(const int &x) { return _query(x, 1, sz); }
private :
    void push_down(const int &i, const int &len) {
        if (!lazy[i]) return;
        if (len-len/2 == 1) tr[i<<1] += lazy[i]*(len-len/2);
        if (len/2 == 1) tr[i<<1|1] += lazy[i]*(len/2);
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
    }
    void _modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) {
            tr[i] = k;
            lazy[i] = 0;
            return;
        }
        push_down(i, trr-trl+1);
        int mid = (trl+trr)>>1;
        if (x <= mid) _modify(x, k, trl, mid, i<<1);
        else _modify(x, k, mid+1, trr, i<<1|1);
    }
    void _add(const int &l, const int &r, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) {
            if (trl == trr) tr[i] += k;
            lazy[i] += k;
            return;
        }
        push_down(i, trr-trl+1);
        int mid = (trl+trr)>>1;
        if (l <= mid) _add(l, r, k, trl, mid, i<<1);
        if (r >  mid) _add(l, r, k, mid+1, trr, i<<1|1);
    }
    T _query(const int &x, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) return tr[i];
        push_down(i, trr-trl+1);
        int mid = (trl+trr)>>1;
        if (x <= mid) return _query(x, trl, mid, i<<1);
        else return _query(x, mid+1, trr, i<<1|1);
    }
};

int n, m;
int a[N], p[N], b[N];
SegmentTree<long long> dp;

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> p[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i];
    // dp[0, m] ==> dp[1, m+1]
    dp.build(m+1, INF);
    dp.modify(0+1, 0);
    int t = 0;
    for (int i = 1, j; i <= n; ++i) {
        j = lower_bound(b+1, b+m+1, a[i])-b;
        long long tag = INF;
        // dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
        if (j <= t+1 && j <= m && a[i] == b[j]) {
            tag = dp.query(j-1+1);
            t = max(t, j);
        }
        if (p[i] < 0) {
            // dp[i][j] = dp[i-1][j]+p[i]
            dp.add(0+1, t+1, p[i]);
        } else {
            // if (a[i] <= b[j]) dp[i][j] = min(dp[i][j], dp[i-1][j]);
            dp.add(0+1, j-1+1, p[i]);
        }
        // dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
        if (j <= m) dp.modify(j+1, min(tag, dp.query(j+1)));
        #ifdef DEBUG
        for (int k = 0; k <= t; ++k) cout << dp.query(k+1) << " ";
        cout << endl;
        #endif
    }
    if (t < m) cout << "NO" << endl;
    else cout << "YES\n" << dp.query(m+1) << endl; 
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