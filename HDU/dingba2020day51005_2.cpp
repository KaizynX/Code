#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int d[] = {0, -1, 0, 1, 0};

int n, k, m;
int a[N][N], vis[N][N];

struct Node
{
    int x, y, v;
};

int main()
{
    while (scanf("%d %d", &n, &k) == 2 && !(n == -1 && k == -1)) {
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                scanf("%d", &a[i][j]);
                vis[i][j] = 0;
            }
        }
        queue<Node> q;
        q.push({1, 1, a[1][1]});
        vis[1][1] = a[1][1];
        while (q.size()) {
            Node u = q.front();
            q.pop();
            if (u.v < vis[u.x][u.y]) continue;
            res = max(res, u.v);
            for (int i = 0, nx, ny; i < 4; ++i) {
                nx = u.x; ny = u.y;
                for (int j = 1; j <= k; ++j) {
                    nx += d[i]; ny += d[i+1];
                    if (nx < 1 || ny < 1 || nx > n || ny > n) break;
                    if (a[nx][ny] <= a[u.x][u.y]) continue;
                    int tmp = u.v+a[nx][ny];
                    if (tmp <= vis[nx][ny]) continue;
                    q.push({nx, ny, tmp});
                    vis[nx][ny] = tmp;
                }
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
