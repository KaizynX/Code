/*
 * @Author: Kaizyn
 * @Date: 2020-03-08 22:25:42
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-08 22:28:14
 * @FilePath: \Code\upc\20200308B.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

struct Node
{
    int v, t;
    friend bool operator < (const Node &n1, const Node &n2) {
        return -n1.v*n2.t < -n2.v*n1.t;
    }
} a[N];

int n;

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i].v >> a[i].t;
    }
    sort(a+1, a+n+1);
    long long res = 0;
    for (int i = 1, t = 0; i <= n; ++i) {
        t += a[i].t;
        res += 1ll*t*a[i].v;
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