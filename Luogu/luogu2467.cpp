#include <bits/stdc++.h>

using namespace std;

const int N = 4200+7;

int n, p;
int dp[N][N][2], s[N][N][2];

int main()
{
    cin >> n >> p;
    dp[1][1][0] = dp[1][1][1] = 1;
    s[1][1][0] = s[1][1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            /*
            for (int k = j; k < i; ++k)
                dp[i][j][0] += dp[i-1][k][1];
            for (int k = 1; k < j; ++k)
                dp[i][j][1] += dp[i-1][k][0];
            */
            dp[i][j][0] = (s[i-1][i-1][1]-s[i-1][j-1][1]+p)%p;
            dp[i][j][1] = s[i-1][j-1][0];
            s[i][j][0] = (s[i][j-1][0]+dp[i][j][0])%p;
            s[i][j][1] = (s[i][j-1][1]+dp[i][j][1])%p;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        (res += (dp[n][i][0]+dp[n][i][1])%p) %= p;
    cout << res << endl;
    return 0;
}
