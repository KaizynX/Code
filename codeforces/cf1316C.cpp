/*
 * @Author: Kaizyn
 * @Date: 2020-03-04 22:49:36
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-05 10:00:58
 * @FilePath: \Code\codeforces\cf1316C.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, p;
int a[N], b[N];

inline long long check(const int &x)
{
    long long res = 0;
    for (int i = 0; i <= x && i < n; ++i) {
        if (x-i >= 0 && x-i < m)
        res = (res+1ll*a[i]*b[x-i])%p;
    }
    return res;
}

inline void solve()
{
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < m; ++i) cin >> b[i];

    int i, j;
    for (i = 0; i < n; ++i) if (a[i]%p) break;
    for (j = 0; j < m; ++j) if (b[j]%p) break;
    cout << i+j << endl;
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