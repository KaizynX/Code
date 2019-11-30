#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int M = 2e3+7;
const long long INF = 1e18;

int n, m, w;
long long res;
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
        for (int j = 0; j <= as; ++j)
            dp[i][j] = dp[0][0]-j*ap+min(bs, as-j)*max(0, bp-ap);
        for (int j = 0; j <= m; ++j) {
            for (int k = 1; k <= i-w-1; ++k) {
                for (int l = 0; l <= as && j-l >= 0; ++l)
                    dp[i][j] = max(dp[i][j], dp[k][j-l]-l*ap+min(bs, as-l)*max(0, bp-ap));
                for (int l = 0; l <= bs && j+l <= m; ++l)
                    dp[i][j] = max(dp[i][j], dp[k][j+l]+l*bp+min(as, bs-l)*max(0, bp-ap));
            }
            res = max(res, dp[i][j]);
#ifdef DEBUG
            printf("dp[%d][%d]=%lld\n", i, j, dp[i][j]);
#endif
        }
    }
    printf("%lld\n", res);
    return 0;
}
