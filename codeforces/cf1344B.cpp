/*
 * @Author: Kaizyn
 * @Date: 2020-05-06 22:33:16
 * @LastEditTime: 2020-05-06 23:51:48
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

const int dir[] = {0,-1,0,1,0};

int n, m;
char s[N];
int a[N][N], vis[N][N];
int cu[N][N], cd[N][N], rl[N][N], rr[N][N];
queue<pii> q;

void bfs(const int &sx, const int &sy) {
    q.push({sx, sy});
    vis[sx][sy] = 1;
    while (q.size()) {
        int ux = q.front().first,
            uy = q.front().second;
        q.pop();
        for (int i = 0, vx, vy; i < 4; ++i) {
            vx = ux+dir[i];
            vy = uy+dir[i+1];
            if (vx < 1 || vy < 1 || vx > n || vy > m ||
                vis[vx][vy] || !a[vx][vy]) continue;
            q.push({vx, vy});
            vis[vx][vy] = 1;
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", s+1);
        for (int j = 1; j <= m; ++j) {
            a[i][j] = s[j] == '#';
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            rl[i][j] = rl[i][j-1]+a[i][j];
        }
        for (int j = m; j; --j) {
            rr[i][j] = rr[i][j+1]+a[i][j];
        }
    }
    for (int j = 1; j <= m; ++j) {
        for (int i = 1; i <= n; ++i) {
            cu[i][j] = cu[i-1][j]+a[i][j];
        }
        for (int i = n; i; --i) {
            cd[i][j] = cd[i+1][j]+a[i][j];
        }
    }
    #ifdef DEBUG
    puts("%%%");
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            printf("%d%c", rl[i][j], " \n"[j==m]);
    puts("%%%");
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            printf("%d%c", rr[i][j], " \n"[j==m]);
    puts("%%%");
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            printf("%d%c", cu[i][j], " \n"[j==m]);
    puts("%%%");
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            printf("%d%c", cd[i][j], " \n"[j==m]);
    puts("%%%");
    #endif
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j]) continue;
            if ((rl[i][j] && rr[i][j]) || (cu[i][j] && cd[i][j])) {
                return puts("-1"), 0;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (rl[i][m]) continue;
        int flag = 0;
        for (int j = 1; j <= m; ++j) {
            if (cu[n][j]) continue;
            flag = 1;
            break;
        }
        if (!flag) return puts("-1"), 0;
    }
    for (int j = 1; j <= m; ++j) {
        if (cu[n][j]) continue;
        int flag = 0;
        for (int i = 1; i <= n; ++i) {
            if (rl[i][m]) continue;
            flag = 1;
            break;
        }
        if (!flag) return puts("-1"), 0;
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (vis[i][j] || !a[i][j]) continue;
            ++res;
            bfs(i, j);
        }
    }
    printf("%d\n", res);
    return 0;
}