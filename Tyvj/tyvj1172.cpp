#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 4e3+7;
const long long MOD = 2147483648;

int n;
// dp[i][j] number i, last part is j
long long dp[N][N], sum[N][N];

int main()
{
    cin >> n;
    dp[0][0] = 1;
    sum[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            /*
            for (int k = 0; k <= j && k <= i-j; ++k) {
                dp[i][j] += dp[i-j][k];
            }
            */
            dp[i][j] = sum[i-j][min(j, i-j)];
            sum[i][j] = (sum[i][j-1]+dp[i][j])%MOD;
#ifdef DEBUG
            printf("dp[%d][%d]=%lld\n", i, j, dp[i][j]);
#endif
        }
    }
    long long res = 0;
    for (int i = 1; i < n; ++i)
        (res += dp[n][i]) %= MOD;
    cout << res << endl;
    return 0;
}

