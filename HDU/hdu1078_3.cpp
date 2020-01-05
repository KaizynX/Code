#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const int d[] = { 0, -1, 0, 1, 0 };

int n, k;
int a[N][N], dp[N][N];

int dfs(int x, int y)
{
    if (dp[x][y]) return dp[x][y];
    for (int i = 0, nx, ny; i < 4; ++i) {
        for (int j = 1; j <= k; ++j) {
            nx = x+j*d[i];
            ny = y+j*d[i+1];
            if (nx < 1 || ny < 1 || nx > n || ny > n || a[x][y] >= a[nx][ny])
                continue;
            dp[x][y] = max(dp[x][y], dfs(nx, ny));
        }
    }
    return dp[x][y] += a[x][y];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> k && !(n == -1 && k == -1)) {
        memset(dp, 0, sizeof dp);
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= n; ++j)
                cin >> a[i][j];
        cout << dfs(1, 1) << endl;
    }
    return 0;
}

