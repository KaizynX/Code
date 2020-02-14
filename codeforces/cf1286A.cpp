#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int INF = 0x3f3f3f3f;

int n, odd;
// dp[i][j][k] at pos i, use j odd, last is odd/even
int a[N], dp[N][N][2];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        odd += a[i]&1;
    }
    odd = (n+1)/2-odd;
    memset(dp, 0x3f, sizeof dp);
    if (a[1]) {
        dp[1][0][a[1]&1] = 0;
    } else {
        dp[1][0][0] = 0;
        dp[1][1][1] = 0;
    }
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= odd && j <= i; ++j) {
            if (a[i]) {
                if (a[i]&1) {
                    dp[i][j][1] = min(dp[i-1][j][0]+1, dp[i-1][j][1]);
                } else {
                    dp[i][j][0] = min(dp[i-1][j][1]+1, dp[i-1][j][0]);
                }
            } else {
                // choose odd
                if (j > 0) {
                    dp[i][j][1] = min(dp[i-1][j-1][0]+1, dp[i-1][j-1][1]);
                }
                // choose even
                dp[i][j][0] = min(dp[i-1][j][1]+1, dp[i-1][j][0]);
            }
        }
    }
    cout << min(dp[n][odd][0], dp[n][odd][1]) << endl;
    return 0;
}
