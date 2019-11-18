#include <bits/stdc++.h>

using namespace std;

const int N = 3e2+7;

int n, k;
int h[N];
// dp[i][j] at i'th delte j's(include i'th) <times, last height>
pair<long long, int> dp[N][N];

int main()
{
    cin >> n >> k;
    h[0] = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> h[i];
        for (int j = 0; j <= min(j, k); ++j) {
            dp[i][j] = dp[i-1][j];
        }
    }
    return 0;
}
