/*
 * @Author: Kaizyn
 * @Date: 2020-03-06 17:34:15
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-06 17:39:42
 * @FilePath: \Code\Luogu\luogu3802.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 10;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int a[9];

inline void solve()
{
    int n = 0, fac = 1;
    for (int i = 1; i <= 7; ++i) {
        cin >> a[i];
        n += a[i];
        fac *= i;
    }
    if (n < 7) { printf("0.000\n"); return; }
    double res = fac*(n-6.0);
    for (int i = 1; i <= 7; ++i) {
        res *= a[i]/(n-i+1.0);
    }
    printf("%.3f\n", res);
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}