/*
 * @Author: Kaizyn
 * @Date: 2020-03-09 22:33:10
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-09 22:36:58
 * @FilePath: \Code\HDU\cf1312A.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m;

inline void solve()
{
    cin >> n >> m;
    cout << (n%m ? "NO" : "YES") << endl;
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