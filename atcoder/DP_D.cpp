#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e2+7;
const int Maxw = 1e5+7;

int n, W;
long long dp[Maxw];

int main()
{
    cin >> n >> W;
    for(int i = 1, wi, vi; i <= n; ++i)
    {
        cin >> wi >> vi;
        for(int j = W; j >= wi; --j)
            dp[j] = max(dp[j], dp[j-wi]+vi);
    }
    cout << dp[W] << endl;
    return 0;
}
