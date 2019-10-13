#include <bits/stdc++.h>

using namespace std;

const int N = 3e5+7;
const long long INF = 1e18;

int q, n;
int a[N], b[N];
long long dp[N][3];

int main()
{
    cin >> q;
    while (q--) {
        cin >> n;
        a[0] = -666;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i] >> b[i];
        }
        long long res = -1;
        for (int i = 1; i <= n; ++i) {
            for (int np = 0; np < 3; ++np) {
                dp[i][np] = -1; // init
                for (int lp = 0; lp < 3; ++lp) {
                    int nh = a[i]+np, lh = a[i-1]+lp;
                    if (nh == lh || dp[i-1][lp] == -1) {
                        continue;
                    } else {
                        dp[i][np] = dp[i][np] == -1 ? dp[i-1][lp]+b[i]*np
                                    : min(dp[i][np], dp[i-1][lp]+b[i]*np);
                    }
                }
                if (i == n) {
                    res = (res == -1 ? dp[i][np] : min(res, dp[i][np]));
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
