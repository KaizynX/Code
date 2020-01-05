#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;
const int N = 1e5+7;

int T, n, m;
int dp[N][2];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> n >> m;
        memset(dp, 0, sizeof(int)*(m+7));
        dp[0][0] = 1;
        for (int t = 1; t <= m; ++t) {
            dp[t][0] = static_cast<int>((n-1ll)*dp[t-1][1]%MOD);
            dp[t][1] = static_cast<int>((dp[t-1][0]+(n-2ll)*dp[t-1][1]%MOD)%MOD);
        }
        cout << dp[m][0] << endl;
    }
    return 0;
}

