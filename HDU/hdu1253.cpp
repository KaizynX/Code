#include <bits/stdc++.h>

using namespace std;

const int N = 55;
const int d[3][6] = {{-1,1,0,0,0,0},
                     {0,0,-1,1,0,0},
                     {0,0,0,0,-1,1}};

int T, n, m, k, t;
int a[N][N][N], vis[N][N][N];

struct Node
{
    int x, y, z, t;
    Node(){}
    Node(int _x, int _y, int _z, int _t) : x(_x), y(_y), z(_z), t(_t) {}
};

inline bool check(const Node &v)
{
    return !(v.x < 1 || v.y < 1 || v.z < 1 || v.x > n || v.y > m || v.z > k ||
             a[v.x][v.y][v.z] || vis[v.x][v.y][v.z]);
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &k, &n, &m, &t);
        for (int l = 1; l <= k; ++l)
        for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j][l]);
            vis[i][j][l] = 0;
        }
        queue<Node> q;
        q.push(Node(1, 1, 1, 0));
        vis[1][1][1] = 1;
        int res = -1;
        Node u, v;
        while (q.size()) {
            u = q.front();
            q.pop();
            if (u.t > t) continue;
            if (u.x == n && u.y == m && u.z == k) {
                res = u.t;
                break;
            }
            for (int i = 0; i < 6; ++i) {
                v.x = u.x+d[0][i];
                v.y = u.y+d[1][i];
                v.z = u.z+d[2][i];
                v.t = u.t+1;
                if (!check(v)) continue;
                vis[v.x][v.y][v.z] = 1;
                q.push(v);
            }
        }
        printf("%d\n", res);
    }
    return 0;
}
