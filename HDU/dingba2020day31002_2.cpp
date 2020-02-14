#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

int n, m;
int a[N], b[N], dp[N];

int main()
{
    while (scanf("%d %d", &m, &n) == 2 && !(n == -1 && m == -1)) {
        for (int i = 0; i <= m; ++i) dp[i] = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", a+i, b+i);
            for (int j = m; j >= b[i]; --j)
                dp[j] = max(dp[j], dp[j-b[i]]+a[i]);
        }
        printf("%d\n", dp[m]);
    }
    return 0;
}
