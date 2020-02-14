#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 25;
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
    return x < 1 || x > n || y < 1 || y > m || a[x][y] == '*' || vis[x][y];
}

int main()
{
    while (scanf("%d %d", &n, &m) == 2) {
        int sx, sy, tx, ty;
        for (int i = 1; i <= n; ++i) {
            scanf("%s", a[i]+1);
            for (int j = 1; j <= m; ++j) {
                vis[i][j] = 0;
                if (a[i][j] == 'S') sx = i, sy = j;
                if (a[i][j] == 'T') tx = i, ty = j;
                if (a[i][j] == '|') a[i][j] = 1;
                if (a[i][j] == '-') a[i][j] = 0;
            }
        }
        queue<Node> q;
        q.push(Node(sx, sy, 0));
        vis[sx][sy] = 1;
        while (q.size()) {
            Node u = q.front();
            q.pop();
#ifdef DEBUG
            printf("(%d, %d) %d\n", u.x, u.y, u.t);
#endif
            if (u.x == tx && u.y == ty) {
                printf("%d\n", u.t);
                break;
            }
            for (int i = 0, nx, ny; i < 4; ++i) {
                nx = u.x+d[i]; ny = u.y+d[i+1];
                if (check(nx, ny)) continue;
                if (a[nx][ny] < 2) {
                    if (i%2 != (a[nx][ny]^(u.t&1))) {
                        nx = u.x; ny = u.y;
                    } else {
                        nx += d[i]; ny += d[i+1];
                        if (check(nx, ny)) continue;
                    }
                }
                vis[nx][ny] = 1;
                q.push(Node(nx, ny, u.t+1));
            }
        }
    }
    return 0;
}

