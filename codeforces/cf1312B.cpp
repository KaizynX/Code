/*
 * @Author: Kaizyn
 * @Date: 2020-03-09 22:33:27
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-09 22:39:30
 * @FilePath: \Code\HDU\cf1312B.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n;
int a[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    reverse(a+1, a+n+1);
    for (int i = 1; i <= n; ++i) {
        cout << a[i] << " \n"[i==n];
    }
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