#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;

int n, m;
int r[4][N][N], c[4][N][N];
int a[N][N];

#ifdef DEBUG
template <typename T> inline void print(const T g[N][N])
{
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            printf("%3d", g[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
#endif

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1, x1, y1, x2, y2; i <= m; ++i) {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        ++r[3][x1+1][y1]; --r[3][x1+1][y2+1];
        r[3][x2+1][y1] -= x2-x1+1; r[3][x2+1][y2+1] += x2-x1+1;
        r[3][x2+2][y1] += x2-x1; r[3][x2+2][y2+1] -= x2-x1;
        ++c[3][x1][y1+1]; --c[3][x2+1][y1+1];
        c[3][x1][y2+1] -= y2-y1+1; c[3][x2+1][y2+1] += y2-y1+1;
        c[3][x1][y2+2] += y2-y1; c[3][x2+1][y2+2] -= y2-y1;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            r[2][i][j] = r[2][i][j-1]+r[3][i][j];
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= n; ++i)
            r[1][i][j] = r[1][i-1][j]+r[2][i][j];
    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= n; ++i)
            r[0][i][j] = r[0][i-1][j]+r[1][i][j];

    for (int j = 1; j <= n; ++j)
        for (int i = 1; i <= n; ++i)
            c[2][i][j] = c[2][i-1][j]+c[3][i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            c[1][i][j] = c[1][i][j-1]+c[2][i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            c[0][i][j] = c[0][i][j-1]+c[1][i][j];

    long long res = 1;
    int flag = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j){
            a[i][j] = (r[0][i][j]+c[0][i][j])%MOD;
            if (a[i][j] == 0) continue;
            flag = 1;
            res = res*a[i][j]%MOD;
        }
    }
#ifdef DEBUG
    print(r[0]);
    print(c[0]);
    print(a);
#endif
    if (flag) printf("%d\n", static_cast<int>(res));
    else puts("0");
    return 0;
}
