#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int d[] = {0, -1, 0, 1, 0};

int n, m, t;
int vis[N][N];
char a[N][N];

bool dfs(int x, int y, int step)
{
    if (step < t && a[x][y] == 'D') return false;
    if (step == t) return a[x][y] == 'D';
    vis[x][y] = 1;
    for (int i = 0, nx, ny; i < 4; ++i) {
        nx = x+d[i]; ny = y+d[i+1];
        if (nx < 1 || ny < 1 || nx > n || ny > m ||
            a[nx][ny] == 'X' || vis[nx][ny]) continue;
        if (dfs(nx, ny, step+1))
            return true;
    }
    vis[x][y] = 0;
    return false;
}

int main()
{
    while (scanf("%d %d %d", &n, &m, &t) == 3 && n|m|t) {
        int bx, by;
        memset(vis, 0, sizeof vis);
        for (int i = 1; i <= n; ++i) {
            scanf("%s", a[i]+1);
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] == 'S') bx = i, by = j;
            }
        }
        puts((dfs(bx, by, 0) ? "YES" : "NO"));
    }
    return 0;
}
