#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const int d[] = { 0, -1, 0, 1, 0 };

int n, k;
int a[N][N], dp[N][N];

struct Node
{
    int x, y, v;
    Node() {}
    Node(int _x, int _y, int _v) : x(_x), y(_y), v(_v) {}
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.v < n2.v;
    }
} b[N*N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> k && !(n == -1 && k == -1)) {
        int tot = 0, res = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                cin >> a[i][j];
                dp[i][j] = -1;
                b[++tot] = Node(i, j, a[i][j]);
            }
        }
        sort(b+1, b+tot+1);
        dp[1][1] = a[1][1];
        for (int i = 1, x, y, nx, ny; i <= tot; ++i) {
            x = b[i].x; y = b[i].y;
            for (int j = 1; j <= k; ++j) {
                for (int dd = 0; dd < 4; ++dd) {
                    nx = x+j*d[dd]; ny = y+j*d[dd+1];
                    if (nx < 1 || ny < 1 || nx > n || ny > n) continue;
                    if (a[x][y] <= a[nx][ny] || dp[nx][ny] == -1) continue;
                    dp[x][y] = max(dp[x][y], dp[nx][ny]+a[x][y]);
                }
            }
#ifdef DEBUG
            cout << "[" << x << ", " << y << "]=" << dp[x][y] << endl;
#endif
            res = max(res, dp[x][y]);
        }
        cout << res << endl;
    }
    return 0;
}
