/*
 * @Author: Kaizyn
 * @Date: 2020-03-12 21:47:10
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-12 21:50:39
 * @FilePath: \Coded:\Blog\source\_posts\cf1324A.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, a[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    int flag = 1;
    for (int i = 2; i <= n; ++i) {
        if (abs(a[i]-a[i-1])&1) flag = 0;
    }
    cout << (flag ? "YES" : "NO") << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}