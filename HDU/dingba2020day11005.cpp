#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int d[] = {0, -1, 0, 1, 0};

int T, n, m;
int vis[N][N];
char a[N][N];

struct Node
{
    int x, y, t;
    Node(){}
    Node(int _x, int _y, int _t) : x(_x), y(_y), t(_t){}
};

int main()
{
    cin >> T;
    while (T--) {
        cin >> n >> m;
        int ex, ey;
        queue<Node> q;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j];
                vis[i][j] = 0;
                if (a[i][j] == 'F') {
                    q.push(Node(i, j, 0));
                    vis[i][j] = 1;
                }
                if (a[i][j] == 'R') ex = i, ey = j;
            }
        }
        while (q.size()) {
            Node cur = q.front();
            q.pop();
            if (cur.x == ex && cur.y == ey) {
                cout << cur.t << endl;
                break;
            }
            for (int i = 0, nx, ny; i < 4; ++i) {
                nx = cur.x+d[i]; ny = cur.y+d[i+1];
                if (nx < 1 || ny < 1 || nx > n || ny > m ||
                    a[nx][ny] == '#' || vis[nx][ny]) continue;
                vis[nx][ny] = 1;
                q.push(Node(nx, ny, cur.t+1));
            }
        }
        if (!vis[ex][ey]) cout << "Poor Rabbit." << endl;
    }
    return 0;
}
