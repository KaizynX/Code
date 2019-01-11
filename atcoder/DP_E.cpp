#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;
const int Maxv = 1e5+7;
const int V = 1e5;

int n, W;
long long dp[Maxn][Maxv];

int main()
{
    cin >> n >> W;
    memset(dp, 0x3f, sizeof dp);
    memset(dp[0], 0, sizeof dp[0]);
    for(int i = 1, wi, vi; i <= n; ++i)
    {
        cin >> wi >> vi;
        for(int j = V; j >= vi; --j)
            dp[i][j] = min(dp[i][j], dp[i-1][j-vi]+wi);
    }
    for(int i = V; i >= 0; ++i)
        if(dp[n][i] <= W)
            return printf("%d\n", i)&0;
    return 0;
}
