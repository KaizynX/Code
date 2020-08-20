#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int t, n;
int a[N], b[N], dp[N][N];

int main()
{
    cin >> t;
    while (t--) {
        cin >> n;
        int sum = 0;
        memset(dp, 0x3f, sizeof dp);
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
            sum += a[i];
        }
        for (int i = 1, tmp; i <= n; ++i) {
            cin >> tmp;
            b[i] = a[tmp];
        }
        dp[1][0] = 0; dp[1][1] = b[1];
        for (int i = 2; i <= n; ++i) {
            for (int j = i/2; j <= min(i, n/2); ++j) {
                dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]+b[i]);
            }
        }
        cout << sum-2*dp[n][n/2] << endl;
    }
    return 0;
}
