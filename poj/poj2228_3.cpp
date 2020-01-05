#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 4e3+7;

int n, m, res;
int a[N], dp[2][N][2];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%d", a+i);

    memset(dp, 0xef, sizeof dp);
    dp[1][0][0] = dp[1][1][1] = 0;
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i&1][j][0] = max(dp[i-1&1][j][0], dp[i-1&1][j][1]);
            if (j) dp[i&1][j][1] = max(dp[i-1&1][j-1][0], dp[i-1&1][j-1][1]+a[i]);
        }
    }
    res = max(dp[n&1][m][0], dp[n&1][m][1]);
    
    memset(dp, 0xef, sizeof dp);
    dp[1][1][1] = a[1];
    for (int i = 2; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            dp[i&1][j][0] = max(dp[i-1&1][j][0], dp[i-1&1][j][1]);
            if (j) dp[i&1][j][1] = max(dp[i-1&1][j-1][0], dp[i-1&1][j-1][1]+a[i]);
        }
    }
    res = max(res, dp[n&1][m][1]);

    printf("%d\n", res);
    return 0;
}
