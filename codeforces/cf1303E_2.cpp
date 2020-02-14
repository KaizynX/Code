#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 4e2+7;

int T, n, m;
char s[N], t[N];
int dp[N][N];
// dp[i][j] = k, in s[0~i] get t[0~j] && t[mid+1~mid+k]

int main()
{
    scanf("%d", &T);
    while (T--) {
        int flag = 0;
        scanf("%s%s", s+1, t+1);
        n = strlen(s+1);
        m = strlen(t+1);
        for (int mid = 1; mid <= m; ++mid) {
            memset(dp, -1, sizeof dp);
            dp[0][0] = 0;
            for (int i = 1; i <= n; ++i) {
                memcpy(dp[i], dp[i-1], sizeof(int)*(mid+3));
                for (int j = 1; j <= mid; ++j) {
                    if (s[i] != t[j] || dp[i-1][j-1] == -1) continue;
                    dp[i][j] = max(dp[i][j], dp[i-1][j-1]);
                }
                for (int j = 0; j <= mid; ++j) {
                    if (dp[i-1][j] == -1 || mid+1+dp[i-1][j] > m ||
                        s[i] != t[mid+1+dp[i-1][j]]) continue;
                    dp[i][j] = max(dp[i][j], dp[i-1][j]+1);
                }
#ifdef DEBUG
                for (int j = 0; j <= mid; ++j)
                    printf("%d%c", dp[i][j], " \n"[j==mid]);
#endif
                if (dp[i][mid] == m-mid) { flag = 1; break; }
            }
        }
        puts((flag ? "YES" : "NO"));
    }
    return 0;
}
