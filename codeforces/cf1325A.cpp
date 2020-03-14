/*
 * @Author: Kaizyn
 * @Date: 2020-03-14 22:32:23
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-14 22:37:48
 * @FilePath: \Code\codeforces\cf1325A.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int x;

inline void solve()
{
    cin >> x;
    cout << 1 << " " << x-1 << endl;
    /*
    for (int i = 2; i*i <= x; ++i) {
        if (x%i) continue;
        cout << i << " " << x-i << endl;
    }
    */
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