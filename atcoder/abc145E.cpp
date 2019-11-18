#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+7;

int n, t, res;
int a[N], b[N];
int dp[N][N];

int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i] >> b[i];
        for (int j = 0; j < t; ++j) {
            dp[i][j] = dp[i-1][j];
        }
        for (int j = a[i]; j < t; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-a[i]]+b[i]);
        }
        dp[i][t] = max(dp[i-1][t], dp[i-1][t-1]+b[i]);
    }
    cout << dp[n][t] << endl;
    return 0;
}
