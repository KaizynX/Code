/*
 * @Author: Kaizyn
 * @Date: 2020-03-04 17:32:31
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-04 17:49:30
 * @FilePath: \Code\codeforces\cf1305E.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m;
int a[N];

inline int calc_max()
{
    int res = 0;
    for (int i = 1; i < n; ++i) res += i/2;
    return res;
}

inline void solve()
{
    cin >> n >> m;
    if (m > calc_max()) { cout << -1 << endl; return; }
    a[1] = 1; a[2] = 2;
    int i, cnt = 0;
    for (i = 3; i <= n; ++i) {
        if (cnt+(i-1)/2 > m) break;
        a[i] = i;
        cnt += (i-1)/2;
    }
    if (m > cnt) a[i] = a[i-1]+a[i-(m-cnt)*2], ++i;
    a[n+1] = 1e9;
    for (int j = n; j >= i; --j) a[j] = a[j+1]-a[i-1]-1;
    for (i = 1; i <= n; ++i) cout << a[i] << " \n"[i==n];
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