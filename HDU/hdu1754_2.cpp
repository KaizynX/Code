#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;
const int INF = 1e9+7;

template <typename T>
struct zkwSegmentTree
{
    int sz;
    T sum[N<<2], mn[N<<2], mx[N<<2], add[N<<2];
    void operate(const int &x) {
        T tmp;
        tmp = min(mn[x], mn[x^1]); mn[x] -= tmp; mn[x^1] -= tmp; mn[x>>1] += tmp;
        tmp = max(mx[x], mx[x^1]); mx[x] -= tmp; mx[x^1] -= tmp; mx[x>>1] += tmp;
    }
    template <typename TT>
    void build(const TT a[], const int &n) {
        memset(mn, 0x7f, sizeof mn);
        memset(mx, 0xef, sizeof mx);
        for (sz = 1; sz <= n+1; sz <<= 1);
        for (int i = sz+1; i <= sz+n; ++i)
            sum[i] = mn[i] = mx[i] = a[i-sz];
        for (int i = sz-1; i; --i) {
            sum[i] = sum[i<<1]+sum[i<<1|1];
            mn[i] = min(mn[i<<1], mn[i<<1|1]); mn[i<<1] -= mn[i]; mn[i<<1|1] -= mn[i];
            mx[i] = max(mx[i<<1], mx[i<<1|1]); mx[i<<1] -= mx[i]; mx[i<<1|1] -= mx[i];
        }
    }
    void update(int x, const T &v) {
        x += sz; mx[x] += v; mn[x] += v; sum[x] += v;
        for ( ; x > 1; x >>= 1) {
            sum[x] += v;
            operate(x);
        }
    }
    void update(int s, int t, const T &v) {
        int lc = 0, rc = 0, len = 1;
        for (s += sz-1, t += sz+1; s^t^1; s >>= 1, t >>= 1, len <<= 1) {
            if (~s&1) add[s^1] += v, lc += len, mn[s^1] += v, mx[s^1] += v;
            if ( t&1) add[t^1] += v, rc += len, mn[t^1] += v, mx[t^1] += v;
            sum[s>>1] += v*lc; sum[t>>1] += v*rc;
            operate(s); operate(t);
        }
        for (lc += rc; s; s >>= 1) {
            sum[s>>1] += v*lc;
            operate(s);
        }
    }
    T query(int x) {
        T res = 0;
        for (x += sz; x; x >>= 1) res += mn[x];
        return res;
    }
    T query_sum(int s, int t) {
        int lc = 0, rc = 0, len = 1;
        T res = 0;
        for (s += sz-1, t += sz+1; s^t^1; s >>= 1, t >>= 1, len <<= 1) {
            if (~s&1) res += sum[s^1]+len*add[s^1], lc += len;
            if ( t&1) res += sum[t^1]+len*add[t^1], rc += len;
            if (add[s>>1]) res += add[s>>1]*lc;
            if (add[t>>1]) res += add[t>>1]*rc;
        }
        for (lc += rc, s >>= 1; s; s >>= 1) if (add[s]) res += add[s]*lc;
        return res;
    }
    T query_min(int s, int t) {
        if (s == t) return query(s);
        T l = 0, r = 0, res = 0;
        for (s += sz, t += sz; s^t^1; s >>= 1, t >>= 1) {
            l += mn[s]; r += mn[t];
            if (~s^1) l = min(l, mn[s^1]);
            if ( t^1) r = min(r, mn[t^1]);
        }
        for (res = min(l, r), s >>= 1; s; s >>= 1) res += mn[s];
        return res;
    }
    T query_max(int s, int t) {
        if (s == t) return query(s);
        T l = 0, r = 0, res = 0;
        for (s += sz, t += sz; s^t^1; s >>= 1, t >>= 1) {
            l += mx[s]; r += mx[t];
            if (~s^1) l = max(l, mx[s^1]);
            if ( t^1) r = max(r, mx[t^1]);
        }
        for (res = max(l, r), s >>= 1; s; s >>= 1) res += mx[s];
        return res;
    }
};

int n, m;
int a[N];
zkwSegmentTree<int> ST;

int main()
{
    char op;
    int n, m, x, y;
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        ST.build(a, n);
        while (m--) {
            scanf("%*[ \n]%c%d%d", &op, &x, &y);
            if (op == 'U') {
                int tmp = ST.query(x);
                if (y <= tmp) continue;
                ST.update(x, y-tmp);
            }
            else if (op == 'Q') printf("%d\n", ST.query_max(x, y));
        }
    }
    return 0;
}
