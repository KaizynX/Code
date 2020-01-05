#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;

int T, n, m;
int a[N], b[N];
int dp[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        cin >> m;
        for (int i = 1; i <= m; ++i) cin >> b[i];

        int res = 0;
        for (int i = 1, val; i <= n; ++i) {
            val = 0;
            for (int j = 1; j <= m; ++j) {
                if (a[i] == b[j]) dp[i][j] = val+1;
                else dp[i][j] = dp[i-1][j];
                if (b[j] < a[i]) val = max(val, dp[i-1][j]);
                res = max(res, dp[i][j]);
            }
        }
        cout << res << endl;
        if (T) cout << endl;
    }
    return 0;
}
