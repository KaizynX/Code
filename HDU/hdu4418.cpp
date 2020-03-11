/*
 * @Author: Kaizyn
 * @Date: 2020-03-11 19:12:08
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-11 21:26:31
 * @FilePath: \Code\HDU\hdu4418.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e2+7;
const double eps = 1e-8;

struct GaussElimination
{
    double a[N][N];
    // ans is a[i][n+1]
    void init() { memset(a, 0, sizeof a); }
    void init(const int &n) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n+1; ++j)
                a[i][j] = 0;
    }
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
};

int n, m, y, x, d, nn, tot;
int p[N], a[N], vis[N];
GaussElimination GE;

bool bfs()
{
    memset(vis, 0, sizeof vis);
    int flag = 0;
    queue<int> q;
    q.push(x);
    tot = 0;
    vis[x] = ++tot;
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (a[u] == y) flag = 1;
        for (int i = 1, v; i <= m; ++i) if (p[i]) {
            v = (u+i)%nn;
            if (vis[v]) continue;
            vis[v] = ++tot;
            q.push(v);
        }
    }
    return flag;
}

inline void solve()
{
    if (x == y) { puts("0.00"); return; }
    nn = n*2-2;
    for (int i = 0; i < n; ++i) a[i] = i;
    for (int i = n; i < nn; ++i) a[i] = 2*n-i-2;
    x = (d == 1 ? nn-x : x);
    if (!bfs()) { puts("Impossible !"); return; }
    GE.init(tot);
    for (int i = 0; i < nn; ++i) if(vis[i]) {
        // E[i] = sigma p[j]*(E[i+j]+j)
        GE.a[vis[i]][vis[i]] = 100;
        if (a[i] == y) continue;
        for (int j = 1, v; j <= m; ++j) if (p[j]) {
            v = (i+j)%nn;
            if (!vis[v]) continue;
            GE.a[vis[i]][vis[v]] -= p[j];
            GE.a[vis[i]][tot+1] += j*p[j];
        }
    }
    #ifdef DEBUG
    for (int i = 1; i <= tot; ++i)
        for (int j = 1; j <= tot+1; ++j)
            cout << GE.a[i][j] << " \n"[j==tot+1];
    #endif
    if (!GE.solve(tot) || abs(GE.a[vis[x]][tot+1]) < eps) { puts("Impossible !"); return; }
    printf("%.2f\n", GE.a[vis[x]][tot+1]);
}

signed main()
{
    int testcase = 1;
    scanf("%d", &testcase);
    for (int i = 1; i <= testcase; ++i) {
        scanf("%d %d %d %d %d", &n, &m, &y, &x, &d);
        for (int i = 1; i <= m; ++i) scanf("%d", p+i);
        solve();
    }
    return 0;
}