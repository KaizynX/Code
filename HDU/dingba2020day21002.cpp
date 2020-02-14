#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+7;
const long long INF = 0x3f3f3f3f3f3f3f3f;

int n, k;
int a[N];
long long dp[N][N];

inline long long calc(int i, int j)
{
    return 1ll*(a[i]-a[j])*(a[i]-a[j]);
}

int main()
{
    while (cin >> n >> k) {
        for (int i = 1; i <= n; ++i)
            cin >> a[i];
        sort(a+1, a+n+1);
        // dp[][0] = 0;
        // dp[i][j] in [1, i] total choose k
        for (int i = 0; i <= n; ++i)
            for (int j = 1; j <= k; ++j)
                dp[i][j] = INF;
        for (int i = 2; i <= n; ++i)
            for (int j = 1; j <= k; ++j)
                dp[i][j] = min(dp[i-1][j], dp[i-2][j-1]+calc(i, i-1));
        cout << dp[n][k] << endl;
    }
    return 0;
}
