#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 4e3+7;

int n, m;
int a[N<<1];
long long dp[2][2][N];

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", a+i);
        a[n+i] = a[i];
    }
    long long res = 0;
    for (int i = 1; i <= 2*n; ++i) {
        for (int j = 1; j <= m && j <= i; ++j) {
            dp[0][i&1][j] = max(dp[0][i&1^1][j], dp[1][i&1^1][j]);
            dp[1][i&1][j] = dp[0][i&1^1][j-1];
            if (j > 1) dp[1][i&1][j] = max(dp[1][i&1][j], dp[1][i&1^1][j-1]+a[i]);
        }
        res = max(res, max(dp[0][i&1][m], dp[1][i&1][m]));
    }
    printf("%lld\n", res);
    return 0;
}
