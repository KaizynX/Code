#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;

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
                if (i == 1 && j == 1) continue;
                b[++tot] = Node(i, j, a[i][j]);
            }
        }
        sort(b+1, b+tot+1);
        memset(dp, -1, sizeof dp);
        dp[1][1] = a[1][1];
        for (int t = 1, x, y; t <= tot; ++t) {
            x = b[t].x; y = b[t].y;
            for (int i = max(-k, 1-x); i <= min(k, n-x); ++i) {
                for (int j = max(-k+abs(i), 1-y); j <= min(k-abs(i), n-y); ++j) {
                    if (a[x+i][y+j] < a[x][y] && dp[x+i][y+j] != -1) {
                        dp[x][y] = max(dp[x][y], dp[x+i][y+j]+a[x][y]);
                    }
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
