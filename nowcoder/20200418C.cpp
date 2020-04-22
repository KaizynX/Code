/*
 * @Author: Kaizyn
 * @Date: 2020-04-18 12:28:04
 * @LastEditTime: 2020-04-18 13:02:52
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

int n[2];
char s[2][N];
int dp[2][30][30];

inline void solve()
{
    for (int t = 0; t < 2; ++t) {
        scanf("%s", s[t]+1);
        n[t] = strlen(s[t]+1);
        memset(dp[t], 0x3f, sizeof dp[t]);
        for (int j = 0; j < 26; ++j) {
            int tmp = 1;
            while (tmp <= n[t] && s[t][tmp] != 'a'+j) ++tmp;
            dp[t][1][j] = tmp;
        }
        for (int i = 2; i <= 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k <= j; ++k) {
                    int tmp = dp[t][i-1][k]+1;
                    while (tmp <= n[t] && s[t][tmp] != 'a'+j) ++tmp;
                    dp[t][i][j] = min(dp[t][i][j], tmp);
                }
            }
        }
    }
    #ifdef DEBUG
    for (int t = 0; t < 2; ++t) {
        for (int i = 1; i <= 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                cout << dp[t][i][j] << " \n"[j==2];
            }
        }
    }
    #endif
    int res = -1;
    for (int i = 1; i <= 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            if ((dp[0][i][j] <= n[0] && dp[1][i][j] > n[1]) ||
                (dp[0][i][j] > n[0] && dp[1][i][j] <= n[0])) {
                res = max(res, i);
            }
        }
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