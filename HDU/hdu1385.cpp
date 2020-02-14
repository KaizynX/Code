#include <bits/stdc++.h>

using namespace std;

const int N = 55;

int n;
int a[N], f[N][N], p[N][N];

void print(int s, int t)
{
    int k = p[s][t];
    if (!k) return;
    print(s, k);
    printf("-->%d", k);
    print(k, t);
}

int main()
{
    while (scanf("%d", &n) == 1 && n) {
        memset(p, 0, sizeof p);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                scanf("%d", &f[i][j]);
        for (int i = 1; i <= n; ++i)
            scanf("%d", a+i);
        for (int k = 1; k <= n; ++k) {
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= n; ++j) {
                    if (f[i][k] == -1 || f[k][j] == -1 || k == i || k == j) continue;
                    int tmp = f[i][k]+f[k][j]+a[k];
                    if (f[i][j] == -1 || tmp < f[i][j] || (tmp == f[i][j] && k < j)) {
                        f[i][j] = tmp;
                        p[i][j] = k;
                    }
                }
            }
        }
        int s, t, flag = 0;
        while (scanf("%d %d", &s, &t) == 2 && !(s == -1 && t == -1)) {
            if (flag) putchar('\n');
            flag = 1;
            printf("From %d to %d : \nPath: %d", s, t, s);
            print(s, t);
            printf("-->%d\nTotal cost : %d\n", t, f[s][t]);
        }
    }
    return 0;
}
