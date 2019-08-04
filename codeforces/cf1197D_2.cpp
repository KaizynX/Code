#include <bits/stdc++.h>

using namespace std;

const int Maxn = 3e5+7;
const long long INF = 1e18;

int n, m, k;
int a[Maxn];
long long ans;
long long dp[Maxn][15];

int main()
{
    cin >> n >> m >> k;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 0; i <= n; ++i)
        for(int j = 0; j < m; ++j)
            dp[i][j] = -INF;
    dp[0][m-1] = 0;

    for(int i = 1; i <= n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(!j) dp[i][j] = max(dp[i-1][m-1]+a[i]-k, 1ll*a[i]-k);
            else dp[i][j] = dp[i-1][j-1]+a[i];
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
