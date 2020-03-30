/*
 * @Author: Kaizyn
 * @Date: 2020-03-28 21:04:12
 * @LastEditTime: 2020-03-28 21:05:12
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 998244353;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

string s;

inline void solve()
{
    cin >> s;
    cout << (s[2] == s[3] && s[4] == s[5] ? "Yes" : "No") << endl;
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