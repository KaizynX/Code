#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int MOD = 1e9+7;
#ifndef DEBUG
const int N = 1e5+7;
#else
const int N = 1e2+7;
#endif

int T, n, m;
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        memset(dp, 0, sizeof dp);
        dp[0][1] = 1;
        for (int t = 1; t < m; ++t) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (i == j) continue;
                    dp[t][i] = (dp[t][i]+dp[t-1][j])%MOD;
                }
            }
        }
        for (int i = 2; i <= n; ++i)
            dp[m][1] = (dp[m][1]+dp[m-1][i])%MOD;
        cout << dp[m][1] << endl;
    }
    return 0;
}
