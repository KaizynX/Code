#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int K = 1e1+7;

int n, m, k;
int a[N][3], s1[3][N][N][K], s2[N][N][K], dp[N][K];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
        }
    }
    for (int j = 1; j <= m; ++j) {
        // for (int i = 1; i <= n; ++i) s1[j][i][i][1] = max(0, a[i][j]);
        for (int len = 1; len <= n; ++len) {
            for (int l = 1, r; (r = l+len-1) <= n; ++l) {
                for (int i = l, now = 0; i <= r; ++i) {
                    now += a[i][j];
                    if (now < 0) now = 0;
                    s1[j][l][r][1] = max(s1[j][l][r][1], now);
                }
                for (int kk = 2; kk <= k; ++kk) {
                    for (int i = l; i < r; ++i) {
                        s1[j][l][r][kk] = max(s1[j][l][r][kk],
                                              s1[j][l][i][kk-1]+s1[j][i+1][r][1]);
                    }
                }
            }
        }
    }
    if (m == 1) {
        cout << s1[1][1][n][k] << endl;
        return 0;
    }
    for (int len = 1; len <= n; ++len) {
        for (int l = 1, r; (r = l+len-1) <= n; ++l) {
            for (int i = l, now = 0; i <= r; ++i) {
                now += a[i][1]+a[i][2];
                if (now < 0) now = 0;
                s2[l][r][1] = max(s2[l][r][1], now);
            }
            for (int kk = 2; kk <= k; ++kk) {
                for (int i = l; i < r; ++i) {
                    s2[l][r][kk] = max(s2[l][r][kk],
                                       s2[l][i][kk-1]+s2[i+1][r][1]);
                }
                for (int i = 0; i <= kk; ++i) {
                    s2[l][r][kk] = max(s2[l][r][kk],
                                       s1[1][l][r][i]+s1[2][l][r][kk-i]);
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= i; ++j) {
            for (int kk = 1; kk <= k; ++kk) {
                for (int kkk = 0; kkk <= kk; ++kkk) {
                    dp[i][kk] = max(dp[i][kk],
                                    dp[j][kkk]+s2[j+1][i][kk-kkk]);
                }
            }
        }
    }
    cout << dp[n][k] << endl;
    return 0;
}
