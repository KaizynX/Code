#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int K = 45;
const int d[] = {0,1,0,-1,0};
typedef pair<int, int> pii;

int n, m, k, q;
int a[N][N], dis[K][N][N], vis[K];
vector<pii> col[K];

inline void bfs(int c)
{
    memset(dis[c], -1, sizeof dis[c]);
    memset(vis, 0, sizeof vis);
    queue<pii> q;
    for (pii &p : col[c])
        q.push(p), dis[c][p.first][p.second] = 0;
    vis[c] = 1;
    while (q.size()) {
        pii u = q.front();
        q.pop();
        for (int i = 0, nx, ny; i < 4; ++i) {
            nx = u.first+d[i];
            ny = u.second+d[i+1];
            if (nx < 1 || ny < 1 || nx > n || ny > m || dis[c][nx][ny] != -1) continue;
            dis[c][nx][ny] = dis[c][u.first][u.second]+1;
            q.push({nx, ny});
        }
        int nc = a[u.first][u.second];
        if (vis[nc]) continue;
        vis[nc] = 1;
        for (pii &v : col[nc]) {
            if (dis[c][v.first][v.second] != -1) continue;
            dis[c][v.first][v.second] = dis[c][u.first][u.second]+1;
            q.push(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j],
            col[a[i][j]].emplace_back(i, j);
    for (int i = 1; i <= k; ++i)
        bfs(i);
    cin >> q;
    for (int i = 1, r1, r2, c1, c2, res; i <= q; ++i) {
        cin >> r1 >> c1 >> r2 >> c2;
        res = abs(r1-r2)+abs(c1-c2);
        for (int j = 1; j <= k; ++j)
            res = min(res, dis[j][r1][c1]+dis[j][r2][c2]+1);
        cout << res << endl;
    }
    return 0;
}
