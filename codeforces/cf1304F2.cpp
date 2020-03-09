#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 55;
const int M = 2e4+7;
const int INF = 1e9;

int n, m, k;
int a[N][M];
long long sum[N][M], dp[N][M];

template <typename T, typename U = greater<T>>
struct SegmentTree
{
    U cmp = U();
    T tr[M<<2], lazy[M<<2], init_val = cmp(0, 1) ? INF : -INF;
    SegmentTree(){}
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y;}
    void push_up(const int &i) { tr[i] = mv(tr[i<<1], tr[i<<1|1]); }
    /*
    void push_down(const int &i) {
        tr[i<<1] = mv(tr[i<<1], lazy[i]);
        tr[i<<1|1] = mv(tr[i<<1|1], lazy[i]);
        lazy[i<<1] = mv(lazy[i<<1], lazy[i]);
        lazy[i<<1|1] = mv(lazy[i<<1|1], lazy[i]);
        lazy[i] = init_val;
    }
    */
    void push_down(const int &i) {
        if (!lazy[i]) return;
        tr[i<<1] += lazy[i];
        tr[i<<1|1] += lazy[i];
        lazy[i<<1] += lazy[i];
        lazy[i<<1|1] += lazy[i];
        lazy[i] = 0;
    }
    void build(const int &l, const int &r, const int &i = 1) {
        lazy[i] = 0;
        if (l == r) { tr[i] = 0; return; }
        int mid = (l+r)>>1;
        build(l, mid, i<<1);
        build(mid+1, r, i<<1|1);
        push_up(i);
    }
    template <typename TT>
    void build(const TT a[], const int &l, const int &r, const int &i = 1) {
        lazy[i] = 0;
        if (l == r) { tr[i] = a[l]; return; }
        int mid = (l+r)>>1;
        build(a, l, mid, i<<1);
        build(a, mid+1, r, i<<1|1);
        push_up(i);
    }
    void modify(const int &x, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl == x && trr == x) {
            tr[i] = k;
            return;
        }
        push_down(i);
        int mid = (trl+trr)>>1;
        if (x <= mid) update(x, k, trl, mid, i<<1);
        else update(x, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    void add(const int &l, const int &r, const T &k, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) {
            tr[i] += k;
            lazy[i] += k;
            return;
        }
        push_down(i);
        int mid = (trl+trr)>>1;
        if (l <= mid) add(l, r, k, trl, mid, i<<1);
        if (r >  mid) add(l, r, k, mid+1, trr, i<<1|1);
        push_up(i);
    }
    T query(const int &l, const int &r, const int &trl, const int &trr, const int &i = 1) {
        if (trl >= l && trr <= r) return tr[i];
        push_down(i);
        int mid = (trl+trr)>>1;
        T res = init_val;
        if (l <= mid) res = mv(res, query(l, r, trl, mid, i<<1));
        if (r >  mid) res = mv(res, query(l, r, mid+1, trr, i<<1|1));
        return res;
    }
};

SegmentTree<long long> ST;

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            sum[i][j] = sum[i][j-1]+a[i][j];
        }

    for (int i = 1; i <= m-k+1; ++i)
        dp[1][i] = sum[1][i+k-1]-sum[1][i-1]+sum[2][i+k-1]-sum[2][i-1];
    for (int i = 2; i <= n; ++i) {
        // the i'th at [1, k], del a[i][1, k]
        for (int j = 1; j <= k && j <= m-k+1; ++j)
            dp[i-1][j] -= sum[i][k]-sum[i][j-1];
        ST.build(dp[i-1], 1, m-k+1);
        for (int j = 1; j <= m-k+1; ++j) {
#ifdef DEBUG
            for (int l = 1; l <= m-k+1; ++l)
                cout << ST.query(l, l, 1, m-k+1) << " \n"[l==m-k+1];
#endif
            long long s = sum[i][j+k-1]-sum[i][j-1]+sum[i+1][j+k-1]-sum[i+1][j-1];
            dp[i][j] = s+ST.query(1, m-k+1, 1, m-k+1);
            // move [j, j+k-1] to [j+1, j+k]
            if (j == m-k+1) break;
            ST.add(max(1, j-k+1), j, a[i][j], 1, m-k+1);
            ST.add(j+1, min(m-k+1, j+k), -a[i][j+k], 1, m-k+1);
        }
#ifdef DEBUG
        for (int j = 1; j <= m-k+1; ++j)
            cout << dp[i][j] << " \n"[j==m-k+1];
#endif
    }
    long long res = 0;
    for (int i = 1; i <= m-k+1; ++i) res = max(res, dp[n][i]);
    cout << res << endl;
    return 0;
}
