/*
 * @Author: Kaizyn
 * @Date: 2020-03-19 22:33:10
 * @LastEditTime: 2020-03-19 22:53:29
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N], b[N], x[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> b[i];
    // b[i] = a[i]-x[i]
    for (int i = 1; i <= n; ++i) {
        a[i] = b[i]+x[i];
        x[i+1] = max(x[i], a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " \n"[i==n];
    }
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