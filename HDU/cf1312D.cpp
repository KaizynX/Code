/*
 * @Author: Kaizyn
 * @Date: 2020-03-09 22:52:00
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-09 23:16:52
 * @FilePath: \Code\HDU\cf1312D.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m;
long long fac[N], inv[N];

void exgcd(long long a, long long b, long long &x, long long &y)
{
    if (!b) { x = 1; y = 0; return; }
    exgcd(b, a%b, y, x);
    y -= (a/b)*x;
}

long long mul_inverse(const long long &a)
{
    long long x, y;
    exgcd(a, MOD, x, y);
    return (x%MOD+MOD)%MOD;
}

inline long long C(const int &p, const int &q)
{
    return fac[p]*inv[q]%MOD*inv[p-q]%MOD;
}

inline void solve()
{
    cin >> n >> m;
    // if (n == 2) { cout << 0 << endl; return; }
    fac[0] = inv[0] = 1;
    for (int i = 1; i <= m; ++i) {
        fac[i] = fac[i-1]*i%MOD;
        inv[i] = mul_inverse(fac[i]);
    }
    long long res = 0;
    // pair can't be the biggest
    // choose n-1 diffrent number from m
    // except the biggest one, pair if one of n-3
    // the pair must at two side
    // and choose who on left 
    // i is the pos of biggest
    for (int i = 2; i <= n-1; ++i) {
        res = (res+(n-2)*C(n-3, i-2)%MOD)%MOD;
    }
    res = res*C(m, n-1)%MOD;
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}