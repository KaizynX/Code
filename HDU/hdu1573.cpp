/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 14:48:22
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 15:11:00
 * @FilePath: \Code\HDU\hdu1573.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 20;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int k, n;
long long a[N], m[N];

template <typename T>
T exgcd(T a, T b, T &x, T &y)
{
    if (!b) { x = 1; y = 0; return a; }
    T d = exgcd(b, a%b, y, x);
    y -= a/b*x;
    return d;
}

template <typename T>
inline T mul_inverse(const T &a, const T &m)
{
    T x, y;
    exgcd(a, m, x, y);
    return (x%m+m)%m;
}

inline int solve()
{
    // EXCRT
    long long M = m[1], res = a[1], x, y, c, d;
    for (int i = 2; i <= n; ++i) {
        d = exgcd(M, m[i], x, y);
        c = (a[i]-res%m[i]+m[i])%m[i];
        if (c%d != 0) { return 0; }
        x = (c/d)*x%(m[i]/d);
        res += x*M;
        M *= m[i]/d;
        res = (res%M+M)%M;
    }
    if (k < res) return 0;
    return (k-res)/M+(res > 0);
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        cin >> k >> n;
        for (int i = 1; i <= n; ++i) cin >> m[i];
        for (int i = 1; i <= n; ++i) cin >> a[i];
        cout << solve() << endl;
    }
    return 0;
}