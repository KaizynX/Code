#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

const int N = 4e3+7;

int n, m, res;
int a[N<<1], dp[2][2][N];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        a[n+i] = a[i];
    }
    memset(dp, -1, sizeof dp);
    dp[0][0][0] = 0;
    for (int i = 1; i <= 2*n; ++i) {
        memset(dp[i&1], -1, sizeof dp[i&1]);
        dp[i&1][0][0] = 0;
        for (int j = 1; j <= m && j <= i; ++j) {
            if (dp[i&1^1][0][j] != -1)
                dp[i&1][0][j] = max(dp[i&1][0][j], dp[i&1^1][0][j]);
            if (dp[i&1^1][1][j] != -1)
                dp[i&1][0][j] = max(dp[i&1][0][j], dp[i&1^1][1][j]);
            if (dp[i&1^1][0][j-1] != -1)
                dp[i&1][1][j] = max(dp[i&1][1][j], dp[i&1^1][0][j-1]);
            if (dp[i&1^1][1][j-1] != -1)
                dp[i&1][1][j] = max(dp[i&1][1][j], dp[i&1^1][1][j-1]+a[i]);
#ifdef DEBUG
            printf("dp[%d][%d] %d %d\n", i, j, dp[i&1][0][j], dp[i&1][1][j]);
#endif
        }
        res = max(res, max(dp[i&1][0][m], dp[i&1][1][m]));
    }
    printf("%d\n", res);
    return 0;
}
