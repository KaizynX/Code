#include <bits/stdc++.h>

using namespace std;

const int N = 21;
const int K = 10;
const int d[] = {0, -1, 0, 1, 0};

int n, m, t, head, tail;
char a[N][N];
bool vis[N][N][1<<K];

struct Node
{
    int x, y, k, t;
} q[500000];

int main()
{
    while (scanf("%d %d %d", &n, &m, &t)) {
        head = tail = 0;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", a[i]+1);
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] == '@')
                    q[++tail] = {i, j, 0, 0}, vis[i][j][0] = 1;
            }
        }
        int res = -1;
        while (head < tail) {
            Node u = q[++head];
            if (u.t >= t) break;
            if (a[u.x][u.y] == '^') {
                res = u.t;
                break;
            }
            for (int i = 0, nx, ny, nk; i < 4; ++i) {
                nx = u.x+d[i]; ny = u.y+d[i+1], nk = u.k;
                if (nx < 1 || nx > n || ny < 1 || ny > m ||
                    a[nx][ny] == '*') continue;
                if (a[nx][ny] >= 'a' && a[nx][ny] <= 'j')
                    nk |= 1<<(a[nx][ny]-'a');
                if (a[nx][ny] >= 'A' && a[nx][ny] <= 'J' &&
                    !(nk>>(a[nx][ny]-'A'))) continue;
                if (vis[nx][ny][nk]) continue;
                vis[nx][ny][nk] = 1;
                q[++tail] = {nx, ny, nk, u.t+1};
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
