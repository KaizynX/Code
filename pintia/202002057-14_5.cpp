#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

char s[N];
long long dp[N][4];

int main()
{
    scanf("%s", s+1);
    int n = strlen(s+1);
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= 3; ++j) {
            dp[i][j] = dp[i-1][j]+dp[i-1][j-1];
            for (int k = i-1; k && i-k <= j; --k) {
                // del i is equal to del [k+1, i]
                if (s[i] == s[k]) {
                    dp[i][j] -= dp[k-1][j-(i-k)];
                    break;
                }
            }
        }
    }
    long long res = 0;
    for (int i = 0; i <= 3; ++i) res += dp[n][i];
    cout << res << endl;
    return 0;
}
