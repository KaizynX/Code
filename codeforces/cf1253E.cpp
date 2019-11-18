#include <bits/stdc++.h>

using namespace std;

const int N = 100;
const int M = 1e5+7;

int n, m, res;
int dp[N][M];

struct Node
{
    int x, s;
    friend bool operator < (const Node &a, const Node &b) {
        return a.x < b.x;
    }
} p[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> p[i].x >> p[i].s;
    }
    sort(p+1, p+n+1);

    if (p[1].x-p[1].s > 1) {
        for (int j = 1; j <= min(m, 2*p[1].x-1); ++j)
            dp[1][j] = p[1].x-p[1].s-1;
        for (int j = 2*p[1].x; j <= m; ++j)
            dp[1][j] = dp[1][j-1]+1;
    } else {
        for (int j = 1; j <= min(m, p[1].x+p[1].s); ++j)
            dp[1][j] = 0;
        for (int j = p[1].x+p[1].s+1; j <= m; ++j)
            dp[1][j] = dp[1][j-1]+1;
    }

    for (int i = 2, l, r; i <= n; ++i) {
        l = p[i].x-p[i].s; r = p[i].x+p[i].s;
        for (int j = max(1, l); j <= min(m, r); ++j)
            dp[i][j] = dp[i-1][max(0, l-1)];
        for (int j = 1; r+j <= m; ++j) {
            if (l-j <= 1) dp[i][r+j] = min(dp[i-1][r+j], j);
            else dp[i][r+j] = min(dp[i-1][r+j], dp[i-1][l-j-1]+j);
        }
    }
    cout << dp[n][m] << endl;
    return 0;
}
