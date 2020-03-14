/*
 * @Author: Kaizyn
 * @Date: 2020-03-13 15:54:01
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-13 15:59:07
 * @FilePath: \Code\Luogu\luogu3390_2.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <typename T>
T exgcd(const T a, const T b, T &x, T &y)
{
    if (!b) { x = 1; y = 0; return a; }
    T d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

template <typename T>
inline T mul_inverse(const T &a, const T &mo = MOD)
{
    T x, y;
    exgcd(a, mo, x, y);
    return (x%mo+mo)%mo;
}

template <typename T>
struct Martix {
    int n, m;
    T a[N][N];
    Martix(){}
    Martix(const int &_n) : n(_n) { init(); }
    Martix(const int &_n, const int &_m) : n(_n), m(_m) { init(); }
    void init(const int &tag = 0) {
        for (int i = 1; i <= n; ++i) memset(a[i], 0, sizeof(T)*(n+1));
        for (int i = 1; i <= n; ++i) a[i][i] = tag;
    }
    friend Martix operator * (const Martix &m1, const Martix &m2) {
        Martix res(m1.n, m2.m);
        for (int i = 1; i <= res.n; ++i)
            for (int j = 1; j <= res.m; ++j)
                for (int k = 1; k <= m1.m; ++k)
                    res.a[i][j] = (res.a[i][j]+m1.a[i][k]*m2.a[k][j])%MOD;
        return res;
    }
    Martix& operator *= (const Martix &mx) { return *this = *this*mx; }
    template <typename TT>
    Martix pow(const TT &p) const {
        Martix res(n, m), a = *this;
        res.init(1);
        for (TT i = p; i; i >>= 1, a *= a) if (i&1) res *= a;
        return res;
    }
    Martix inv() const {
        Martix res = *this;
        vector<int> is(n+1), js(n+1);
        for (int k = 1; k <= n; ++k) {
            for (int i = k; i <= n; ++i)
                for (int j = k; j <= n; ++j) if (res.a[i][j]) {
                    is[k] = i; js[k] = j; break;
                }
            for (int i = 1; i <= n; ++i) swap(res.a[k][i], res.a[is[k]][i]);
            for (int i = 1; i <= n; ++i) swap(res.a[i][k], res.a[i][js[k]]);
            if (!res.a[k][k]) return Martix(0);
            res.a[k][k] = mul_inverse(res.a[k][k]); // get inv of number
            for (int j = 1; j <= n; ++j) if (j != k)
                res.a[k][j] = res.a[k][j]*res.a[k][k]%MOD;
            for (int i = 1; i <= n; ++i) if (i != k)
                for (int j = 1; j <= n; ++j) if (j != k)
                    res.a[i][j] = (res.a[i][j]+MOD-res.a[i][k]*res.a[k][j]%MOD)%MOD;
            for (int i = 1; i <= n; ++i) if (i != k)
                res.a[i][k] = (MOD-res.a[i][k]*res.a[k][k]%MOD)%MOD;
        }
        for (int k = n; k; --k) {
            for (int i = 1; i <= n; ++i) swap(res.a[js[k]][i], res.a[k][i]);
            for (int i = 1; i <= n; ++i) swap(res.a[i][is[k]], res.a[i][k]);
        }
        return res;
    }
    void print() {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                cout << a[i][j] << " \n"[j==m];
    }
};

Martix<long long> mx;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n;
    long long k;
    cin >> n >> k;
    mx.n = mx.m = n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> mx.a[i][j];
        }
    }
    mx.pow(k).print();
    return 0;
}