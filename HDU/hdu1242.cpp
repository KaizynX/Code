#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int d[] = {0, -1, 0, 1, 0};

int n, m;
char a[N][N];
int vis[N][N];

struct Node
{
    int x, y, t;
    Node(){}
    Node(int _x, int _y, int _t) : x(_x), y(_y), t(_t) {}
};

inline bool check(int x, int y)
{
    return !(x < 1 || y < 1 || x > n || y > m ||
             a[x][y] == '#' || vis[x][y]);
}

int main()
{
    while (scanf("%d %d", &n, &m) == 2) {
        queue<Node> q;
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            scanf("%s", a[i]+1);
            for (int j = 1; j <= m; ++j) {
                if (a[i][j] == 'a') {
                    q.push(Node(i, j, 0));
                    vis[i][j] = 1;
                } else {
                    vis[i][j] = 0;
                }
            }
        }
        while (q.size()) {
            Node u = q.front();
            q.pop();
            if (a[u.x][u.y] == 'r') {
                printf("%d\n", u.t);
                flag = 1;
                break;
            }
            if (a[u.x][u.y] == 'x') {
                a[u.x][u.y] = '.';
                ++u.t;
                q.push(u);
                continue;
            }
            for (int i = 0, nx, ny; i < 4; ++i) {
                nx = u.x+d[i]; ny = u.y+d[i+1];
                if (!check(nx, ny)) continue;
                vis[nx][ny] = 1;
                q.push(Node(nx, ny, u.t+1));
            }
        }
        if (!flag) puts("Poor ANGEL has to stay in the prison all his life.");
    }
    return 0;
}
