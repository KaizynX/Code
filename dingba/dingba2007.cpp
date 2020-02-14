#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int M = 5e3+7;
const int INF = 0x3f3f3f3f;

int n;
int a[N], b[N];
// dp[][i] the min time b cost when a cost time i
int dp[2][M];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        memset(dp[i&1], 0x3f, sizeof dp[0]);
        // give to a
        for (int j = a[i]; j <= 5000; ++j)
            dp[i&1][j] = min(dp[i&1][j], dp[i-1&1][j-a[i]]);
        // give to b
        for (int j = 0; j <= 5000; ++j)
            dp[i&1][j] = min(dp[i&1][j], dp[i-1&1][j]+b[i]);
    }
    int res = INF;
    for (int j = 0; j <= 5000; ++j)
        res = min(res, max(j, dp[n&1][j]));
    cout << res << endl;
    return 0;
}
