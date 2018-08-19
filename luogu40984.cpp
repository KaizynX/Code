#include <cstdio>
#include <iostream>

using namespace std;

const int Maxn = 1e2+7;
const int Maxm = 1e4+7;

int n, m, a[Maxn][Maxm];
long long sum[Maxn][Maxm], dp[Maxn][Maxm];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
        {
            scanf("%d", &a[i][j]);
            sum[i][j] = sum[i][j-1]+a[i][j];
        }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= m; ++j)
            for(int k = 0; k <= j; ++k)
                dp[i][j] = max(dp[i][j], dp[i-1][k]+sum[i][j-k]);
    printf("%lld\n", dp[n][m]);
    return 0;
}
