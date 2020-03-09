/*
 * @Author: Kaizyn
 * @Date: 2020-03-05 17:48:47
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-05 19:03:09
 * @FilePath: \Code\Luogu\luogu1850.cpp
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, v, e;
int c[N], d[N], dis[N][N], choose[N];
double res;
double k[N], dpc[N], dpd[N];

inline void floyd()
{
    for (int l = 1; l <= v; ++l)
        for (int i = 1; i <= v; ++i)
            for (int j = 1; j <= v; ++j)
                dis[i][j] = min(dis[i][j], dis[i][l]+dis[l][j]);
}

double calc()
{
    for (int i = 1; i <= n; ++i) {
        double p = (choose[i] ? k[i] : 0);
        dpc[i+1] = (1-p)*(dpc[i]+dis[c[i]][c[i+1]])+p*(dpd[i]+dis[d[i]][c[i+1]]);
        dpd[i+1] = (1-p)*(dpc[i]+dis[c[i]][d[i+1]])+p*(dpd[i]+dis[d[i]][d[i+1]]);
    }
    return dpc[n+1];
}

void dfs(const int &u, const int &num)
{
    if (u > n) {
        res = min(res, calc());
        return;
    }
    choose[u] = 0;
    dfs(u+1, num);
    if (num >= m) return;
    choose[u] = 1;
    dfs(u+1, num+1);
}

inline void solve()
{
    cin >> n >> m >> v >> e;
    for (int i = 1; i <= n; ++i) cin >> c[i];
    for (int i = 1; i <= n; ++i) cin >> d[i];
    for (int i = 1; i <= n; ++i) cin >> k[i];
    memset(dis, 0x3f, sizeof dis);
    for (int i = 1, a, b, w; i <= e; ++i) {
        cin >> a >> b >> w;
        dis[a][b] = dis[b][a] = min(dis[b][a], w);
    }
    for (int i = 1; i <= v; ++i)
        dis[i][i] = dis[i][0] = dis[0][i] = dis[i][v+1] = dis[v+1][i] = 0;
    floyd();
    res = INF;
    dfs(1, 0);
    printf("%.2f\n", res);
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