#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int M = 1e4+7;

int n, m;
long long dp[M];

int main()
{
    cin >> n >> m;
    dp[0] = 1;
    for (int i = 1, a; i <= n; ++i) {
        cin >> a;
        for (int j = m; j >= a; --j) {
            dp[j] += dp[j-a];
        }
    }
    cout << dp[m] << endl;
    return 0;
}
