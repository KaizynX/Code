#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int wx[] = {-2,-2,-1,+1,+2,+2,-1,+1};
const int wy[] = {-1,+1,+2,+2,-1,+1,-2,-2};
const int jx[] = {-1,-1,+0,+0,+1,+1,+0,+0};
const int jy[] = {+0,+0,+1,+1,+0,+0,-1,-1};

int n, m;
int res[N][N];
char a[N][N];
typedef pair<int, int> pii;
queue<pii> q;

inline void bfs(int bx, int by)
{
    q.push({bx, by});
    res[bx][by] = 0;
    while (q.size()) {
        pii u = q.front();
        q.pop();
        for (int i = 0, nx, ny; i < 8; ++i) {
            nx = u.first+wx[i];
            ny = u.second+wy[i];
            if (nx < 1 || ny < 1 || nx > n || ny > m ||
                a[nx][ny] == 'X' || res[nx][ny] != -1 ||
                a[u.first+jx[i]][u.second+jy[i]] == 'X') continue;
            res[nx][ny] = res[u.first][u.second]+1;
            q.push({nx, ny});
        }
    }
}

int main()
{
    int bx, by;
    scanf("%d%d", &n, &m);
    memset(res, -1, sizeof res);
    for (int i = 1; i <= n; ++i) {
        scanf("%s", a[i]+1);
        for (int j = 1; j <= m; ++j)
            if (a[i][j] == 'M') bx = i, by = j;
    }
    bfs(bx, by);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            printf("%d%c", res[i][j], " \n"[j==m]);
    return 0;
}
