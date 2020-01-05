#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int M = 1e3+7;
const int INF = 0x3f3f3f3f;

int n, m;
// dp[i][j][k] min cost three people at(i, j, k)
// mv[i][j][k] the min cost two people at (j, k) to get to next query
int b[M], a[N][N], dp[2][N][N][N], mv[2][3][N][N];

inline void update(int &x, const int &y) { if (y < x) x = y; }

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= m; ++i) cin >> b[i];

    int res = INF;
    memset(dp[0], 0x3f, sizeof dp[0]);
    memset(mv[0], 0x3f, sizeof mv[0]);
    dp[0][1][2][3] = 0;
    mv[0][0][2][3] = a[1][b[1]];
    mv[0][1][1][3] = a[2][b[1]];
    mv[0][2][1][2] = a[3][b[1]];
    for (int t = 1, q, qq; t <= m; ++t) {
        q = b[t]; qq = b[t+1];
        memset(dp[t&1], 0x3f, sizeof dp[0]);
        memset(mv[t&1], 0x3f, sizeof mv[0]);
        for (int i = 1; i <= n; ++i) {
            if (i == q) continue;
            for (int j = 1; j <= n; ++j) {
                if (i == j || j == q) continue;
                dp[t&1][q][i][j] = mv[t&1^1][0][i][j];
                dp[t&1][i][q][j] = mv[t&1^1][1][i][j];
                dp[t&1][i][j][q] = mv[t&1^1][2][i][j];
                update(mv[t&1][0][i][j], dp[t&1][q][i][j]+a[q][qq]);
                update(mv[t&1][0][q][j], dp[t&1][i][q][j]+a[i][qq]);
                update(mv[t&1][0][j][q], dp[t&1][i][j][q]+a[i][qq]);
                update(mv[t&1][1][q][j], dp[t&1][q][i][j]+a[i][qq]);
                update(mv[t&1][1][i][j], dp[t&1][i][q][j]+a[q][qq]);
                update(mv[t&1][1][i][q], dp[t&1][i][j][q]+a[j][qq]);
                update(mv[t&1][2][q][i], dp[t&1][q][i][j]+a[j][qq]);
                update(mv[t&1][2][i][q], dp[t&1][i][q][j]+a[j][qq]);
                update(mv[t&1][2][i][j], dp[t&1][i][j][q]+a[q][qq]);
            }
        }
    }
    for (int i = 1, q = b[m]; i <= n; ++i) {
        if (i == q) continue;
        for (int j = 1; j <= n; ++j) {
            if (i == j || q == j) continue;
            res = min(res, dp[m&1][i][j][q]);
            res = min(res, dp[m&1][i][q][j]);
            res = min(res, dp[m&1][q][i][j]);
        }
    }
    cout << res << endl;
    return 0;
}

