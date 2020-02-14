#include <bits/stdc++.h>

using namespace std;

const int N = 21;
const int K = 10;
const int d[] = {0, -1, 0, 1, 0};

int n, m, t;
char a[N][N];
int vis[N][N][1<<K];

struct Node
{
    int x, y, k, t;
};

int main()
{
    while (scanf("%d %d %d", &n, &m, &t) == 3) {
        queue<Node> q;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", a[i]+1);
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] == '@')
                    q.push({i, j, 0, 0}), vis[i][j][0] = 1;
            }
        }
        int res = -1;
        while (q.size()) {
            Node u = q.front();
            q.pop();
            if (u.t >= t) break;
            if (a[u.x][u.y] == '^') { res = u.t; break; }
            for (int i = 0, nx, ny, nk; i < 4; ++i) {
                nx = u.x+d[i]; ny = u.y+d[i+1], nk = u.k;
                if (nx < 1 || nx > n || ny < 1 || ny > m ||
                    a[nx][ny] == '*') continue;
                if (a[nx][ny] >= 'a' && a[nx][ny] <= 'j')
                    nk |= 1<<(a[nx][ny]-'a');
                if (a[nx][ny] >= 'A' && a[nx][ny] <= 'J' &&
                    !((nk>>(a[nx][ny]-'A'))&1)) continue;
                if (vis[nx][ny][nk]) continue;
                vis[nx][ny][nk] = 1;
                q.push({nx, ny, nk, u.t+1});
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
