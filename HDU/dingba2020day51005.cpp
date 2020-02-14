#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int d[] = {0, -1, 0, 1, 0};

int n, k, m;
int a[N][N], dp[N][N], vis[N][N];

struct Node
{
    int x, y, v;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.v < n2.v;
    }
} b[N*N];

int main()
{
    while (scanf("%d %d", &n, &k) == 2 && !(n == -1 && k == -1)) {
        m = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &a[i][j]);
                vis[i][j] = a[i][j] <= a[1][1];
                b[++m] = {i, j, a[i][j]};
                dp[i][j] = 0;
            }
        }
        sort(b+2, b+m+1);
        dp[1][1] = a[1][1];
        vis[1][1] = 0;
        int res = a[1][1];
        for (int i = 2, nx, ny; i <= m; ++i) {
            if (vis[b[i].x][b[i].y]) continue;
            for (int j = 0; j < 4; ++j) {
                nx = b[i].x; ny = b[i].y;
                for (int l = 1; l <= k; ++l) {
                    nx += d[j]; ny += d[j+1];
                    if (nx < 1 || ny < 1 || nx > n || ny > n) break;
                    if (vis[nx][ny] || a[nx][ny] >= a[b[i].x][b[i].y]) continue;
                    dp[b[i].x][b[i].y] = max(dp[b[i].x][b[i].y], dp[nx][ny]+a[b[i].x][b[i].y]);
                }
            }
            if (!dp[b[i].x][b[i].y]) vis[b[i].x][b[i].y] = 1;
            res = max(res, dp[b[i].x][b[i].y]);
        }
        printf("%d\n", res);
    }
    return 0;
}
