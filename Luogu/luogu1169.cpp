#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+7;

int n, m;
int a[N][N], dp[N][N], lif[N][N], rig[N][N], up[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        a[i][0] = a[i][1], a[i][m+1] = a[i][m];
    for (int j = 1; j <= m; ++j)
        a[0][j] = a[1][j];
    a[0][0] = a[1][1]^1;

    int res = 1;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == a[i][j-1] || a[i][j] == a[i-1][j] || a[i][j] != a[i-1][j-1]) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]))+1;
            }
            res = max(res, dp[i][j]);
        }
    }
    cout << res*res << endl;

    res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j]^a[i-1][j]) up[i][j] = up[i-1][j]+1;
            else up[i][j] = 1;
            if (a[i][j]^a[i][j-1]) lif[i][j] = lif[i][j-1]+1;
            else lif[i][j] = 1;
        }
        for (int j = m; j; --j) {
            if (a[i][j]^a[i][j+1]) rig[i][j] = rig[i][j+1]+1;
            else rig[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (up[i][j] > 1) {
                lif[i][j] = min(lif[i][j], lif[i-1][j]);
                rig[i][j] = min(rig[i][j], rig[i-1][j]);
            }
            res = max(res, up[i][j]*(lif[i][j]+rig[i][j]-1));
        }
    }
    cout << res << endl;
    return 0;
}
