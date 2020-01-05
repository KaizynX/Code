#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int INF = 0x3f3f3f3f;

int n, m;
int a[N][N], dp[2][N][N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j];
        }
    }
    int res = INF;
    memset(dp[0], 0x3f, sizeof dp[0]);
    dp[0][1][2][3] = 0;
    for (int t = 1, q; t <= m; ++t) {
        cin >> q;
        memset(dp[t&1], 0x3f, sizeof dp[0]);
        for (int i = 1; i <= n; ++i) {
            if (i == q) continue;
            for (int j = 1; j <= n; ++j) {
                if (i == j || j == q) continue;
                for (int k = 1; k <= n; ++k) {
                    if (k == i || k == j) continue;
                    dp[t&1][i][j][q] = min(dp[t&1][i][j][q], dp[t&1^1][i][j][k]+a[k][q]);
                    dp[t&1][i][q][j] = min(dp[t&1][i][q][j], dp[t&1^1][i][k][j]+a[k][q]);
                    dp[t&1][q][i][j] = min(dp[t&1][q][i][j], dp[t&1^1][k][i][j]+a[k][q]);
                }
                if (t == m) {
                    res = min(res, dp[t&1][i][j][q]);
                    res = min(res, dp[t&1][i][q][j]);
                    res = min(res, dp[t&1][q][i][j]);
                }
            }
        }
    }
    cout << res << endl;
    return 0;
}
