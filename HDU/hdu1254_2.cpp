#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 8;
const int d[] = {0, -1, 0, 1, 0};

int T, n, m;
int a[N][N], vis[N][N][N][N];

struct Node
{
    int bx, by, px, py, t;
};

inline bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 1;
}

inline walk(int bx, int by, int sx, int sy, int tx, int ty)
{
    static int v[N][N];
    typedef pair<int, int> pii;
    memset(v, 0, sizeof v);
    queue<pii> q;
    q.push({sx, sy});
    v[sx][sy] = 1;
    v[bx][by] = 1;
    while (q.size()) {
        pii u = q.front();
        q.pop();
        if (u.first == tx && u.second == ty) return true;
        for (int i = 0, nx, ny; i < 4; ++i) {
            nx = u.first+d[i]; ny = u.second+d[i+1];
            if (!check(nx, ny) || v[nx][ny]) continue;
            v[nx][ny] = 1;
            q.push({nx, ny});
        }
    }
    return false;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        int bx, by, px, py, ex, ey;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                scanf("%d", &a[i][j]);
                if (a[i][j] == 2) bx = i, by = j;
                if (a[i][j] == 3) ex = i, ey = j;
                if (a[i][j] == 4) px = i, py = j;
            }
        }
        memset(vis, 0, sizeof vis);
        queue<Node> q;
        int res = -1;
        q.push({bx, by, px, py, 0});
        vis[bx][by][px][py] = 1;
        while (q.size()) {
            Node u = q.front();
            q.pop();
            if (u.bx == ex && u.by == ey) {
                res = u.t;
                break;
            }
            for (int i = 0, nx, ny, lx, ly; i < 4; ++i) {
                nx = u.bx+d[i]; ny = u.by+d[i+1];
                lx = u.bx+d[(i+2)%4]; ly = u.by+d[(i+2)%4+1];
                if (!check(nx, ny) || !check(lx, ly)) continue;
                if (!walk(u.bx, u.by, u.px, u.py, lx, ly)) continue;
                if (vis[nx][ny][u.bx][u.by]) continue;
                vis[nx][ny][u.bx][u.by] = 1;
                q.push({nx, ny, u.bx, u.by, u.t+1});
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
