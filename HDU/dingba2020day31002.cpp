#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, m;
int a[N], b[N], dp[N][N];

int main()
{
    while (scanf("%d %d", &m, &n) == 2 && !(n == -1 && m == -1)) {
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", a+i, b+i);
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];
                if (j >= b[i])
                    dp[i][j] = max(dp[i][j], dp[i-1][j-b[i]]+a[i]);
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
