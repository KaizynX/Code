/*
 * @Author: Kaizyn
 * @Date: 2020-03-05 19:04:06
 * @LastEditors: Kaizyn
 * @LastEditTime: 2020-03-06 12:48:48
 * @FilePath: \Code\Luogu\luogu1850_2.cpp
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 2e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

int n, m, v, e;
int c[N], d[N], dis[N][N];
double k[N], dpc[2][N][N], dpd[2][N][N];

inline void floyd()
{
    for (int l = 1; l <= v; ++l)
        for (int i = 1; i <= v; ++i)
            for (int j = 1; j <= v; ++j)
                dis[i][j] = min(dis[i][j], dis[i][l]+dis[l][j]);
}

double calc()
{
    fill(dpc[0][0], dpc[1][N-1]+N, INF);
    fill(dpd[0][0], dpd[1][N-1]+N, INF);
    dpc[0][1][0] = dpd[0][1][0] = 0;
    for (int i = 1; i <= n; ++i) {
        // dp[k][i][j] k wheather (i-1) ask for change, j the number of ask in [1, i]
        for (int j = 0; j < i && j <= m; ++j) {
            dpc[0][i+1][j] = min(dpc[0][i][j]+dis[c[i]][c[i+1]], dpc[1][i][j]+dis[c[i]][c[i+1]]);
            dpd[0][i+1][j] = min(dpc[0][i][j]+dis[c[i]][d[i+1]], dpc[1][i][j]+dis[c[i]][d[i+1]]);
            dpc[1][i+1][j+1] = min(
                (1-k[i])*(dpc[0][i][j]+dis[c[i]][c[i+1]])+k[i]*(dpd[0][i][j]+dis[d[i]][c[i+1]]),
                (1-k[i])*(dpc[1][i][j]+dis[c[i]][c[i+1]])+k[i]*(dpd[1][i][j]+dis[d[i]][c[i+1]]));
            dpd[1][i+1][j+1] = min(
                (1-k[i])*(dpc[0][i][j]+dis[c[i]][d[i+1]])+k[i]*(dpd[0][i][j]+dis[d[i]][d[i+1]]),
                (1-k[i])*(dpc[1][i][j]+dis[c[i]][d[i+1]])+k[i]*(dpd[1][i][j]+dis[d[i]][d[i+1]]));
            #ifdef DEBUG
            printf("%d %d %.2f %.2f %.2f %.2f\n", i, j, dpc[0][i+1][j], dpd[0][i+1][j], dpc[1][i+1][j+1], dpd[1][i+1][j+1]);
            #endif
        }
    }
    double res = INF;
    for (int i = 0; i <= m && i <= n; ++i) {
        if (i) res = min(res, dpc[1][n+1][i]);
        if (i < n) res = min(res, dpc[0][n+1][i]);
    }
    #ifdef DEBUG
    for (int i = 0; i <= m; ++i) printf("%.2f%c", dpc[0][n+1][i], " \n"[i==m]);
    for (int i = 0; i <= m; ++i) printf("%.2f%c", dpc[1][n+1][i], " \n"[i==m]);
    #endif
    return res;
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
        dis[i][i] = dis[i][0] = dis[0][i] = 0;
    floyd();
    printf("%.2f\n", calc());
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