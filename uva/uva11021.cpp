/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 10:36:21
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 10:50:49
 * @FilePath: \Code\uva\uva11021.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, k, m;
double p[N], f[N];

template <typename T>
inline T qpow(T a, int p)
{
    T res = 1;
    while (p) {
        if (p&1) res *= a;
        a *= a;
        p >>= 1;
    }
    return res;
}

inline double solve()
{
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i) cin >> p[i];
    // f[i] is the probility one die within i day(s)
    f[0] = 0;
    f[1] = p[0];
    for (int i = 2; i <= m; ++i) {
        f[i] = 0;
        for (int j = 0; j < n; ++j) {
            f[i] += p[j]*qpow(f[i-1], j);
        }
    }
    return qpow(f[m], k);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        printf("Case #%d: %.7f\n", i, solve());
    }
    return 0;
}