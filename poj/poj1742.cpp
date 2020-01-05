#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e2+7;
const int M = 1e5+7;

int n, m;
int a[N], c[N];
int dp[M], cnt[M];

int main()
{
    while (scanf("%d %d", &n, &m) && n|m) {
        for (int i = 1; i <= n; ++i) scanf("%d", a+i);
        for (int i = 1; i <= n; ++i) scanf("%d", c+i);
        for (int i = 1; i <= m; ++i) dp[i] = 0;
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) cnt[j] = 0;
            for (int j = a[i]; j <= m; ++j) {
                if (dp[j]) continue;
                if (dp[j-a[i]] && cnt[j-a[i]] < c[i]) {
                    dp[j] = 1;
                    cnt[j] = cnt[j-a[i]]+1;
                }
            }
        }
        int res = 0;
        for (int i = 1; i <= m; ++i) res += dp[i];
        printf("%d\n", res);
    }
    return 0;
}
