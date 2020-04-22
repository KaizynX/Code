/*
 * @Author: Kaizyn
 * @Date: 2020-04-18 12:28:04
 * @LastEditTime: 2020-04-18 13:45:10
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 5e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

string s1, s2;

inline void solve()
{
    cin >> s1 >> s2;
    if (s1 == s2) cout << -1 << endl;
    else cout << max(s1.size(), s2.size()) << endl;
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