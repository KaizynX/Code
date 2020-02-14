#include <bits/stdc++.h>

using namespace std;

const int N = 15;
const int d[] = {0,-1,0,1,0};

int n, m;
int a[N][N];
long long k, res;

void dfs(int x, int y, int t, long long v)
{
    if (t >= k) {
        res = max(res, v);
        return;
    }
    v += t-a[x][y];
    int tmp = a[x][y];
    a[x][y] = 0;
    for (int i = 0, nx, ny; i < 4; ++i) {
        nx = x+d[i]; ny = y+d[i+1];
        if (nx < 1 || ny < 1 || nx > n || ny > m) continue;
        dfs(nx, ny, t+1, v);
    }
    a[x][y] = tmp;
}

int main()
{
    int x, y;
    cin >> n >> m >> x >> y >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            res += a[i][j];
        }
    if (k >= n*m) {
        res += (n*m-1)*n*m/2;
        res += n*m*(k-n*m);
    } else {
        res = 0;
        for (int i = 1; i <= n; ++i)
            for (int j = 1; j <= m; ++j)
                a[i][j] = -a[i][j];
        dfs(x, y, 0, 0);
    }
    cout << res << endl;
    return 0;
}
