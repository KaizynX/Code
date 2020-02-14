#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, m;
int f[N][N];

int main()
{
    while (scanf("%d %d", &n, &m) && n|m) {
        memset(f, 0x3f, sizeof f);
        for (int i = 1; i <= n; ++i) f[i][i] = 0;
        for (int i = 1, u, v, w; i <= m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            f[u][v] = f[v][u] = min(f[u][v], w);
        }
        for (int k = 1; k <= n; ++k)
            for (int i = 1; i <= n; ++i)
                for (int j = 1; j <= n; ++j)
                    f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
        printf("%d\n", f[1][n]);
    }
    return 0;
}
