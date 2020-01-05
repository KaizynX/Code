#include <bits/stdc++.h>

using namespace std;

const int N = 4200+7;

int n, p;
int dp[2][N][2], s[2][N][2];

int main()
{
    cin >> n >> p;
    dp[1][1][0] = dp[1][1][1] = 1;
    s[1][1][0] = s[1][1][1] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            dp[i&1][j][0] = (s[i-1&1][i-1][1]-s[i-1&1][j-1][1]+p)%p;
            dp[i&1][j][1] = s[i-1&1][j-1][0];
            s[i&1][j][0] = (s[i&1][j-1][0]+dp[i&1][j][0])%p;
            s[i&1][j][1] = (s[i&1][j-1][1]+dp[i&1][j][1])%p;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i)
        (res += (dp[n&1][i][0]+dp[n&1][i][1])%p) %= p;
    cout << res << endl;
    return 0;
}
