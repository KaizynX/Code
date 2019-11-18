#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 3e2+7;
const long long INF = 1e18;

int n, k;
int h[N];
long long res = INF;
// dp[i][j] keep i'th , del j's before i
long long dp[N][N];

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> h[i];

    for (int i = 0; i <= n+1; ++i)
        for (int j = 0; j <= n+1; ++j)
            dp[i][j] = INF;
    dp[0][0] = 0;

    for (int i = 1; i <= n+1; ++i) {
        for (int j = 0; j < i && j <= k; ++j) {
            for (int k = 0; k <= j && i-k-1 >= 0; ++k) {
                dp[i][j] = min(dp[i][j], dp[i-k-1][j-k]+max(0, h[i]-h[i-k-1]));
            }
#ifdef DEBUG
            printf("dp[%d][%d]=%lld\n", i, j, dp[i][j]);
#endif
            if (i == n+1) res = min(res, dp[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}
