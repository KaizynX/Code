#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e3+7;

int n, m, p;
int c[N], a[N][N], s[N][N], dp[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    // at time i at j'th machine
    for (int i = 1; i <= m; ++i)
        for (int j = 0; j < n; ++j)
            s[i][j] = s[i-1][(j-1+n)%n]+a[j][i];
    memset(dp, 0xef, sizeof dp);
    dp[0] = 0;
    for (int t = 1; t <= m; ++t) {
        for (int i = 0; i < n; ++i) {
            for (int j = 1; j <= p && j <= t; ++j) {
                // dp[t] = max(dp[t], dp[t-j]+s[t][i]-s[t-j][(i-j+n)%n]-c[(i-j+1+n)%n]);
                dp[t] = max(dp[t], dp[t-j]+s[t][(i+j-1)%n]-s[t-j][(i-1+n)%n]-c[i]);
            }
        }
    }
    cout << dp[m] << endl;
    return 0;
}
