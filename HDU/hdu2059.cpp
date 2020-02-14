#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int L, n, c, t, vr, vt1, vt2;
int p[N];
// dp[i] get charge i
double dp[N];

int main()
{
    while (cin >> L) {
        cin >> n >> c >> t;
        cin >> vr >> vt1 >> vt2;
        for (int i = 1; i <= n; ++i)
            cin >> p[i];
        p[0] = 0; p[n+1] = L;
        fill(dp+1, dp+n+2, 1e10);
        for (int i = 1; i <= n+1; ++i) {
            dp[i] = 1.0*min(c, p[i])/vt1+1.0*max(0, p[i]-c)/vt2;
            // get charge at p[j]
            for (int j = 1; j < i; ++j) {
                dp[i] = min(dp[i],
                    dp[j]+t+1.0*min(c, p[i]-p[j])/vt1+1.0*max(0, p[i]-p[j]-c)/vt2);
            }
        }
        // cout << dp[n+1] << " " << 1.0*L/vr << endl;
        cout << (dp[n+1] < 1.0*L/vr ? "What a pity rabbit!" : "Good job,rabbit!") << endl;
    }
    return 0;
}
