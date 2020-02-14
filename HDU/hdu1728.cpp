#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int d[] = {0, -1, 0, 1, 0};

int T, n, m, k, bx, by, ex, ey;
int vis[N][N];
char a[N][N];

struct Node
{
    int x, y, t;
};

inline bool check(int x, int y)
{
    return !(x < 1 || y < 1 || x > n || y > m || a[x][y] == '*');
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; ++i)
            scanf("%s", a[i]+1);
        scanf("%d %d %d %d %d", &k, &by, &bx, &ey, &ex);
        memset(vis, 0, sizeof vis);
        queue<Node> q;
        q.push({bx, by, -1});
        vis[bx][by] = 1;
        int flag = 0;
        while (q.size()) {
            Node u = q.front();
            q.pop();
            // cout << u.x << ' ' << u.y << " " << u.t << endl;
            if (u.t > k) break;
            if (u.x == ex && u.y == ey) {
                flag = 1;
                break;
            }
            for (int i = 0; i < 4; ++i) {
                for (int nx = u.x+d[i], ny = u.y+d[i+1]; check(nx, ny); nx += d[i], ny += d[i+1]) {
                    if (!vis[nx][ny]) {
                        vis[nx][ny] = 1;
                        q.push({nx, ny, u.t+1});
                    }
                }
            }
        }
        puts((flag ? "yes" : "no"));
    }
    return 0;
}
