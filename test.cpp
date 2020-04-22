#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
int numOfArrays(int n, int m, int k) {
        if (m < k) return 0;
        static const int MOD = 1e9+7;
        long long dp[3][k+3][m+3], sum[3][k+3][m+3];
        memset(dp, 0, sizeof dp);
        memset(sum, 0, sizeof sum);
        dp[0][0][0] = 1;
        for (int i = 0; i <= m; ++i) sum[0][0][i] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int kk = 1; kk <= k; ++kk) {
                sum[i&1][kk][0] = 0;
                dp[i&1][kk][0] = 0;
                for (int j = 1; j <= m; ++j) {
                    dp[i&1][kk][j] = (sum[~i&1][kk][m]-sum[~i&1][kk][j-1]+sum[~i&1][kk-1][j-1])%MOD;
                    sum[i&1][kk][j] = (sum[i&1][kk][j-1]+dp[i&1][kk][j])%MOD;
                }
                cout << i << " " << kk << endl;
                for (int j = 0; j <= m; ++j)  cout << dp[i&1][kk][j] << " \n"[j==m];
                for (int j = 0; j <= m; ++j)    cout << sum[i&1][kk][j] << " \n"[j==m];
            }
        }
        /*
        long long res = 0;
        for (int i = 1; i <= m; ++i) {
            (res += dp[n&1][k][i]) %= MOD;
        }
        return (res+MOD)%MOD;
        */
        return (sum[n&1][k][m]+MOD)%MOD;
    }

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, k;
    cin >> n >> m >> k;
    cout << numOfArrays(n, m, k) << endl;
    return 0;
}