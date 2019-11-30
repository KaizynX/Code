#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;
const int M = 1e4+7;

int T, n, m;
int dp[M];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int E, F;
    cin >> T;
    while (T--) {
        cin >> E >> F >> n;
        m = F-E;
        memset(dp, -1, sizeof(int)*(m+7));
        dp[0] = 0;
        for (int i = 1, p, w; i <= n; ++i) {
            cin >> p >> w;
            for (int j = w; j <= m; ++j) {
                if (dp[j-w] == -1) continue;
                if (dp[j] == -1 || dp[j] > dp[j-w]+p)
                    dp[j] = dp[j-w]+p;
            }
        }
        if (dp[m] == -1) cout << "This is impossible.\n";
        else cout << "The minimum amount of money in the piggy-bank is "
                  << dp[m]  << ".\n";
    }
    return 0;
}
