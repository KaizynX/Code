#include <bits/stdc++.h>

using namespace std;

const int N = 70;

int T, n, m;
char buf[N];
int a[N][N], row[N], col[N];

int main()
{
    scanf("%d", &T);
    while (T--) {
        int sum = 0;
        scanf("%d %d", &n, &m);
        memset(row, 0, sizeof(int)*(n+1));
        memset(col, 0, sizeof(int)*(m+1));
        for (int i = 1; i <= n; ++i) {
            scanf("%s", buf+1);
            for (int j = 1; j <= m; ++j) {
                a[i][j] = buf[j] == 'A' ? 1 : 0;
                row[i] += a[i][j];
                col[j] += a[i][j];
                sum += a[i][j];
            }
        }
        if (sum == n*m) {
            puts("0");
            continue;
        } else if (!sum) {
            puts("MORTAL");
            continue;
        }
        if (row[1] == m || row[n] == m || col[1] == n || col[m] == n) {
            puts("1");
            continue;
        }
        int flag = 0;
        for (int i = 1; i <= n; ++i)
            if (row[i] == m) flag = 1;
        for (int j = 1; j <= m; ++j)
            if (col[j] == n) flag = 1;
        if (a[1][1] || a[1][m] || a[n][1] || a[n][m])
            flag = 1;
        if (flag) {
            puts("2");
            continue;
        }
        flag = 0;
        for (int i = 1; i <= n; ++i)
            if (a[i][1] || a[i][m])
                flag = 1;
        for (int j = 1; j <= m; ++j)
            if (a[1][j] || a[n][j])
                flag = 1;
        if (flag) {
            puts("3");
            continue;
        }
        puts("4");
    }
    return 0;
}
