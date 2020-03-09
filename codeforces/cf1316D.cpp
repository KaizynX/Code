/*
 * @Author: Kaizyn
 * @Date: 2020-03-04 23:10:15
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-05 00:24:08
 * @FilePath: \Code\codeforces\cf1316D.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int dir[] = {0, -1, 0, 1, 0};
const char mp[] = "LURDX";
// 0 1 2 3 4
// L U R D X

int n, tp;
int res[N][N];
pii a[N][N], stk[N*N];
queue<pii> q;
map<pii, int> dfn;

template <typename T>
void clear(T &x) { T tmp; swap(tmp, x); }

void bfs1(const int &x, const int &y)
{
    clear(q);
    res[x][y] = 4;
    q.push({x, y});
    while (q.size()) {
        pii u = q.front();
        q.pop();
        for (int i = 0, nx, ny; i < 4; ++i) {
            nx = u.first+dir[i];
            ny = u.second+dir[i+1];
            if (nx < 1 || ny < 1 || nx > n || ny > n ||
                res[nx][ny] != -1 ||  a[nx][ny] != make_pair(x, y)) continue;
            res[nx][ny] = (i+2)%4;
            q.push({nx, ny});
        }
    }
}

inline int getdir(const pii &u, const pii &v)
{
    for (int i = 0; i < 4; ++i) {
        if (make_pair(u.first+dir[i], u.second+dir[i+1]) == v) {
            return i;
        }
    }
    return -1;
}

inline void add_que(const int &x, const int &y)
{
    for (pii u = stk[tp], last = {x, y}; ; u = stk[--tp]) {
        res[u.first][u.second] = getdir(u, last);
        q.push(u);
        if (u == make_pair(x, y)) break;
        last = u;
    }
}

bool dfs(const int &x, const int &y, const int &_dfn)
{
    if (dfn.count({x, y})) {
        // if (_dfn-dfn[{x,y}] <= 2) return false;
        add_que(x, y);
        return true;
    }
    dfn[{x, y}] = _dfn;
    stk[++tp] = {x, y};
    for (int i = 0, nx, ny; i < 4; ++i) {
        nx = x+dir[i];
        ny = y+dir[i+1];
        if (nx < 1 || ny < 1 || nx > n || ny > n ||
            a[nx][ny] != make_pair(-1, -1)) continue;
        if (dfs(nx, ny, _dfn+1)) return true;
    }
    --tp;
    return false;
}

void bfs2(const int &x, const int &y)
{
    clear(q);
    dfn.clear();
    tp = 0;
    if (!dfs(x, y, 1)) return;
    while (q.size()) {
        pii u = q.front();
        q.pop();
        for (int i = 0, nx, ny; i < 4; ++i) {
            nx = u.first+dir[i];
            ny = u.second+dir[i+1];
            if (nx < 1 || ny < 1 || nx > n || ny > n ||
                res[nx][ny] != -1 ||  a[nx][ny] != make_pair(-1, -1)) continue;
            res[nx][ny] = (i+2)%4;
            q.push({nx, ny});
        }
    }
}

inline void solve()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cin >> a[i][j].first >> a[i][j].second;
        }
    }

    int flag = 1;
    memset(res, -1, sizeof res);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (res[i][j] != -1) continue;
            if (a[i][j] == make_pair(i, j)) bfs1(i, j);
            if (a[i][j] == make_pair(-1, -1)) bfs2(i, j);
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (res[i][j] == -1) flag = 0;
        }
    }
    if (!flag) {cout << "INVALID" << endl; return; }
    cout << "VALID" << endl;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            cout << mp[res[i][j]];
        }
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int testcase = 1;
    // cin >> testcase;
    for (int i = 1; i <= testcase; ++i) {
        solve();
    }
    return 0;
}