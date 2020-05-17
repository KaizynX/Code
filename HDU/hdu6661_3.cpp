/*
 * @Author: Kaizyn
 * @Date: 2020-05-05 10:01:56
 * @LastEditTime: 2020-05-05 17:20:50
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 3e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

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

namespace SuffixArray {

int sa[N], rk[N], ht[N];
bool t[N << 1];

inline bool islms(const int i, const bool *t) { return i > 0 && t[i] && !t[i - 1]; }

template <class T>
inline void sort(T s, int *sa, const int len, const int sz, const int sigma, bool *t, int *b, int *cb,
                 int *p) {
    memset(b, 0, sizeof(int) * sigma);
    memset(sa, -1, sizeof(int) * len);
    for (register int i = 0; i < len; i++) b[static_cast<int>(s[i])]++;
    cb[0] = b[0];
    for (register int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i];
    for (register int i = sz - 1; i >= 0; i--) sa[--cb[static_cast<int>(s[p[i]])]] = p[i];
    for (register int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i - 1];
    for (register int i = 0; i < len; i++)
        if (sa[i] > 0 && !t[sa[i] - 1])
            sa[cb[static_cast<int>(s[sa[i] - 1])]++] = sa[i] - 1;
    cb[0] = b[0];
    for (register int i = 1; i < sigma; i++) cb[i] = cb[i - 1] + b[i];
    for (register int i = len - 1; i >= 0; i--)
        if (sa[i] > 0 && t[sa[i] - 1])
            sa[--cb[static_cast<int>(s[sa[i] - 1])]] = sa[i] - 1;
}

template <class T>
inline void sais(T s, int *sa, const int len, bool *t, int *b, int *b1, const int sigma) {
    register int i, j, x, p = -1, cnt = 0, sz = 0, *cb = b + sigma;
    for (t[len - 1] = 1, i = len - 2; i >= 0; i--) t[i] = s[i] < s[i + 1] || (s[i] == s[i + 1] && t[i + 1]);
    for (i = 1; i < len; i++)
        if (t[i] && !t[i - 1])
            b1[sz++] = i;
    sort(s, sa, len, sz, sigma, t, b, cb, b1);
    for (i = sz = 0; i < len; i++)
        if (islms(sa[i], t))
            sa[sz++] = sa[i];
    for (i = sz; i < len; i++) sa[i] = -1;
    for (i = 0; i < sz; i++) {
        for (x = sa[i], j = 0; j < len; j++) {
            if (p == -1 || s[x + j] != s[p + j] || t[x + j] != t[p + j]) {
                cnt++, p = x;
                break;
            } else if (j > 0 && (islms(x + j, t) || islms(p + j, t))) {
                break;
            }
        }
        sa[sz + (x >>= 1)] = cnt - 1;
    }
    for (i = j = len - 1; i >= sz; i--)
        if (sa[i] >= 0)
            sa[j--] = sa[i];
    register int *s1 = sa + len - sz, *b2 = b1 + sz;
    if (cnt < sz)
        sais(s1, sa, sz, t + len, b, b1 + sz, cnt);
    else
        for (i = 0; i < sz; i++) sa[s1[i]] = i;
    for (i = 0; i < sz; i++) b2[i] = b1[sa[i]];
    sort(s, sa, len, sz, sigma, t, b, cb, b2);
}

template <class T>
inline void getHeight(T s, int n) {
    for (register int i = 1; i <= n; i++) rk[sa[i]] = i;
    register int j = 0, k = 0;
    for (register int i = 0; i < n; ht[rk[i++]] = k)
        for (k ? k-- : 0, j = sa[rk[i] - 1]; s[i + k] == s[j + k]; k++)
            ;
}

template <class T>  // s start from 0
inline void init(T s, const int len, const int sigma = 128) {
    sais(s, sa, len + 1, t, rk, ht, sigma);
    getHeight(s, len);
    for (int i = 1; i <= len; ++i) ++sa[i];
    for (int i = len; i; --i) rk[i] = rk[i-1];
}

}  // namespace SuffixArray

int n, k;
char s[N];
ST<int, less<int>> st;

inline int lcp(const int &l, const int &r) {
    return l < r ? st.query(l+1, r) : st.query(r+1, l);
}

inline void solve()
{
    scanf("%d%s", &k, s);
    n = strlen(s);
    if (k == 1) return void(printf("%lld\n", n*(n+1ll)/2));
    SuffixArray::init(s, n);
    int *ht = SuffixArray::ht;
    int *rk = SuffixArray::rk;
    st.build(ht, n);
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1, last = 0, len1, len2, t1, t2, l; j+i <= n; j += i) {
            len1 = lcp(rk[j], rk[j+i]);
            t1 = len1/i+1;
            l = j-i+len1%i;
            // check (j-i, j-1]
            if (l > 0 && len1%i) {
                len2 = lcp(rk[l], rk[l+i]);
                t2 = len2/i+1;
                if (t2 > k) {
                    res += max(0, j-1-last);
                } else if (t2 == k) {
                    res += max(0, l+len2%i-last);
                }
            }
            // check[j, j+i)
            if (t1 > k) {
                res += i;
                last = j+i-1;
            } else if (t1 == k) {
                res += len1%i+1;
                last = j+len1%i;
            }
        }
    }
    printf("%lld\n", res);
}

signed main()
{
    int T;
    scanf("%d", &T);
    while (T--) solve();
    return 0;
}