#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;

int n, m, s, t;
int f[N][N];

int main()
{
    while (scanf("%d %d", &n, &m) == 2) {
        memset(f, -1, sizeof f);
        for (int i = 0; i < n; ++i) f[i][i] = 0;
        for (int i = 0, u, v, w; i < m; ++i) {
            scanf("%d %d %d", &u, &v, &w);
            if (f[u][v] != -1) w = min(w, f[u][v]);
            f[u][v] = f[v][u] = w;
        }
        scanf("%d %d", &s, &t);
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    if (f[i][k] != -1 && f[k][j] != -1 &&
                        (f[i][j] == -1 || f[i][k]+f[k][j] < f[i][j]))
                        f[i][j] = f[i][k]+f[k][j];
        printf("%d\n", f[s][t]);
    }
    return 0;
}
