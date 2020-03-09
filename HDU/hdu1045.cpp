#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 10;

int n, xx, yy;
char a[N][N];
int vis[N], co[N], e[N][N], x[N][N], y[N][N];

bool check(int u)
{
    for (int v = 1; v <= yy; ++v) if (e[u][v]) {
        if (vis[v]) continue;
        vis[v] = 1;
        if (!co[v] || check(co[v])) {
            co[v] = u;
            return true;
        }
    }
    return false;
}

inline int solve()
{
    int res = 0;
    memset(co, 0, sizeof co);
    for (int i = 1; i <= xx; ++i) {
        memset(vis, 0, sizeof(int)*(xx+3));
        res += check(i);
    }
    return res;
}

int main()
{
    while (scanf("%d", &n) && n) {
        memset(e, 0, sizeof e);
        memset(x, 0, sizeof x);
        memset(y, 0, sizeof y);
        xx = yy = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%s", a[i]+1);
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (a[i][j] == 'X' || x[i][j]) continue;
                ++xx;
                for (int k = j; k <= n && a[i][k] != 'X'; ++k)
                    x[i][k] = xx;
            }
        }
        for (int j = 1; j <= n; ++j) {
            for (int i = 1; i <= n; ++i) {
                if (a[i][j] == 'X' || y[i][j]) continue;
                ++yy;
                for (int k = i; k <= n && a[k][j] != 'X'; ++k)
                    y[k][j] = yy;
            }
        }
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                e[x[i][j]][y[i][j]] = 1;
#ifdef DEBUG
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                printf("(%d,%d)%c", x[i][j], y[i][j], " \n"[j==n]);
            }
        }
#endif
        printf("%d\n", solve());
    }
    return 0;
}
