/*
 * @Author: Kaizyn
 * @Date: 2020-03-05 16:31:43
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-05 16:40:12
 * @FilePath: \Code\Luogu\luogu1654.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int K = 5;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
double p[N], a[N], b[N], f[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> p[i];
    for (int i = 1; i <= n; ++i)
        a[i] = (a[i-1]+1)*p[i];
    for (int i = 1; i <= n; ++i)
        b[i] = (b[i-1]+2*a[i-1]+1)*p[i];
    for (int i = 1; i <= n; ++i)
        f[i] = (f[i-1]+3*b[i-1]+3*a[i-1]+1)*p[i]+f[i-1]*(1-p[i]);
    printf("%.1f\n", f[n]);
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