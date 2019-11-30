#include <bits/stdc++.h>

using namespace std;

int n, K;
long long res;
// dp[i][j][k] i'th row, j(2)states, put k
long long dp[10][1<<9][100];

int main()
{
    cin >> n >> K;
    dp[0][0][0] = 1;
    for (int i = 1, cnt, flag, tmp; i <= n; ++i) {
        for (int j = 0; j < (1<<n); ++j) {
            cnt = 0;
            flag = 1;
            for (int k = 1; k < n; ++k) {
                if (((j>>k)&1) && ((j>>(k-1))&1)) {
                    flag = 0;
                    break;
                }
            }
            if (!flag) continue;
            tmp = j;
            for (int k = 0; k < n; ++k) {
                if ((j>>k)&1) {
                    ++cnt;
                    if (k > 0) tmp |= 1<<(k-1);
                    if (k < n-1) tmp |= 1<<(k+1);
                }
            }
            for (int k = 0; k < (1<<n); ++k) {
                if (tmp&k) continue;
                for (int t = 0; t+cnt <= K; ++t) {
                    dp[i][j][t+cnt] += dp[i-1][k][t];
                }
            }
            if (i == n) res += dp[i][j][K];
        }
    }
    cout << res << endl;
    return 0;
}
