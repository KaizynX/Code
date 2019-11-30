#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;
const int M = 1e2+7;
const int INF = 1e9+7;

int n, m;
int a[N], dp[N][M], mx[N][M];

int main()
{
    while (scanf("%d %d", &m, &n) == 2) {
        int res = -INF;
        /*
        memset(dp, 0xef, sizeof dp);
        memset(mx, 0xef, sizeof mx);
        for (int i = 0; i <= m; ++i) {
            dp[0][i] = 0;
        }
        */
        memset(dp, 0, sizeof dp);
        memset(mx, 0, sizeof mx);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
            for (int j = 1; j <= i && j <= m; ++j) {
                dp[i][j] = max(dp[i-1][j], mx[i-1][j-1])+a[i];
                mx[i][j] = max(mx[i-1][j], dp[i][j]);
            }
            res = max(res, dp[i][m]);
        }
        printf("%d\n", res);
    }
    return 0;
}
