#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, m;
int f[N][N];

int main()
{
    while (scanf("%d %d", &n, &m) == 2) {
        memset(f, 0x3f, sizeof f);
        for (int i = 0; i < n; ++i) f[i][i] = 0;
        for (int i = 0, u, v; i < m; ++i) {
            scanf("%d %d", &u, &v);
            f[u][v] = f[v][u] = 1;
        }
        for (int k = 0; k < n; ++k)
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < n; ++j)
                    f[i][j] = min(f[i][j], f[i][k]+f[k][j]);
        int flag = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                flag |= f[i][j] > 7;
        puts((flag ? "No" : "Yes"));
    }
    return 0;
}
