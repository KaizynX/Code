/*
 * @Author: Kaizyn
 * @Date: 2020-03-10 15:02:32
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-10 16:29:06
 * @FilePath: \Code\HDU\hdu2262_2.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 4e2+7;
const int M = 20;
const int MOD = 1e9+7;
const double eps = 1e-11;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int dir[] = {0, -1, 0, 1, 0};

struct GaussElimination
{
    double a[N][N];
    bool solve(const int &n) {
        for (int i = 1, j, k; i <= n; ++i) {
            for (j = i+1, k = i; j <= n; ++j)
                if (abs(a[j][i]) > abs(a[k][i])) k = j;
            if (abs(a[k][i]) < eps) return false;
            swap(a[k], a[i]);
            for (j = 1; j <= n; ++j) if (i != j) {
                double d = a[j][i]/a[i][i];
                for (k = i+1; k <= n+1; ++k)
                    a[j][k] -= d*a[i][k];
            }
        }
        for (int i = 1; i <= n; ++i) a[i][n+1] /= a[i][i];
        return true;
    }
} GE;

int n, m;
char a[M][M];
int mp[M][M];

inline void solve()
{
    int tot = 0, flag = 0;;
    queue<pii> q;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == '@') {
                q.push({i, j});
                mp[i][j] = ++tot;
            } else {
                mp[i][j] = -1;
            }
        }
    }
    while (q.size()) {
        pii u = q.front();
        q.pop();
        for (int i = 0, nx, ny; i < 4; ++i) {
            nx = u.first+dir[i];
            ny = u.second+dir[i+1];
            if (nx < 1 || ny < 1 || nx > n || ny > m ||
                a[nx][ny] == '#' || mp[nx][ny] != -1) continue; 
            if (a[nx][ny] == '$') {
                flag = 1;
                mp[nx][ny] = 0;
            } else {
                mp[nx][ny] = ++tot;
                q.push({nx, ny});
            }
        }
    }
    if (!flag) { cout << -1 << endl; return; }

    for (int i = 1; i <= tot; ++i)
        for (int j = 1; j <= tot+1; ++j)
            GE.a[i][j] = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (mp[i][j] <= 0) continue;
            int cnt = 0;
            for (int k = 0, nx, ny; k < 4; ++k) {
                nx = i+dir[k];
                ny = j+dir[k+1];
                if (nx < 1 || ny < 1 || nx > n || ny > m ||
                    a[nx][ny] == '#' || mp[nx][ny] == -1) continue; 
                ++cnt;
            }
            GE.a[mp[i][j]][mp[i][j]] = cnt;
            GE.a[mp[i][j]][tot+1] = cnt;
            for (int k = 0, nx, ny; k < 4; ++k) {
                nx = i+dir[k];
                ny = j+dir[k+1];
                if (nx < 1 || ny < 1 || nx > n || ny > m ||
                    a[nx][ny] == '#' || mp[nx][ny] == -1) continue; 
                GE.a[mp[i][j]][mp[nx][ny]] = -1;
            }
        }
    }
    if (!GE.solve(tot)) { cout << -1 << endl; return; }
    printf("%.6f\n", GE.a[1][tot+1]);
}

signed main()
{
    while (scanf("%d %d", &n, &m) == 2) {
        for (int i = 1; i <= n; ++i) scanf("%s", a[i]+1);
        solve();
    }
    return 0;
}