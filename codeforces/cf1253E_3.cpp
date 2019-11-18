#include <bits/stdc++.h>
// #define DEBUG

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
    for (int i = 0; i <= m; ++i) dp[0][i] = i;

    for (int i = 1, l, r; i <= n; ++i) {
        l = p[i].x-p[i].s; r = p[i].x+p[i].s;
        for (int j = 1; j <= m; ++j) dp[i][j] = dp[i-1][j];
        for (int j = max(l, 1); j <= min(m, r); ++j)
            dp[i][j] = dp[i-1][max(0, l-1)];
        for (int j = 1; r+j <= m; ++j)
            dp[i][r+j] = min(dp[i][r+j], dp[i-1][max(0, l-j-1)]+j);
#ifdef DEBUG
        for (int j = 1; j <= m; ++j) cout << dp[i][j] << " ";
        cout << endl;
#endif
    }
    cout << dp[n][m] << endl;
    return 0;
}
