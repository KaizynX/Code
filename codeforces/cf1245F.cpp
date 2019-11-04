#include <bits/stdc++.h>
#define DEBUG

using namespace std;

const int N = 30;

int t, l, r;
// 0 small, 1 equal
long long dp[N][2];

inline long long get(int r, int l)
{
    for (int i = 0; i <= 30; ++i) dp[i][0] = dp[i][1] = 0;
    int i = 30;
    while (i && !((r>>i)&1)) --i;
    dp[i+1][1] = 1;
    for ( ; i >= 0; --i) {
        if ((r>>i)&1) {
            // Ö»ÄÜÌî0
            if ((l>>i)&1) {
                dp[i][0] = dp[i+1][0]+dp[i+1][1];
                dp[i][1] = 0;
            } else {
                dp[i][0] = dp[i+1][0];
                dp[i][1] = dp[i+1][1];
            }
        } else {
            // ÄÜÌî01
            if ((l>>i)&1) {
                dp[i][0] = 2*dp[i+1][0]+dp[i+1][1];
                dp[i][1] = dp[i+1][1];
            } else {
                dp[i][0] = 2*dp[i+1][0];
                dp[i][1] = dp[i+1][1];
            }
        }
#ifdef DEBUG
        printf("dp[%d]= %lld, %lld\n", i, dp[i][0], dp[i][1]);
#endif
    }
    return dp[0][0]+dp[0][1];
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> l >> r;
        if (!l) cout << 2*(get(r, r)) << endl;
        else cout << 2*(get(r, r)-get(r, l-1)) << endl;
    }
    return 0;
}
