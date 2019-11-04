#include <bits/stdc++.h>
//#define DEBUG

using namespace std;

long long dp[32][2][2];

long long calc(int r, int l)
{
    // a^b == a+b
    // a <= r, b <= l
    memset(dp, 0, sizeof dp);
    int i = 30;
    while (i && !((r>>i)&1)) --i;
    dp[i+1][1][1] = 1;
    for ( ; i >= 0; --i) {
        if (((r>>i)&1) && ((l>>i)&1)) {
            dp[i][0][0] = 3*dp[i+1][0][0]+2*dp[i+1][0][1]+2*dp[i+1][1][0]+1*dp[i+1][1][1];
            dp[i][0][1] = 0*dp[i+1][0][0]+1*dp[i+1][0][1]+0*dp[i+1][1][0]+1*dp[i+1][1][1];
            dp[i][1][0] = 0*dp[i+1][0][0]+0*dp[i+1][0][1]+1*dp[i+1][1][0]+1*dp[i+1][1][1];
            dp[i][1][1] = 0*dp[i+1][0][0]+0*dp[i+1][0][1]+0*dp[i+1][1][0]+0*dp[i+1][1][1];
        } else if (((r>>i)&1) == 0 && ((l>>i)&1)) {
            dp[i][0][0] = 3*dp[i+1][0][0]+2*dp[i+1][0][1]+0*dp[i+1][1][0]+0*dp[i+1][1][1];
            dp[i][0][1] = 0*dp[i+1][0][0]+1*dp[i+1][0][1]+0*dp[i+1][1][0]+0*dp[i+1][1][1];
            dp[i][1][0] = 0*dp[i+1][0][0]+0*dp[i+1][0][1]+2*dp[i+1][1][0]+1*dp[i+1][1][1];
            dp[i][1][1] = 0*dp[i+1][0][0]+0*dp[i+1][0][1]+0*dp[i+1][1][0]+1*dp[i+1][1][1];
        } else if (((r>>i)&1) && ((l>>i)&1) == 0) {
            dp[i][0][0] = 3*dp[i+1][0][0]+0*dp[i+1][0][1]+2*dp[i+1][1][0]+0*dp[i+1][1][1];
            dp[i][0][1] = 0*dp[i+1][0][0]+2*dp[i+1][0][1]+0*dp[i+1][1][0]+1*dp[i+1][1][1];
            dp[i][1][0] = 0*dp[i+1][0][0]+0*dp[i+1][0][1]+1*dp[i+1][1][0]+0*dp[i+1][1][1];
            dp[i][1][1] = 0*dp[i+1][0][0]+0*dp[i+1][0][1]+0*dp[i+1][1][0]+1*dp[i+1][1][1];
        } else {
            dp[i][0][0] = 3*dp[i+1][0][0]+0*dp[i+1][0][1]+0*dp[i+1][1][0]+0*dp[i+1][1][1];
            dp[i][0][1] = 0*dp[i+1][0][0]+2*dp[i+1][0][1]+0*dp[i+1][1][0]+0*dp[i+1][1][1];
            dp[i][1][0] = 0*dp[i+1][0][0]+0*dp[i+1][0][1]+2*dp[i+1][1][0]+0*dp[i+1][1][1];
            dp[i][1][1] = 0*dp[i+1][0][0]+0*dp[i+1][0][1]+0*dp[i+1][1][0]+1*dp[i+1][1][1];
        }
#ifdef DEBUG
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                printf("dp[%d][%d][%d]=%I64d ", i, j, k, dp[i][j][k]);
            }
        }
        putchar('\n');
#endif
    }
    return dp[0][0][0]+dp[0][0][1]+dp[0][1][0]+dp[0][1][1];
}

int main()
{
    int t, l, r;
    cin >> t;
    while (t--) {
        cin >> l >> r;
#ifdef DEBUG
        cout << calc(r, r) << " " << calc(r, l-1) << " " << calc(l-1, l-1) << endl;
#endif
        if (!l && !r) cout << 1 << endl;
        else if (!l) cout << calc(r, r) << endl;
        else cout << (calc(r, r)-2*calc(r, l-1)+calc(l-1, l-1)) << endl;
    }
    return 0;
}
