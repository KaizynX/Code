#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int M = 2e2+7;

int n, m, t;
int dp[M][M];

int main()
{
    cin >> n >> m >> t;
    for (int i = 1, mi, ti; i <= n; ++i) {
        cin >> mi >> ti;
        for (int j = m; j >= mi; --j) {
            for (int k = t; k >= ti; --k) {
                dp[j][k] = max(dp[j][k], dp[j-mi][k-ti]+1);
            }
        }
    }
    cout << dp[m][t] << endl;
    return 0;
}
