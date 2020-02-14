#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
int a[N], f[N][N], p[N][N];

int main()
{
    while (scanf("%d", &n) == 1 && n) {
        memset(p, 0, sizeof p);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &f[i][j]),
                p[i][j] = j;
        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (f[i][k] == -1 || f[k][j] == -1 || k == i || k == j) continue;
                    int tmp = f[i][k]+f[k][j]+a[k];
                    if (f[i][j] == -1 || tmp < f[i][j]) {
                        f[i][j] = tmp;
                        p[i][j] = p[i][k];
                    } else if (tmp == f[i][j]) {
                        p[i][j] = min(p[i][j], p[i][k]);
                    }
                }
            }
        }
        int s, t;
        while (scanf("%d %d", &s, &t) == 2 && !(s == -1 && t == -1)) {
            printf("From %d to %d :\nPath: ", s, t);
            int now = s;
            while (now != t) {
                printf("%d-->", now);
                now = p[now][t];
            }
            printf("%d\nTotal cost : %d\n\n", t, f[s][t]);
        }
    }
    return 0;
}
