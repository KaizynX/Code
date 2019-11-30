#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 2e2+7;
const int T = 4e4+7;
const int dx[] = { 0, -1, 1, 0, 0 },
          dy[] = { 0, 0, 0, -1, 1 };

int n, m, k, mt;
int d[T], a[N][N], dp[2][N][N];

int main()
{
    char c;
    int bx, by;
    cin >> n >> m >> bx >> by >> k;
    memset(dp, 0xef, sizeof dp);
    dp[0][bx][by] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> c;
            if (c == '.') a[i][j] = 1;
        }
    }
    for (int i = 1, s, t, dd; i <= k; ++i) {
        cin >> s >> t >> dd;
        mt = max(mt, t);
        for (int j = s; j <= t; ++j) d[j] = dd;
    }

    int res = 0, cur = 0;
    for (int t = 1, lx, ly; t <= mt; ++t) {
        if (!d[t]) continue;
        cur ^= 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (!a[i][j]) continue;
                dp[cur][i][j] = dp[cur^1][i][j];
                lx = i-dx[d[t]];
                ly = j-dy[d[t]];
                if (a[lx][ly]) dp[cur][i][j] = max(dp[cur^1][i][j], dp[cur^1][lx][ly]+1);
                if (t == mt) res = max(res, dp[cur][i][j]);
            }
        }
    }
    cout << res << endl;
    return 0;
}
