/*
 * @Author: Kaizyn
 * @Date: 2020-05-05 23:27:57
 * @LastEditTime: 2020-05-06 10:15:56
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

template <typename T, typename U = std::greater<T>>
struct rST
{
    static const int NN = (int)log2(N)+3;
    static const T INF = 1e9;
    int n;
    int lg2[N];
    U cmp = U();
    T rmq[N][NN]; // rmq[i][j] ==> [i, i+2^j-1]
    rST() { for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1; }
    T& operator [] (const int &i) { return rmq[i][0]; }
    T mv(const T &x, const T &y) { return cmp(x, y) ? x : y; }
    void init(const int &_n, const T &val = 0) { 
        n = _n;
        for (int i = 1; i <= n; ++i) fill(rmq[i], rmq[i]+NN, val);
    }
    void update(const int &l, const int &r, const T &k) {
        if (l > r) return void(update(r, l, k));
        int b = lg2[r-l+1];
        rmq[l][b] = mv(rmq[l][b], k);
        rmq[r-(1<<b)+1][b] = mv(rmq[r-(1<<b)+1][b], k);
    }
    void build() {
        for (int i = lg2[n]; i >= 0; --i) {
            for (int l = 1, r; l <= n; ++l) {
                r = l+(1<<i);
                if (r <= n) rmq[r][i] = mv(rmq[r][i], rmq[l][i+1]);
                rmq[l][i] = mv(rmq[l][i], rmq[l][i+1]);
            }
        }
    }
    T query(const int &l, const int &r) {
        if (l > r) return query(r, l);
        int b = lg2[r-l+1];
        return mv(rmq[l][b], rmq[r-(1<<b)+1][b]);
    }
};
    

int n, m;
unsigned X, Y, Z;
rST<int> ST;

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
    ST.init(n);
    for (int i = 1, l, r, v; i <= m; ++i) {
        l = RNG61()%n+1;
        r = RNG61()%n+1;
        v = RNG61()%(1<<30);
        if (l > r) swap(l, r);
        ST.update(l, r, v);
        // cerr << "update" << i << endl;
    }
    ST.build();
    // cerr << "build" << endl;
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        res ^= 1ll*i*ST[i];
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