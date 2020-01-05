#include <bits/stdc++.h>

using namespace std;

const int N = 80+3;
const int M = 6500;

int n, m;
int a[N][N], b[N][N];
int mem[N][N][M<<1], *dp[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            dp[i][j] = mem[i][j]+M;

    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> b[i][j];
    dp[0][1][0] = dp[1][0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = -6400; k <= 6400; ++k) {
                dp[i][j][k+a[i][j]-b[i][j]] |= dp[i-1][j][k];
                dp[i][j][k-a[i][j]+b[i][j]] |= dp[i-1][j][k];
                dp[i][j][k+a[i][j]-b[i][j]] |= dp[i][j-1][k];
                dp[i][j][k-a[i][j]+b[i][j]] |= dp[i][j-1][k];
            }
        }
    }
    int res;
    for (int i = 0; ; ++i) {
        if (!dp[n][m][i] && !dp[n][m][-i]) continue;
        res = i;
        break;
    }
    cout << res << endl;
    return 0;
}

