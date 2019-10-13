#include <bits/stdc++.h>
#define DEBUG
 
using namespace std;
 
const int N = 4+3;
const int M = 1e2+7;
 
int t, n, m, res;
int a[N][M], dp[M][N][N], sum[N];
// dp[j][ns][i] col j rorate ns the val of row i

int main()
{
    cin >> t;
    while (t--) {
        res = 0;
        cin >> n >> m;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        for (int j = 0; j < m; ++j) {
            for (int ns = 0; ns < n; ++ns) {
                for (int i = 0; i < n; ++i) {
                    dp[j][ns][i] = a[(i+ns)%n][j];
                }
            }
        }
        for (int j = 1; j < m; ++j) {
            for (int ns = 0; ns < n; ++ns) {
                for (int i = 0; i < n; ++i) {
                    for (int ls = 0; ls < n; ++ls) {
                        dp[j][ns][i] = max(dp[j][ns][i], dp[j-1][ls][i]);
                    }
#ifdef DEBUG
                    printf("dp[%d][%d][%d]=%d\n", j, ns, i, dp[j][ns][i]);
#endif
                }
            }
        }
        for (int ns = 0; ns < n; ++ns) {
            sum[ns] = 0;
            for (int i = 0; i < n; ++i) {
                sum[ns] += dp[m-1][ns][i];
                res = max(res, sum[ns]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
