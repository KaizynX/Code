/*
 * @Author: Kaizyn
 * @Date: 2020-05-03 15:40:28
 * @LastEditTime: 2020-05-03 16:08:53
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
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

int n, k;
int a[N];
ST<int, less<int>> st;

int sa[N], rk[N<<1], height[N];
template <typename T> // s start from 1
inline void SA(const T *s, const int &n) {
    static int oldrk[N<<1];
    for (int i = 1; i <= n; ++i) rk[i] = s[i];
    for (int w = 1; w < n; w <<= 1) {
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

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    SA(a, n);
    st.build(height, n);
    int res = 0;
    #ifdef DEBUG
    for (int i = 1; i <= n; ++i) cout << height[i] << " \n"[i==n];
    #endif
    for (int i = 1; i+k-2 <= n; ++i) {
        res = max(res, st.query(i, i+k-2));
    }
    cout << res << endl;
    return 0;
}