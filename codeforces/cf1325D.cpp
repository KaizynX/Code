/*
 * @Author: Kaizyn
 * @Date: 2020-03-14 22:49:24
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-14 23:48:18
 * @FilePath: \Code\codeforces\cf1325D.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

long long u, v;
long long a[5];

inline void solve()
{
    cin >> u >> v;
    int flag = 0;
    if (u == 0 && v == 0) { cout << 0 << endl; return; }
    if (u == v) { cout << 1 << endl << u << endl; return; }
    if ((u&1) != (v&1) || u > v) { cout << -1 << endl; return; }
    // if res == 2
    a[1] = a[2] = a[3] = 0;
    a[1] = u;
    long long vv = v;
    for (int i = 0; i < 63; ++i) {
        if ((u>>i)&1) vv -= 1ll<<i;
    }
    for (int i = 1; i < 63; ++i) {
        if ((vv>>i)&1) {
            if ((a[1]>>(i-1))&1) {
                flag = 1;
                a[2] |= 1ll<<(i-1);
                a[3] |= 1ll<<(i-1);
            }
            a[1] |= 1ll<<(i-1);
            a[2] |= 1ll<<(i-1);
        }
    }
    if (!flag) cout << 2 << endl << a[1] << " " << a[2] << endl;
    else cout << 3 << endl << a[1] << " " << a[2] << " " << a[3] << endl;
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