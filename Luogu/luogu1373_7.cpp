#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 8e2+3;
const int K = 20;
const int MOD = 1e9+7;

int n, m, k, res;
int a[N][N];
int mem[2][2][N][K<<1], *dp[2][2][N];

int main()
{
    for (int t = 0; t < 2; ++t)
    for (int i = 0; i < 2; ++i)
    for (int j = 0; j < N; ++j)
        dp[t][i][j] = mem[t][i][j]+K;

    scanf("%d %d %d", &n, &m, &k);
    ++k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            scanf("%d", &a[i][j]), a[i][j] %= k;

    for (int i = 1, b; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            b = a[i][j];
            for (int kk = -k+1; kk < k; ++kk) {
                int &dp0 = dp[0][i&1][j][kk],
                    &dp1 = dp[1][i&1][j][kk];
                dp0 = (dp[1][i&1^1][j][(kk-b)%k]+dp[1][i&1][j-1][(kk-b)%k])%MOD;
                dp1 = (dp[0][i&1^1][j][(kk+b)%k]+dp[0][i&1][j-1][(kk+b)%k])%MOD;
            }
            (++dp[0][i&1][j][b]) %= MOD;
            (res += dp[1][i&1][j][0]) %= MOD;
        }
    }
    cout << res << endl;
    return 0;
}
