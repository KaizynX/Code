/*
 * @Author: Kaizyn
 * @Date: 2020-03-15 14:17:42
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-15 21:14:04
 * @FilePath: \Code\pintia\2020031507.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int dir[] = {0, -1, 0, 1, 0};

int n, m, k;
int kx[N], ky[N];
int a[N][N], vis[N][N];
vector<int> dx, dy, ddx, ddy;

void bfs(const int &x, const int &y)
{
    queue<pii> q;
    q.push({x, y});
    vis[x][y] = 1;
    while (q.size()) {
        int ux = q.front().first, uy = q.front().second;
        q.pop();
        for (int i = 0, vx, vy; i < 4; ++i) {
            vx = ux+dir[i];
            vy = uy+dir[i+1];
            if (vx < 1 || vy < 1 || vx > n || vy > m ||
                a[vx][vy] || vis[vx][vy]) continue;
            vis[vx][vy] = 1;
            q.push({vx, vy});
        }
    }
}

inline void solve()
{
    cin >> n >> m >> k;
    if (n <= 1000 && m <= 1000) {
        for (int i = 1, x, y; i <= k; ++i) {
            cin >> x >> y;
            a[x][y] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                a[i][j] ^= 1;
            }
        }
    } else {
        dx.resize(k+1);
        dy.resize(k+1);
        dx[0] = n;
        dy[0] = m;
        for (int i = 1; i <= k; ++i) {
            cin >> kx[i] >> ky[i];
            dx[i] = kx[i];
            dy[i] = ky[i];
        }
        sort(dx.begin(), dx. end());
        sort(dy.begin(), dy. end());
        dx.erase(unique(dx.begin(), dx.end()), dx.end());
        dy.erase(unique(dy.begin(), dy.end()), dy.end());
        ddx.resize(dx.size());
        ddy.resize(dy.size());
        ddx[0] = ddy[0] = 1;
        for (int i = 1; i < (int)dx.size(); ++i)
            ddx[i] = ddx[i-1]+(dx[i] == dx[i-1]+1 ? 1 : 2);
        for (int i = 1; i < (int)dy.size(); ++i)
            ddy[i] = ddy[i-1]+(dy[i] == dy[i-1]+1 ? 1 : 2);
        for (int i = 1; i <= k; ++i) {
            kx[i] = ddx[lower_bound(dx.begin(), dx.end(), kx[i])-dx.begin()];
            ky[i] = ddy[lower_bound(dy.begin(), dy.end(), ky[i])-dy.begin()];
            a[kx[i]][ky[i]] = 1;
        }
        n = ddx.back();
        m = ddy.back();
    }
    long long res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] || vis[i][j]) continue;
            ++res;
            bfs(i, j);
        }
    }
    cout << res << endl;
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