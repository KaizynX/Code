#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, m, k, s;
// dp[i][j] kill i's get j tolerate max exp
int dp[N][N];

int main()
{
    while (scanf("%d %d %d %d", &n, &m, &k, &s) == 4) {
        memset(dp, 0, sizeof dp);
        for (int i = 1, a, b; i <= k; ++i) {
            scanf("%d %d", &a, &b);
            for (int j = 1; j <= s; ++j) {
                for (int v = 0; v <= m; ++v)
                    dp[j][v] = max(dp[j][v], dp[j-1][v]);
                for (int v = b; v <= m; ++v) 
                    dp[j][v] = max(dp[j][v], dp[j-1][v-b]+a);
            }
        }
        int res = -1;
        for (int i = m; i; --i)
            if (dp[s][i] >= n)
                res = m-i;
        cout << res << endl;
    }
    return 0;
}
