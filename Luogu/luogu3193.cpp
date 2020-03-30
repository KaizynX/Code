/*
 * @Author: Kaizyn
 * @Date: 2020-03-29 19:34:15
 * @LastEditTime: 2020-03-29 20:27:07
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 30;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

int MOD = 998244353;

template <typename T>
struct Martix {
    int n, m;
    T a[N][N];
    Martix(){}
    Martix(const int &_n) : n(_n), m(_n) { init(); }
    Martix(const int &_n, const int &_m) : n(_n), m(_m) { init(); }
    T* operator [] (const int &i) { return a[i]; }
    void init(const int &tag = 0) {
        for (int i = 0; i < n; ++i) memset(a[i], 0, sizeof(T)*(n+1));
        for (int i = 0; i < n; ++i) a[i][i] = tag;
    }
    friend Martix operator * (const Martix &m1, const Martix &m2) {
        Martix res(m1.n, m2.m);
        for (int i = 0; i < res.n; ++i)
            for (int j = 0; j < res.m; ++j)
                for (int k = 0; k < m1.m; ++k)
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
    friend ostream& operator << (ostream &os, Martix<T> &mx) {
        for (int i = 0; i < mx.n; ++i)
            for (int j = 0; j < mx.m; ++j)
                os << mx[i][j] << " \n"[j==mx.m-1];
        return os;
    }
};

int n, m;
int nex[N];
string s;
Martix<int> g;

inline void get_next()
{
    nex[0] = nex[1] = 0;
    for (int i = 1, j = 0; i < (int)s.size(); ++i) {
        while (j && s[i] != s[j]) j = nex[j];
        nex[i+1] = s[i] == s[j] ? ++j : 0;
    }
}

inline void kmp()
{
    for (int i = 0; i < m; ++i) {
        for (int j = 0, k; j <= 9; ++j) {
            for (k = i; k && j != s[k]-'0'; k = nex[k]) {}
            if (j == s[k]-'0') ++k;
            ++g[i][k];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> MOD >> s;
    g.n = g.m = m;
    get_next();
    kmp();
    #ifdef DEBUG
    for (int i = 0; i <= m; ++i) cout << nex[i] << " \n"[i==m];
    cout << g << endl;
    #endif
    g = g.pow(n);
    #ifdef DEBUG
    cout << g << endl;
    #endif
    int res = 0;
    for (int i = 0; i < m; ++i) (res += g[0][i]) %= MOD;
    cout << res << endl;
    return 0;
}