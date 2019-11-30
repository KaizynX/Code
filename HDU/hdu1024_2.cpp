#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;
const int M = 1e2+7;
const int INF = 1e9+7;

int n, m;
int a[N], dp[N], mv[N];

int main()
{
    while (scanf("%d %d", &m, &n) == 2) {
        int ms;
        memset(dp, 0, sizeof dp);
        memset(mv, 0, sizeof mv);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", a+i);
        }
        for (int i = 1; i <= m; ++i) {
            ms = -INF;
            for (int j = i; j <= n; ++j) {
                dp[j] = max(dp[j-1], mv[j-1])+a[j];
                mv[j-1] = ms;
                ms = max(ms, dp[j]);
            }
            mv[n] = ms;
        }
        printf("%d\n", ms);
    }
    return 0;
}
