#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

#define DEBUG

using namespace std;

const int N = 2e3+7;
const long long INF = 1e18;

int n, m;
int a[N], d[N];
long long dp[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        d[i] = a[i];
    }
    sort(d+1, d+n+1);
    m = unique(d+1, d+n+1)-d-1;
    for (int i = 1; i <= n; ++i) {
        a[i] = lower_bound(d+1, d+m+1, a[i])-d;
    }
    long long res = INF;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = INF;
            for (int k = 1; k <= j; ++k) {
                dp[i][j] = min(dp[i][j], dp[i-1][k]+abs(d[a[i]]-d[j]));
            }
            if (i == n) res = min(res, dp[i][j]);
#ifdef DEBUG
            cout << "[" << i << ", " << j << "]=" << dp[i][j] << endl;
#endif
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            dp[i][j] = INF;
            for (int k = j; k <= m; ++k) {
                dp[i][j] = min(dp[i][j], dp[i-1][k]+abs(d[a[i]]-d[j]));
            }
            if (i == n) res = min(res, dp[i][j]);
#ifdef DEBUG
            cout << "[" << i << ", " << j << "]=" << dp[i][j] << endl;
#endif
        }
    }
    cout << res << endl;
    return 0;
}

