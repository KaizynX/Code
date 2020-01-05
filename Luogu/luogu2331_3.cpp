#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int K = 1e1+7;

int n, m, k;
int a[N][3], s1[K][3][N][N], s2[K][N][N], dp[K][N];

int main()
{
    memset(s1, 0xef, sizeof s1);
    memset(s2, 0xef, sizeof s2);
    memset(dp, 0xef, sizeof dp);
    memset(s1[0], 0, sizeof s1[0]);
    memset(s2[0], 0, sizeof s2[0]);
    memset(dp[0], 0, sizeof dp[0]);

    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    for (int j = 1; j <= m; ++j) {
        for (int len = 1; len <= n; ++len) {
            for (int l = 1, r; (r = l+len-1) <= n; ++l) {
                for (int i = l, now = 0; i <= r; ++i) {
                    now += a[i][j];
                    s1[1][j][l][r] = max(s1[1][j][l][r], now);
                    if (now < 0) now = 0;
                }
                for (int kk = 2; kk <= k && kk <= len; ++kk) {
                    for (int i = l; i < r; ++i) {
                        s1[kk][j][l][r] = max(s1[kk][j][l][r],
                                              s1[kk-1][j][l][i]+s1[1][j][i+1][r]);
                    }
                    for (int i = l; i < r; ++i) {
                        s1[kk][j][l][r] = max(s1[kk][j][l][r],
                                              s1[kk][j][l][i]);
                    }
                }
            }
        }
    }
    if (m == 1) {
        cout << s1[k][1][1][n] << endl;
        return 0;
    }
    for (int len = 1; len <= n; ++len) {
        for (int l = 1, r; (r = l+len-1) <= n; ++l) {
            for (int i = l, now = 0; i <= r; ++i) {
                now += a[i][1]+a[i][2];
                s2[1][l][r] = max(s2[1][l][r], now);
                if (now < 0) now = 0;
            }
            for (int kk = 2; kk <= k && kk <= len; ++kk) {
                for (int i = l; i < r; ++i) {
                    s2[kk][l][r] = max(s2[kk][l][r],
                                       s2[kk-1][l][i]+s2[1][i+1][r]);
                }
                for (int i = l; i < r; ++i) {
                    s2[kk][l][r] = max(s2[kk][l][r],
                                       s2[kk][l][i]);
                }
                for (int i = 0; i <= kk; ++i) {
                    s2[kk][l][r] = max(s2[kk][l][r],
                                       s1[i][1][l][r]+s1[kk-i][2][l][r]);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int kk = 1; kk <= k && kk <= i; ++kk) {
                for (int kkk = 0; kkk <= kk; ++kkk) {
                    dp[kk][i] = max(dp[kk][i],
                                    dp[kkk][j]+s2[kk-kkk][j+1][i]);
                }
            }
        }
    }
    cout << dp[k][n] << endl;
    return 0;
}
