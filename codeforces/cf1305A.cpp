/*
 * @Author: Kaizyn
 * @Date: 2020-03-03 22:28:45
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-03 22:37:22
 * @FilePath: \Code\codeforces\cf1305A.cpp
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
int a[N], b[N];

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort(a+1, a+n+1);
    sort(b+1, b+n+1);
    for (int i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
    for (int i = 1; i <= n; ++i) cout << b[i] << " \n"[i==n];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}
