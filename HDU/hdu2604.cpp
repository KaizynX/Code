#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int n, m;
// dp[i][j][k] at pos i, i is j, i-1 is k (0-f, 1-m)
int dp[N][2][2];

int main()
{
    while (cin >> n >> m) {
        if (n == 0) { cout << 0 << endl; continue; }
        if (n == 1) { cout << 2%m << endl; continue; }
        if (n == 2) { cout << 4%m << endl; continue; }
        dp[2][0][0] = dp[2][0][1] = dp[2][1][0] = dp[2][1][1] = 1%m;
        for (int i = 3; i <= n; ++i) {
            dp[i][0][0] = dp[i-1][0][1];
            dp[i][0][1] = dp[i-1][1][1];
            dp[i][1][0] = (dp[i-1][0][0]+dp[i-1][0][1])%m;
            dp[i][1][1] = (dp[i-1][1][0]+dp[i-1][1][1])%m;
        }
        cout << (dp[n][0][0]+dp[n][0][1]+dp[n][1][0]+dp[n][1][1])%m << endl;
    }
    return 0;
}
