/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 13:29:34
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 13:31:22
 * @FilePath: \Code\pintia\2020031501.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N];

inline void solve()
{
    cin >> n;
    // a[i]-a[j] > a[i]+a[j]
    // -a[j] > a[j]
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        if (a[i] < 0) res += n-1;
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