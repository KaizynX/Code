#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int n, m;
int a[N][N], dp[N][N];

int main()
{
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                cin >> a[i][j];
                dp[i][j] = 0;
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                for (int k = 0; k <= j; ++k) {
                    dp[i][j] = max(dp[i][j], dp[i-1][j-k]+a[i][k]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
