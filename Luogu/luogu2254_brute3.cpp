#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int T = 4e4+7;
const int dx[] = { 0, -1, 1, 0, 0 },
          dy[] = { 0, 0, 0, -1, 1 };

int n, m, k, mt;
int d[T], a[N][N], dp[2][N][N], vis[N][N];
int xx[T], yy[T], tot;

inline void add(int x, int y) {
    if (vis[x][y]) return;
    ++tot;
    vis[x][y] = 1;
    xx[tot] = x;
    yy[tot] = y;
}

int main()
{
    char c;
    int bx, by;
    cin >> n >> m >> bx >> by >> k;
    memset(dp, 0xef, sizeof dp);
    dp[0][bx][by] = 0;
    add(bx, by);
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
    for (int t = 1, nx, ny; t <= mt; ++t) {
        if (!d[t]) continue;
        cur ^= 1;
        for (int i = 1, sz = tot; i <= sz; ++i) {
            dp[cur][xx[i]][yy[i]] = max(dp[cur][xx[i]][yy[i]], dp[cur^1][xx[i]][yy[i]]);
            nx = xx[i]+dx[d[t]];
            ny = yy[i]+dy[d[t]];
            if (!a[nx][ny]) continue;
            dp[cur][nx][ny] = max(dp[cur][nx][ny], dp[cur^1][xx[i]][yy[i]]+1);
            add(nx, ny);
        }
    }
    for (int i = 1; i <= tot; ++i)
        res = max(res, dp[cur][xx[i]][yy[i]]);
    cout << res << endl;
    return 0;
}
