#include <bits/stdc++.h>
// #define DEBUG

using namespace std;

const int dx[4] = { -1, 1, 0, 0 },
          dy[4] = { 0, 0, -1, 1 };

int T, num, ans;
int f[30], m[30][30], r[3][5];

void dfs(int x, int y)
{
    m[x][y] = 1;
    for (int d = 0, nx, ny; d < 4; ++d) {
        nx = x+dx[d];
        ny = y+dy[d];
        if(nx < 0 || ny < 0 || nx > 20 || ny > 20 || m[nx][ny]) continue;
        dfs(nx, ny);
    }
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        // 初始化
        num = 0;
        ans = 0;
        for (int i = 0; i <= 20; ++i)
            for (int j = 0; j <= 20; ++j)
                m[i][j] = 0;
        // 读入
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 4; ++j) {
                scanf("%d", &r[i][j]);
                f[++num] = r[i][j];
            }
        }
        // 离散化
        sort(f+1, f+num+1);
        // num is end
        num = unique(f+1, f+num+1)-f;
        for (int i = 0; i < 2; ++i)
            for (int j = 0; j < 4; ++j)
                r[i][j] = (lower_bound(f+1, f+num, r[i][j])-f)*2-1;

        for (int i = 0; i < 2; ++i) {
            // j (x1, x2)
            for (int j = r[i][0]; j <= r[i][2]; ++j)
                m[j][r[i][1]] = m[j][r[i][3]] = 1;
            // j (y1 - y2)
            for (int j = r[i][1]; j <= r[i][3]; ++j)
                m[r[i][0]][j] = m[r[i][2]][j] = 1;
        }
#ifdef DEBUG
        for (int i = 0; i <= 20; ++i) {
            for (int j = 0; j <= 20; ++j) {
                printf("%d ", m[i][j]);
            }
            putchar('\n');
        }
#endif
        for (int i = 0; i <= 20; ++i)
            for (int j = 0; j <= 20; ++j) {
                if (!m[i][j]) {
                    ++ans;
                    dfs(i, j);
                }
            }
        printf("%d\n", ans);
    }
    return 0;
}
