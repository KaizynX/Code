/*
 * @Author: Kaizyn
 * @Date: 2020-03-21 19:57:52
 * @LastEditTime: 2020-03-21 20:34:08
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e2+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int dir[] = {0, 1, 0};

struct Node
{
    int x, y, step;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.step > n2.step;
    }
};

int n, m;
int a[N][N], vis[N][N];
priority_queue<Node> q;

inline void bfs()
{
    memset(vis, 0x3f, sizeof vis);
    q.push({1, 1, 0});
    vis[1][1] = 0;
    while (q.size()) {
        Node u = q.top();
        q.pop();
        if (u.step > vis[u.x][u.y]) continue;
        for (int i = 0, nx, ny; i < 2; ++i) {
            nx = u.x+dir[i];
            ny = u.y+dir[i+1];
            if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
            Node v = {nx, ny, u.step+(a[nx][ny] != a[u.x][u.y])};
            if (vis[nx][ny] <= v.step) continue;
            vis[nx][ny] = v.step;
            q.push(v);
        }
    }
}

inline void solve()
{
    string str;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> str;
        for (int j = 1; j <= m; ++j) {
            a[i][j] = str[j-1] == '#';
        }
    }
    bfs();
    cout << vis[n][m]/2+(a[1][1]|a[n][m]) << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}