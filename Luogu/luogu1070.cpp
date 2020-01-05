#include <bits/stdc++.h>

#define SIMPLE

using namespace std;

#ifndef SIMPLE
const int N = 1e3+7;
#else
const int N = 2e2+7;
#endif

int n, m, p;
int c[N], a[N][N], s[N][N][N], dp[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> p;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 1; i <= n; ++i)
        cin >> c[i];
    // from i'th at time j walk k steps
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            for (int k = 1; k <= p; ++k) {
                s[i][j][k] = s[i][j][k-1]+a[i+k-1][j+k-1];
            }
        }
    }
    memset(dp, 0xef, sizeof dp);
    dp[0] = 0;
    for (int t = 1; t <= m; ++t) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= p && j <= t; ++j) {
                dp[t] = max(dp[t], dp[t-j]+s[i][t-j+1][j]-c[i]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}
