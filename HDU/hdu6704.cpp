/*
 * @Author: Kaizyn
 * @Date: 2020-05-03 17:01:25
 * @LastEditTime: 2020-05-03 21:25:05
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e5+7;
const int NN = (int)log2(N)+3;

template <typename T>
struct PersistenceSegmentTree
{
    static const int NN = N*(log2(N)+5);
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

int n, q;
char s[N];
int lg2[N], stl[N][NN], str[N][NN];
int sa[N], rk[N<<1], height[N];
PersistenceSegmentTree<int> pst;

template <typename T>
void st_init(const T a[], const int &n) {
    for (int i = 1; i <= n; ++i) {
        stl[i][0] = a[i];
        for (int j = 1; j <= lg2[i]; ++j)
            stl[i][j] =  min(stl[i][j-1], stl[i-(1<<(j-1))][j-1]);
    }
    for (int i = n; i; --i) {
        str[i][0] = a[i];
        for (int j = 1; j <= lg2[n-i+1]; ++j)
            str[i][j] =  min(str[i][j-1], str[i+(1<<(j-1))][j-1]);
    }
}

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
    st_init(height, n);
    pst.build(sa, n);
#ifdef DEBUG
    // for (int i = 1; i <= n; ++i) printf("sa[%2d]=%2d %s\n", i, sa[i], s+sa[i]);
#endif
    for (int t = 1, l, r, k, st, ed, len; t <= q; ++t) {
        scanf("%d%d%d", &l, &r, &k);
        len = r-l+1;
        st = rk[l];
        ed = rk[l]+1;
        for (int i = lg2[n]; i >= 0; --i) {
            if (stl[st][i] >= len) st -= 1<<i;
            if (str[ed][i] >= len) ed += 1<<i;
        }
#ifdef DEBUG
        // printf("(%d %d) ", st, ed);
#endif
        printf("%d\n", ed-st < k ? -1 : pst.query(st, ed-1, k));
    }
    for (int i = 1; i <= n; ++i) {
        memset(stl[i], 0, sizeof stl[i]);
        memset(str[i], 0, sizeof str[i]);
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}