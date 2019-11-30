#include <bits/stdc++.h>
#define DEBUG

using namespace std;

#ifdef DEBUG
const int N = 100;
#else
const int N = 150000+7;
#endif
const int M = 3e2+7;
const long long INF = 1e18;

int n, m, d;
int a[N], b[N], t[N];
long long dp[N][M], res = -INF;

int main()
{
    cin >> n >> m >> d;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i] >> t[i];
        int dis = d*(t[i]-t[i-1]);
        for (int j = 1; j <= n; ++j) {
            dp[i][j] = -INF;
            for (int k = max(1, j-dis); k <= min(n, j+dis); ++k) {
                dp[i][j] = max(dp[i][j], dp[i-1][k]+b[i]-abs(j-a[i]));
            }
            if (i == m) res = max(res, dp[i][j]);
        }
    }
    cout << res << endl;
    return 0;
}
