#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;
const int M = 40;

int n, m;
// dp[i][j][k] at pos i, i is j, i-1 is k (0-f, 1-m)
int dp[N][2][2], f[M][N];

inline void init()
{
    for (int k = 1; k <= 30; ++k) {
        f[k][0] = 0;
        f[k][1] = 2%k;
        f[k][2] = 4%k;
        dp[2][0][0] = dp[2][0][1] = dp[2][1][0] = dp[2][1][1] = 1%k;
        for (int i = 3; i <= 1e6; ++i) {
            dp[i][0][0] = dp[i-1][0][1];
            dp[i][0][1] = dp[i-1][1][1];
            dp[i][1][0] = (dp[i-1][0][0]+dp[i-1][0][1])%k;
            dp[i][1][1] = (dp[i-1][1][0]+dp[i-1][1][1])%k;
            f[k][i] = (dp[i][0][0]+dp[i][0][1]+dp[i][1][0]+dp[i][1][1])%k;
        }
    }
}

int main()
{
    init();
    while (cin >> n >> m) {
        cout << f[m][n] << endl;
    }
    return 0;
}
