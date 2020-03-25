/*
 * @Author: Kaizyn
 * @Date: 2020-03-22 19:57:48
 * @LastEditTime: 2020-03-22 20:18:02
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

string s;

inline void solve()
{
    cin >> s;
    int n = s.size();
    string l = s.substr(0, n/2), r = s.substr(n/2+1, n/2);
    string rs = s, rl = l, rr = r;
    reverse(rs.begin(), rs.end());
    reverse(rl.begin(), rl.end());
    reverse(rr.begin(), rr.end());
    cout << (s == rs && l == rl && r == rr ? "Yes" : "No") << endl;
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