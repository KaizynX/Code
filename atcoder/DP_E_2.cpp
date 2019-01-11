#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;
const int Maxv = 1e5+7;
#ifdef DEBUG
const int V = 20;
#else
const int V = 1e5;
#endif

int n, W;
long long dp[Maxv];

int main()
{
    cin >> n >> W;
    memset(dp, 0x3f, sizeof dp);
    dp[0] = 0;
    for(int i = 1, wi, vi; i <= n; ++i)
    {
        cin >> wi >> vi;
        for(int j = V; j >= vi; --j)
            dp[j] = min(dp[j], dp[j-vi]+wi);
#ifdef DEBUG
        for(int j = 0; j <= V; ++j)
            cout << dp[j] << " ";
        cout << endl;
#endif
    }
    for(int i = V; i >= 0; --i)
        if(dp[i] <= W)
            return printf("%d\n", i)&0;
    return 0;
}
