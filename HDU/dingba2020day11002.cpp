#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

int T, n;
int dp[N];

int main()
{
    cin >> T;
    while (T--) {
        cin >> n;
        dp[0] = 1;
        for (int i = 1; i <= n; ++i) {
            dp[i] = dp[i-1];
            if (i-3 >= 0) dp[i] += dp[i-3];
        }
        cout << dp[n] << endl;
    }
    return 0;
}
