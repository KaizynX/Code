#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 8;
const int d[] = {0, -1, 0, 1, 0};

int T, n, m;
int a[N][N], vis[N][N][N*N], col[N][N][N][N];
// col[bx][by][px][py] the connect color when box at (bx, by) person at (px, py)

struct Node
{
    int x, y, c, t;
};

inline void color_it(int color[N][N])
{
    int number = 0;
    typedef pair<int, int> pii;
    for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
    if (a[i][j] != 1 && !color[i][j]) {
        color[i][j] = ++number;
        queue<pii> q;
        q.push({i, j});
        while (q.size()) {
            pii u = q.front();
            q.pop();
            for (int k = 0, x, y; k < 4; ++k) {
                x = u.first+d[k];
                y = u.second+d[k+1];
                if (x < 1 || y < 1 || x > n || y > m ||
                    a[x][y] == 1 || color[x][y]) continue;
                color[x][y] = number;
                q.push({x, y});
            }
        }
    }
}

inline void init()
{
    memset(vis, 0, sizeof vis);
    memset(col, 0, sizeof col);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (a[i][j] != 1) {
                col[i][j][i][j] = -1;
                color_it(col[i][j]);
            }
}

inline bool check(int x, int y)
{
    return x >= 1 && x <= n && y >= 1 && y <= m && a[x][y] != 1;
}

#ifdef DEBUG
inline void print(int x, int y)
{
    puts("**********");
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j)
            printf("%3d", col[x][y][i][j]);
        putchar('\n');
    }
    puts("**********");
}
#endif

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
        init();
        queue<Node> q;
        int tmp = col[bx][by][px][py], res = -1;
        q.push({bx, by, tmp, 0});
        vis[bx][by][tmp] = 1;
        while (q.size()) {
            Node u = q.front();
            q.pop();
#ifdef DEBUG
            printf("(%d %d) %d\n", u.x, u.y, u.c);
            print(u.x, u.y);
#endif
            if (u.x == ex && u.y == ey) {
                res = u.t;
                break;
            }
            for (int i = 0, nx, ny, lx, ly; i < 4; ++i) {
                nx = u.x+d[i]; ny = u.y+d[i+1];
                lx = u.x+d[(i+2)%4]; ly = u.y+d[(i+2)%4+1];
                if (!check(nx, ny) || !check(lx, ly)) continue;
                if (col[u.x][u.y][lx][ly] != u.c) continue;
                tmp = col[nx][ny][u.x][u.y];
                if (vis[nx][ny][tmp]) continue;
                vis[nx][ny][tmp] = 1;
                q.push({nx, ny, tmp, u.t+1});
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
