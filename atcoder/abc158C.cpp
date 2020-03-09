/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 21:03:11
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 21:06:29
 * @FilePath: \Code\atcoder\abc158C.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

inline void solve()
{
    int a, b;
    cin >> a >> b;
    for (int i = 13; i <= 1000; ++i) {
        if ((int)(i*.08) == a && (int)(i*.1) == b) {
            cout << i << endl;
            return;
        }
    }
    cout << -1 << endl;
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