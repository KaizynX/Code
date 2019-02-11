#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;
const int MOD = 1e6+7;

int n, m;
int a[Maxn], dp[Maxn][Maxn];

int main()
{
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    //dp[0][0] = 1;
    for(int i = 0; i <= m; ++i) dp[0][i] = 1;
    // i kind flowers
    int pre = 0;
    for(int i = 1; i <= n; ++i)
    {
        // flower[i] take number j
        for(int j = 0; j <= a[i]; ++j)
        {
            // k'th flower
            for(int k = min(pre+j, m); k >= j; --k)
            {
                (dp[i][k] += dp[i-1][k-j]) %= MOD;
            }
        }
        pre = min(m, pre+a[i]);
    }
    cout << dp[n][m] << endl;
    return 0;
}