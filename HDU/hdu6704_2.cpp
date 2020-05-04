/*
 * @Author: Kaizyn
 * @Date: 2020-05-03 17:01:25
 * @LastEditTime: 2020-05-03 21:02:04
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int NN = (int)log2(N)+3;

template <typename T>
struct PersistenceSegmentTree
{
    static const int NN = N*(log2(N)+3);
    int rt[N], sum[NN], ls[NN], rs[NN], tot, sz;
    void build(const T a[], const int &n) {
        sz = n;
        tot = 0;
        rt[0] = _build(1, n);
        for (int i = 1; i <= n; ++i) {
            rt[i] = _update(rt[i-1], 1, sz, a[i]);
        }
    }
    T query(const int &l, const int &r, const int &k) {
        if (sum[rt[r]]-sum[rt[l-1]] < k) return -1;
        return _query(rt[l-1], rt[r], 1, sz, k);
    }
private:
    int _build(const int &l, const int &r) {
        int cur = ++tot;
        sum[cur] = 0;
        if (l >= r) return cur;
        int mid = (l+r)>>1;
        ls[cur] = _build(l, mid);
        rs[cur] = _build(mid+1, r);
        return cur;
    }
    int _update(const int &pre, const int &l, const int &r, const int &k) {
        int cur = ++tot;
        ls[cur] = ls[pre]; rs[cur] = rs[pre]; sum[cur] = sum[pre]+1;
        if (l >= r) return cur;
        int mid = (l+r)>>1;
        if (k <= mid) ls[cur] = _update(ls[pre], l, mid, k);
        else rs[cur] = _update(rs[pre], mid+1, r, k);
        return cur;
    }
    int _query(const int &u, const int &v, const int &l, const int &r, const int &k) {
        if (l >= r) return l;
        int num = sum[ls[v]]-sum[ls[u]], mid = (l+r)>>1;
        if (num >= k) return _query(ls[u], ls[v], l, mid, k);
        else return _query(rs[u], rs[v], mid+1, r, k-num);
    }
};

template <typename T, typename U = std::greater<T>>
struct ST
{
    static const int NN = (int)log2(N)+3;
    static const T INF = 1e9;
    int lg2[N];
    U cmp = U();
    T rmq[N][NN]; // rmq[i][j] ==> [i-2^j+1, i]
    ST() {
        fill(rmq[0], rmq[0]+N*NN, cmp(-INF, +INF) ? INF : -INF);
        for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
    }
    T& operator [] (const int &i) { return rmq[i][0]; }
    void init(const T &val = 0) { fill(rmq[0], rmq[0]+N*NN, val); }
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y; }
    void build(T a[], const int &n) {
        for (int i = 1; i <= n; ++i) {
            rmq[i][0] = a[i];
            for (int j = 1; j <= lg2[i]; ++j)
                rmq[i][j] =  mv(rmq[i][j-1], rmq[i-(1<<(j-1))][j-1]);
        }
    }
    T query(const int &l, const int &r) {
        int k = lg2[r-l+1];
        return mv(rmq[r][k], rmq[l+(1<<k)-1][k]);
    }
};

int n, q;
char s[N];
int sa[N], rk[N<<1], height[N];
ST<int, less<int>> st;
PersistenceSegmentTree<int> pst;

template <typename T> // s start from 1
inline void SA(const T *s, const int &n) {
    static int oldrk[N<<1];
    for (int i = 1; i <= n; ++i) rk[i] = s[i];
    for (int w = 1; w <= n; w <<= 1) {
        iota(sa+1, sa+n+1, 1);
        sort(sa+1, sa+n+1, [&](const int &x, const int &y) {
          return rk[x] == rk[y] ? rk[x+w] < rk[y+w] : rk[x] < rk[y];
        });
        memcpy(oldrk+1, rk+1, sizeof(int)*n);
        for (int p = 0, i = 1; i <= n; ++i) {
            if (oldrk[sa[i]] == oldrk[sa[i-1]] &&
                oldrk[sa[i]+w] == oldrk[sa[i-1]+w]) {
                rk[sa[i]] = p;
            } else {
                rk[sa[i]] = ++p;
            }
        }
    }
    for (int i = 1, k = 0; i <= n; ++i) {
        if (k) --k;
        while (s[i+k] == s[sa[rk[i]-1]+k]) ++k;
        height[rk[i]] = k;
    }
}

inline void solve() {
    scanf("%d%d%s", &n, &q, s+1);
    SA(s, n);
    st.build(height, n);
    pst.build(sa, n);
    for (int t = 1, l, r, k, be, ed, len, ll ,rr, mid; t <= q; ++t) {
        scanf("%d%d%d", &l, &r, &k);
        len = r-l+1;
        be = ed = sa[l];
        ll = 1; rr = sa[l];
        while (ll <= rr) {
            mid = (ll+rr)>>1;
            if (st.query(mid, sa[l]) >= len) be = mid, rr = mid-1;
            else ll = mid+1;
        }
        ll = sa[l]; rr = n;
        while (ll <= rr) {
            mid = (ll+rr)>>1;
            if (st.query(sa[l], mid) >= len) ed = mid, ll = mid+1;
            else rr = mid-1;
        }
        printf("(%d %d) ", be, ed);
        printf("%d\n", ed-be+1 < k ? -1 : pst.query(be, ed, k));
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}