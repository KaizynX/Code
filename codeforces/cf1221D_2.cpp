#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;
const long long INF = 1e18;

int q, n;
int a[N], b[N];
long long dp[N][3];

int main()
{
    scanf("%d", &q);
    while (q--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d %d", a+i, b+i);
        }
        long long res = INF;
        for (int i = 1; i <= n; ++i) {
            for (int np = 0; np < 3; ++np) {
                dp[i][np] = INF; // init
                for (int lp = 0; lp < 3; ++lp) {
                    if (i == 1 || a[i]+np != a[i-1]+lp) {
                        dp[i][np] = min(dp[i][np], dp[i-1][lp]+b[i]*np);
                    }
                }
                if (i == n) {
                    res = min(res, dp[i][np]);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
