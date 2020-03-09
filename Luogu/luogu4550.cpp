/*
 * @Author: Kaizyn
 * @Date: 2020-03-05 17:05:01
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-05 17:08:03
 * @FilePath: \Code\Luogu\luogu4550.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e4+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
double a[N], f[N];

inline void solve()
{
    // if need x times, ans = (x^2+x)/2
    // a[i] is the expection times to buy i's
    // f[i] is the tiems^2 to ...
    cin >> n;
    for (int i = 1; i <= n; ++i)
        a[i] = a[i-1]+n/(n-i+1.0);
    for (int i = 1; i <= n; ++i)
        f[i] = 2*(i-1.0)/(n-i+1.0)*a[i]+f[i-1]+2*a[i-1]+n/(n-i+1.0);
    printf("%.2f\n", (f[n]+a[n])/2);
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