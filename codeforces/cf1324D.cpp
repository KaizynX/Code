/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 22:00:59
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 22:04:09
 * @FilePath: \Code\codeforces\cf1324D.cpp
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
int a[N], b[N], d[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= n; ++i) d[i] = a[i]-b[i];
    // a[i]+a[j] > b[i]+b[j]
    // a[i]-b[i] > -(a[j]-b[j])
    sort(d+1, d+n+1);
    long long res = 0;
    for (int i = 2; i <= n; ++i) {
        int p = upper_bound(d+1, d+i, -d[i])-d;
        res += i-p;
    }
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