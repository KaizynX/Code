#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int M = 1e5+7;

int n, m;
int a[N], c[N];
int dp[M];

int main()
{
    while (scanf("%d %d", &n, &m) == 2 && n|m) {
        memset(dp, 0, sizeof(int)*(m+7));
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        for (int i = 1; i <= n; ++i) scanf("%d", c+i);
        for (int i = 1; i <= n; ++i) {
            for (int b = 1; b < c[i]; c[i] -= b, b <<= 1)
                for (int j = m; j >= a[i]*b; --j)
                    dp[j] = max(dp[j], dp[j-a[i]*b]+a[i]*b);
            for (int j = m; j >= a[i]*c[i]; --j)
                dp[j] = max(dp[j], dp[j-a[i]*c[i]]+a[i]*c[i]);
        }
        int res = 0;
        for (int i = 1; i <= m; ++i)
            res += dp[i] == i;
        printf("%d\n", res);
    }
    return 0;
}
