#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int dir[] = {0, -1, 0, 1, 0};

int n, m, q, bx, by, ex, ey;
int a[N][N], b[N][N];

#ifdef DEBUG
inline void print()
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            printf("%d ", b[i][j]);
        }
        putchar('\n');
    }
}
#endif

int main()
{
    while (scanf("%d %d", &n, &m) && n|m) {
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                scanf("%d", &a[i][j]);
        scanf("%d", &q);
        while (q--) {
            scanf("%d %d %d %d", &bx, &by, &ex, &ey);
            int flag = 0;
            if (!a[bx][by] || !a[ex][ey] || a[bx][by] != a[ex][ey]) {
                puts("NO");
                continue;
            }
            if (ey == by) {
                if (ex < bx) swap(ex, bx);
                flag = 1;
                for (int i = bx+1; i < ex; ++i) {
                    if (a[i][by]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    puts("YES");
                    continue;
                }
            }
            if (bx == ex) {
                if (ey < by) swap(ey, by);
                flag = 1;
                for (int i = by+1; i < ey; ++i) {
                    if (a[bx][i]) {
                        flag = 0;
                        break;
                    }
                }
                if (flag) {
                    puts("YES");
                    continue;
                }
            }
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    b[i][j] = 0;
            b[bx][by] += 1;
            b[ex][ey] += 2;
            for (int d = 0, x, y; d < 4; ++d) {
                for (int i = 1; i <= n; ++i) {
                    x = bx+dir[d]*i; y = by+dir[d+1]*i;
                    if (x < 1 || x > n || y < 1 || y > m || a[x][y]) break;
                    b[x][y] += 1;
                }
            }
            for (int d = 0, x, y; d < 4; ++d) {
                for (int i = 1; i <= n; ++i) {
                    x = ex+dir[d]*i; y = ey+dir[d+1]*i;
                    if (x < 1 || x > n || y < 1 || y > m || a[x][y]) break;
                    b[x][y] += 2;
                }
            }
#ifdef DEBUG
            print();
#endif
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= m; ++j)
                    if (b[i][j] == 3) flag = 1;
            if (flag) {
                puts("YES");
                continue;
            }
            for (int i = 1; i <= n; ++i) {
                for (int j = 1, t = 0; j <= m; ++j) {
                    if (b[i][j]+t == 3) flag = 1;
                    if (b[i][j]) t = b[i][j];
                    if (a[i][j]) t = 0;
                }
            }
            for (int j = 1; j <= m; ++j) {
                for (int i = 1, t = 0; i <= n; ++i) {
                    if (b[i][j]+t == 3) flag = 1;
                    if (b[i][j]) t = b[i][j];
                    if (a[i][j]) t = 0;
                }
            }
            puts((flag ? "YES" : "NO"));
        }
    }
    return 0;
}
