/*
 * @Author: Kaizyn
 * @Date: 2020-03-07 21:10:26
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-07 21:13:56
 * @FilePath: \Code\atcoder\abc158A.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 10;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int a, b;
string s;

inline void solve()
{
    cin >> s;
    for (char c : s) {
        if (c == 'A') ++a;
        else ++b;
    }
    cout << (a && b ? "Yes" : "No") << endl;
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