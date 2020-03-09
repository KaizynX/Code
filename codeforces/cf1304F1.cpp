#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 55;
const int M = 2e4+7;

int n, m, k;
int a[N][M];
long long sum[N][M], dp[N][M], premv[N][M], bacmv[N][M];

template <typename T>
inline void update(T &x, const T &y) { if (y > x) x = y; }

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            sum[i][j] = sum[i][j-1]+a[i][j];
        }
    }

    for (int j = 1; j+k-1 <= m; ++j) {
        dp[1][j] = sum[1][j+k-1]-sum[1][j-1]+sum[2][j+k-1]-sum[2][j-1];
        premv[1][j] = max(premv[1][j-1], dp[1][j]);
    }
    for (int j = m-k+1; j; --j) bacmv[1][j] = max(bacmv[1][j+1], dp[1][j]);

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j+k-1 <= m; ++j) {
            // [j, j+k-1]
            long long s = sum[i][j+k-1]-sum[i][j-1]+sum[i+1][j+k-1]-sum[i+1][j-1];
            if (j+k <= m) update(dp[i][j], s+bacmv[i-1][j+k]);
            if (j-k >= 1) update(dp[i][j], s+premv[i-1][j-k]);
            for (int p = max(1, j-k+1); p <= j; ++p)
                update(dp[i][j], dp[i-1][p]+s-sum[i][p+k-1]+sum[i][j-1]);
            for (int p = j+1; p+k-1 <= m && p <= j+k-1; ++p)
                update(dp[i][j], dp[i-1][p]+s-sum[i][j+k-1]+sum[i][p-1]);
            premv[i][j] = max(premv[i][j-1], dp[i][j]);
        }
        for (int j = m-k+1; j; --j) bacmv[i][j] = max(bacmv[i][j+1], dp[i][j]);
#ifdef DEBUG
        for (int j = 1; j <= m-k+1; ++j)
            cout << dp[i][j] << " \n"[j==m-k+1];
#endif
    }
    cout << premv[n][m-k+1] << endl;
    return 0;
}
