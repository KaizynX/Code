/*
 * @Author: Kaizyn
 * @Date: 2020-04-27 23:13:30
 * @LastEditTime: 2020-04-27 23:27:19
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e5+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

string s;
long long dp[2][2019];

inline void solve()
{
    cin >> s;
    int n = s.size();
    long long res = 0;
    dp[0][s[0]-'0'] = 1;
    for (int i = 1; i < n; ++i) {
        memset(dp[i&1], 0, sizeof dp[i&1]);
        for (int j = 0; j < 2019; ++j) {
            dp[i&1][(j*10+s[i]-'0')%2019] += dp[~i&1][j];
        }
        ++dp[i&1][s[i]-'0'];
        #ifdef DEBUG
        if (dp[i&1][0]) cout << i << endl;
        #endif
        res += dp[i&1][0];
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