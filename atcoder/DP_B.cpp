#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n, k;
int h[Maxn], dp[Maxn];

int main()
{
    cin >> n >> k;
    for(int i = 1; i <= n; ++i) cin >> h[i];
    memset(dp, 0x3f, sizeof dp);
    dp[1] = 0;
    for(int i = 2; i <= n; ++i)
    {
        for(int j = 1; j <= k && i-j >= 1; ++j)
            dp[i] = min(dp[i], dp[i-j]+abs(h[i]-h[i-j]));
    }
    cout << dp[n] << endl;
    return 0;
}
