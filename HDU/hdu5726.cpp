/*
 * @Author: Kaizyn
 * @Date: 2020-05-05 18:24:58
 * @LastEditTime: 2020-05-05 19:10:55
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
    void build(T a[], const int &n) {
        for (int i = 1; i <= n; ++i) {
            rmq[i][0] = a[i];
            for (int j = 1; j <= lg2[i]; ++j)
                rmq[i][j] =  cmp(rmq[i][j-1], rmq[i-(1<<(j-1))][j-1]);
        }
    }
    T query(const int &l, const int &r) {
        if (l > r) return query(r, l);
        int k = lg2[r-l+1];
        return cmp(rmq[r][k], rmq[l+(1<<k)-1][k]);
    }
};

struct GCD {
    template <class T>
    T operator ()(const T &x, const T &y) {
        return __gcd(x, y);
    }
};

int n, m;
int a[N];
ST<int, GCD> st;
map<int, long long> cnt;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T;
    scanf("%d", &T);
    for (int t = 1; t <= T; ++t) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        int base = a[1];
        for (int i = 2; i <= n; ++i) base = __gcd(base, a[i]);
        for (int i = 1; i <= n; ++i) a[i] /= base;
        st.build(a, n);

        cnt.clear();
        for (int i = 1, g; i <= n; ++i) {
            g = a[i];
            ++cnt[g];
            for (int j = i+1; j <= n; ++j) {
                g = __gcd(g, a[j]);
                if (g == 1) {
                    cnt[1] += n-j+1;
                    break;
                }
                ++cnt[g];
            }
        }

        scanf("%d", &m);
        printf("Case #%d:\n", t);
        for (int i = 1, l, r, g; i <= m; ++i) {
            scanf("%d%d", &l, &r);
            g = st.query(l, r);
            printf("%d %lld\n", g*base, cnt[g]);
        }
    }
    return 0;
}