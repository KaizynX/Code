#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int K = 1e1+7;

int n, m, k;
int a[N][3], s[N][3], dp[N][N][K];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            s[i][j] = s[i-1][j]+a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            for (int t = 1; t <= k; ++t) {
                dp[i][j][t] = max(dp[i-1][j][t], dp[i][j-1][t]);
                for (int l = 0; l < i; ++l)
                    dp[i][j][t] = max(dp[i][j][t], dp[l][j][t-1]+s[i][1]-s[l][1]);
                for (int l = 0; l < j; ++l)
                    dp[i][j][t] = max(dp[i][j][t], dp[i][l][t-1]+s[j][2]-s[l][2]);
                if (i == j) for (int l = 0; l < i; ++l)
                    dp[i][j][t] = max(dp[i][j][t], dp[l][l][t-1]+s[i][1]-s[l][1]+s[i][2]-s[l][2]);
            }
        }
    }
    cout << dp[n][n][k] << endl;
    return 0;
}
