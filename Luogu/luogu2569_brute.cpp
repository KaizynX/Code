#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int M = 2e3+7;
const long long INF = 1e18;

int n, m, w;
// dp[i][j] the max value after i'th day keeps j gupiao
long long dp[N][M];

int main()
{
    scanf("%d %d %d", &n, &m, &w);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    for (int i = 1, ap, bp, as, bs; i <= n; ++i) {
        scanf("%d %d %d %d", &ap, &bp, &as, &bs);
        if (ap >= bp) {
            for (int j = 0; j <= as; ++j)
                dp[i][j] = dp[0][0]-j*ap;
            for (int j = 0; j <= m; ++j) {
                for (int k = 1; k <= min(i-w, i-1); ++k) {
                    for(int l = max(0, j-as); l <= j; ++l)
                        dp[i][j] = max(dp[i][j], dp[k][l]-ap*(j-l));
                    for (int l = j; l <= min(m, j+bs); ++l)
                        dp[i][j] = max(dp[i][j], dp[k][l]+bp*(l-j));
                }
            }
        } else {
            for (int j = 0; j <= as; ++j)
                dp[i][j] = dp[0][0]-j*ap+min(bs, as-j)*(bp-ap);
            for (int j = 0; j <= m; ++j) {
                for (int k = 1; k <= min(i-w, i-1); ++k) {
                    for (int l = max(0, j-as); l <= j; ++l)
                        dp[i][j] = max(dp[i][j], dp[k][l]-ap*(j-l)+min(bs, as-(j-l))*(bp-ap));
                    for (int l = j; l <= min(m, j+bs); ++l)
                        dp[i][j] = max(dp[i][j], dp[k][k]+bp*(l-j)+min(as, bs-(l-j))*(bp-ap));
                }
            }
        }
    }
    long long res = dp[n][0];
    for (int i = 1; i <= m; ++i)
        res = max(res, dp[n][i]);
    printf("%lld\n", res);
    return 0;
}
