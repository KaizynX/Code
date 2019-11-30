#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 2e3+7;
const long long INF = 1e18;

int n, m, w;
long long res;
// dp[i][j] the max value after i'th day keeps j gupiao
long long dp[N][N], mv[N];

int main()
{
    scanf("%d %d %d", &n, &m, &w);
    for (int i = 0; i <= n; ++i)
        for (int j = 0; j <= m; ++j)
            dp[i][j] = -INF;
    dp[0][0] = 0;
    for (int i = 0; i <= m; ++i) mv[i] = dp[0][i];

    for (int i = 1, ap, bp, as, bs; i <= n; ++i) {
        scanf("%d %d %d %d", &ap, &bp, &as, &bs);
        for (int j = 0; j <= m; ++j) {
            for (int k = 0; k <= as && j-k >= 0; ++k)
                dp[i][j] = max(dp[i][j], mv[j-k]-k*ap+min(bs, as-k)*max(0, bp-ap));
            for (int k = 0; k <= bs && j+k <= m; ++k)
                dp[i][j] = max(dp[i][j], mv[j+k]+k*bp+min(as, bs-k)*max(0, bp-ap));
            res = max(res, dp[i][j]);
#ifdef DEBUG
            printf("dp[%d][%d]=%lld\n", i, j, dp[i][j]);
#endif
        }
        if (i-w <= 0) continue;
        for (int j = 0; j <= m; ++j)
            mv[j] = max(mv[j], dp[i-w][j]);
    }
    printf("%lld\n", res);
    return 0;
}
