#include <bits/stdc++.h>

using namespace std;

const int N = 57;

int n, m;
int a[N][N];
int dp[N<<1][N][N];

inline void update(int &x, const int &y) { if (y > x) x = y; }

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    dp[2][1][1] = a[1][1];
    for (int t = 3; t <= n+m; ++t) {
        for (int x1 = 1, y1; x1 < t && x1 <= n; ++x1) {
            y1 = t-x1;
            if (y1 > m) continue;
            for (int x2 = 1, y2; x2 < t && x2 <= n; ++x2) {
                y2 = t-x2;
                if (y2 > m) continue;
                update(dp[t][x1][x2], dp[t-1][x1-1][x2-1]);
                update(dp[t][x1][x2], dp[t-1][x1][x2-1]);
                update(dp[t][x1][x2], dp[t-1][x1-1][x2]);
                update(dp[t][x1][x2], dp[t-1][x1][x2]);
                dp[t][x1][x2] += a[x1][y1];
                if (x1 != x2) dp[t][x1][x2] += a[x2][y2];
            }
        }
    }
    cout << dp[n+m][n][n] << endl;
    return 0;
}
