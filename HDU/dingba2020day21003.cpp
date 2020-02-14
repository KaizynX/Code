#include <bits/stdc++.h>

using namespace std;

const int N = 1e1+7;
const int d[] = {0, -1, 0, 1, 0};

int testcase, n, m, t;
char a[2][N][N];
int vis[2][N][N];

struct Node
{
    int k, x, y, t;
    Node(){}
    Node(int _k, int _x, int _y, int _t) : k(_k), x(_x), y(_y), t(_t) {}
};

inline bool check(int k, int x, int y)
{
    return !(x < 1 || y < 1 || x > n || y > m ||
             a[k][x][y] == '*' || vis[k][x][y]);
}

int main()
{
    cin >> testcase;
    while (testcase--) {
        queue<Node> q;
        scanf("%d %d %d", &n, &m, &t);
        for (int k = 0; k < 2; ++k)
            for (int i = 1; i <= n; ++i)
                scanf("%s", a[k][i]+1);
        for (int k = 0; k < 2; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= m; ++j) {
                    vis[k][i][j] = 0;
                    if (a[k][i][j] == 'S') {
                        q.push(Node(k, i, j, 0));
                        vis[k][i][j] = 1;
                    }
                    if (a[k][i][j] == '#' && a[k^1][i][j] == '#') {
                        a[0][i][j] = a[1][i][j] = '*';
                    }
                }
            }
        }
        int flag = 0;
        while (q.size()) {
            Node u = q.front();
            q.pop();
            if (u.t > t) continue;
            if (a[u.k][u.x][u.y] == 'P') {
                flag = 1;
                break;
            }
            for (int i = 0, nx, ny, nk; i < 4; ++i) {
                nk = u.k; nx = u.x+d[i]; ny = u.y+d[i+1];
                if (!check(nk, nx, ny)) continue;
                if (a[u.k][nx][ny] == '#') {
                    nk ^= 1;
                    if (!check(nk, nx, ny)) continue;
                }
                q.push(Node(nk, nx, ny, u.t+1));
                vis[nk][nx][ny] = 1;
            }
        }
        puts((flag ? "YES" : "NO"));
    }
    return 0;
}
