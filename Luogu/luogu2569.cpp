#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 2e3+7;
const long long INF = 1e18;

int n, m, w, head, tail;
int q[N];
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
        head = tail = 0;
        for (int j = 0; j <= m; ++j) {
            while (head < tail && q[head+1] < j-as) ++head;
            while (head < tail && mv[q[tail]]-ap*(j-q[tail]) <= mv[j]) --tail;
            q[++tail] = j;
            dp[i][j] = max(dp[i][j], mv[q[head+1]]-ap*(j-q[head+1]));
        }
        head = tail = 0;
        for (int j = m; j >= 0; --j) {
            while (head < tail && q[head+1] > j+bs) ++head;
            while (head < tail && mv[q[tail]]+bp*(q[tail]-j) <= mv[j]) --tail;
            q[++tail] = j;
            dp[i][j] = max(dp[i][j], mv[q[head+1]]+bp*(q[head+1]-j));
            res = max(res, dp[i][j]);
        }
#ifdef DEBUG
        for (int j = 0; j <= m; ++j)
            printf("dp[%d][%d]=%lld\n", i, j, dp[i][j]);
#endif
        if (i-w <= 0) continue;
        for (int j = 0; j <= m; ++j)
            mv[j] = max(mv[j], dp[i-w][j]);
    }
    printf("%lld\n", res);
    return 0;
}
