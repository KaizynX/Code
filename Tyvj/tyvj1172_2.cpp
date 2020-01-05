#include <bits/stdc++.h>

using namespace std;

const int N = 4e3+7;
const long long MOD = 2147483648;

int n;
long long dp[N];

int main()
{
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i < n; ++i)
        for (int j = i; j <= n; ++j)
            (dp[j] += dp[j-i]) %= MOD;
    cout << dp[n] << endl;
    return 0;
}
