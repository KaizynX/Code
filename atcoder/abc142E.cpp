#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1<<12;
const int M = 1e3+7;

int n, m, res = -1;
int a[M], b[M], c[M];
int dp[M][N];

int main()
{
    cin >> n >> m;
    memset(dp, -1, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i];
        for (int j = 0, tmp; j < b[i]; ++j) {
            cin >> tmp;
            --tmp;
            c[i] += (1<<tmp);
        }
#ifdef DEBUG
        cout << i << " " << c[i] << endl;
#endif
        for (int j = 0; j < (1<<n); ++j) dp[i][j] = dp[i-1][j];
        for (int j = 0; j < (1<<n); ++j) {
            if (dp[i-1][j] == -1) continue;
            if (dp[i][j|c[i]] == -1) dp[i][j|c[i]] = dp[i-1][j]+a[i];
            else dp[i][j|c[i]] = min(dp[i][j|c[i]], dp[i-1][j]+a[i]);
        }
#ifdef DEBUG
        for (int j = 0; j < (1<<n); ++j) cout << j << " " << dp[i][j] << endl;
#endif
        if (dp[i][(1<<n)-1] == -1) continue;
        if (res == -1) res = dp[i][(1<<n)-1];
        else res = min(res, dp[i][(1<<n)-1]);
    }
    cout << res << endl;
    return 0;
}
