#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int B = 8;
const int INF = 0x3f3f3f3f;

int testcase, n;
int t[N], b[N];
int dp[N][1<<B][N];

int main()
{
    cin >> testcase;
    while (testcase--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> t[i] >> b[i];
            b[i] = min(b[i], n-i);
        }
        memset(dp, 0x3f, sizeof dp);
        dp[1][0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= b[i]; ++j) {
                dp[i][1<<j][j] = dp[i-1]
            }
            for (int j = 0; j < (1<<(b[i]+1)); ++j) {
                for (int k = 0; k <= b[i]; ++k) if (!((j>>k)&1)) {
                    int cnt = 0;
                    for (int l = k+1; l <= b[i]; ++l) cnt += (j>>l)&1;
                    if (cnt > b[i+k]) continue;
                    for (int l = 0; l <= b[i]; ++l) if ((j>>l)&1)
                        dp[i][j|(1<<k)][k] = min(dp[i][j|(1<<k)][k],
                            dp[i][j][l]+t[i+l]^t[i+k]);
                }
                if (j&1) for (int k = 0; k <= b[i]; ++k) if ((j>>k)&1)
                    dp[i+1][j>>1][k] = dp[i][j][k];
            }
        }
        cout << dp[n][1][0] << endl;
    }
    return 0;
}
