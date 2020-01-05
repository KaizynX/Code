#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;

int n;
// dp[i][j] number i, last part is j
long long dp[N][N];

int main()
{
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            for (int k = 0; k <= j && k <= i-j; ++k) {
                dp[i][j] += dp[i-j][k];
            }
            /*
            for (int k = 1; k <= j; ++k) {
                dp[i][j] += dp[i-k][min(i-k, j)];
            }
            */
#ifdef DEBUG
            printf("dp[%d][%d]=%lld\n", i, j, dp[i][j]);
#endif
        }
    }
    long long res = 0;
    for (int i = 1; i < n; ++i)
        res += dp[n][i];
    cout << res << endl;
    return 0;
}
