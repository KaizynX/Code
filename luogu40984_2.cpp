#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

const int Maxn = 1e2+7;
const int Maxm = 1e4+7;

int n, m;
long long sum[Maxn], dp[2][Maxn];

int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1, a; i <= m; ++i)
    {
        memset(dp[i&1]+1, 0x80, sizeof(long long)*n);
        for(int j = 1; j <= n; ++j)
        {
            scanf("%d", &a);
            sum[j] = sum[j-1]+a;
            // from [1, i-1] choose k and from [i] choose j-k
            for(int k = 0; k <= j; ++k)
                dp[i&1][j] = max(dp[i&1][j], dp[(i+1)&1][k]+sum[j-k]);
        }
    }
    printf("%lld\n", dp[m&1][n]);
    return 0;
}
