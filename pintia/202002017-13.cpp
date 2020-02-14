#include <bits/stdc++.h>

using namespace std;

const int dx[] = {-1,1,0,0,0,0};
const int dy[] = {0,0,-1,1,0,0};
const int dz[] = {0,0,0,0,-1,1};

int n, m, l, t;
int a[61][1287][129];
bool vis[61][1287][129];

struct Node
{
    int z, x, y;
};

inline int bfs(int z, int x, int y)
{
    int res = 0;
    queue<Node> q;
    q.push({z, x, y});
    vis[z][x][y] = 1;
    while (q.size()) {
        Node u = q.front(), v;
        q.pop();
        ++res;
        for (int d = 0; d < 6; ++d) {
            v.z = u.z+dz[d];
            v.x = u.x+dx[d];
            v.y = u.y+dy[d];
            if (v.z < 1 || v.z > l || v.x < 1 || v.x > n || v.y < 1 || v.y > m ||
                !a[v.z][v.x][v.y] || vis[v.z][v.x][v.y]) continue;
            vis[v.z][v.x][v.y] = 1;
            q.push(v);
        }
    }
    return res >= t ? res : 0;
}

int main()
{
    scanf("%d %d %d %d", &n, &m, &l, &t);
    for (int k = 1; k <= l; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &a[k][i][j]);
    int res = 0;
    for (int k = 1; k <= l; ++k)
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j) {
                if (vis[k][i][j] || !a[k][i][j]) continue;
                res += bfs(k, i, j);
            }
    printf("%d\n", res);
    return 0;
}
