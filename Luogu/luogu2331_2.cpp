#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const int K = 1e1+7;

int n, m, k;
int a[N][N];
int s1[2][2][N][N][K], s2[2][N][N][K], mv[N][N][K];
int dp[N][K];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            for (int t = 1; t <= k; ++t) {
                if (m == 2) {
                    s2[0][l][r][t] = max(s2[0][l][r-1][t], s2[1][l][r-1][t]);
                    s2[1][l][r][t] = a[r][1]+a[r][2]+
                        max({s2[0][l][r-1][t-1], s2[1][l][r-1][t-1], s2[1][l][r-1][t]});
                    mv[l][r][k] = max(s2[0][l][r][t], s2[1][l][r][t]);
                }
                for (int j = 1; j <= m; ++j) {
                    s1[j][0][l][r][t] = max(s1[j][0][l][r-1][t], s1[j][1][l][r-1][t]);
                    s1[j][1][l][r][t] = a[r][j]+
                        max({s1[j][0][l][r-1][t-1], s1[j][1][l][r-1][t-1], s1[j][1][l][r-1][t]});
                }
                for (int i = 0; i <= t; ++i) {
                    mv[l][r][k] = max(mv[l][r][k],
                            max(s1[1][0][l][r][i], s1[1][1][l][r][i])+
                            max(s1[2][0][l][r][t-i], s1[2][1][l][r][t-i]));
                }
            }
        }
    }
    if (m == 1) {
        cout << max(s1[1][0][1][n][k], s1[1][1][1][n][k]) << endl;
        return 0;
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 0; j < i; ++j)
            for (int t = 1; t <= k; ++t)
                for (int l = 0; l <= t; ++l)
                    dp[i][t] = max(dp[i][t], dp[j][l]+mv[j+1][i][t-l]);

    cout << dp[n][k] << endl;

    /*
    for (int j = 1; j <= m; ++j) {
        for (int l = 1; l <= n; ++l) {
            for (int r = l; r <= n; ++r) {
                for (int t = 1; t <= k; ++t) {
                    s1[j][0][l][r][t] = 
                        max(s1[j][0][l][r-1][t], s1[j][1][l][r-1][t]);
                    s1[j][1][l][r][t] = a[r][j]+
                        max({s1[j][1][l][r-1][t], s1[j][0][l][r-1][t-1], s1[j][1][l][r-1][t-1]});
                }
            }
        }
    }
    if (m == 1) {
        cout << max(s1[1][0][1][n][k], s1[1][1][1][n][k]) << endl;
        return 0;
    }
    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            for (int t = 1; t <= k; ++t) {
                s2[0][l][r][t] = 
                    max(s2[0][l][r-1][t], s2[1][l][r-1][t]);
                s2[1][l][r][t] = a[r][0]+a[r][1]+
                    max({s2[0][l][r-1][t-1], s2[1][l][r-1][t], s2[1][l][r-1][t-1]});
            }
        }
    }
    for (int l = 1; l <= n; ++l) {
        for (int r = l; r <= n; ++r) {
            for (int t = 1; t <= k; ++t) {
                mv[l][r][t] = max(s2[0][l][r][t], s2[1][l][r][t]);
                for (int i = 0; i <= t; ++i) {
                    mv[l][r][t] = max(mv[l][r][t],
                        max(s1[1][0][l][r][i], s1[1][1][l][r][i])+
                        max(s1[2][0][l][r][t-i], s1[2][1][l][r][t-i]));
                }
#ifdef DEBUG
                printf("mv[%d][%d][%d]=%d\n", l, r, t, mv[l][r][t]);
#endif
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        for (int t = 1; t <= k; ++t) {
            for (int j = 0; j < i; ++j) {
                for (int l = 0; l <= t; ++l) {
                    dp[i][t] = max(dp[i][t], dp[j][t-l]+mv[j+1][i][l]);
                }
            }
        }
    }
    cout << dp[n][k] << endl;
    */
    return 0;
}
