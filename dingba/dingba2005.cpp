#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;
const int M = 1e3+7;

int n, m, d, k;
int a[M][M];

int main()
{
    scanf("%d %d %d %d", &n, &m, &d, &k);
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= m; ++j) {
            scanf("%d", &a[i][j]);
            // a[i][j] = min(a[i][j], k);
        }
    }
    while (n--) {
        int x, y, res = 0;
        scanf("%d %d", &x, &y);
        for (int i = max(1, x-d); i <= min(m, x+d); ++i)
            for (int j = max(1, y-d); j <= min(m, y+d); ++j)
                if (abs(x-i)+abs(y-j) <= d) {
                    int tmp = min(a[i][j], k);
                    res += tmp;
                    a[i][j] -= tmp;
                    // res += a[i][j];
                }
        printf("%d\n", res);
    }
    return 0;
}
