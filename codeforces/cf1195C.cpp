#include <bits/stdc++.h>

using namespace std;

const int Maxn = 1e5+7;

int n;
int h[2][Maxn];
long long dp[2][Maxn], maxh[2];

int main()
{
    cin >> n;
    for(int i = 0; i < 2; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> h[i][j];
    for(int i = 1; i <= n; ++i)
    {
        // dp[x][i] = max(dp[x^1][1~i-1])
        dp[0][i] = h[0][i]+maxh[1];
        dp[1][i] = h[1][i]+maxh[0];
        maxh[0] = max(maxh[0], dp[0][i]);
        maxh[1] = max(maxh[1], dp[1][i]);
    }
    cout << max(maxh[0], maxh[1]) << endl;
    return 0;
}
