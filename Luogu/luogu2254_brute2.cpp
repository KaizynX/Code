#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int T = 4e4+7;
const int dx[] = { 0, -1, 1, 0, 0 },
          dy[] = { 0, 0, 0, -1, 1 };

int n, m, k, mt;
int d[T], a[N][N], dp[2][N][N], vis[N][N];
vector<pair<int, int>> v;

int main()
{
    char c;
    int bx, by;
    cin >> n >> m >> bx >> by >> k;
    memset(dp, 0xef, sizeof dp);
    dp[0][bx][by] = 0;
    vis[bx][by] = 1;
    v.emplace_back(bx, by);
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
    for (int t = 1, x, y, nx, ny; t <= mt; ++t) {
        if (!d[t]) continue;
        cur ^= 1;
        for (auto p : v) {
            x = p.first;
            y = p.second;
            dp[cur][x][y] = max(dp[cur][x][y], dp[cur^1][x][y]);
            nx = x+dx[d[t]];
            ny = y+dy[d[t]];
            if (!a[nx][ny]) continue;
            dp[cur][nx][ny] = max(dp[cur][nx][ny], dp[cur^1][x][y]+1);
            if (vis[nx][ny]) continue;
            vis[nx][ny] = 1;
            v.emplace_back(nx, ny);
        }
    }
    for (auto p : v) res = max(res, dp[cur][p.first][p.second]);
    cout << res << endl;
    return 0;
}
