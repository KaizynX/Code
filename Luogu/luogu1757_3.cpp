#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int T = 1e2+7;

int n, m, t;
int dp[T][N];
vector<pair<int, int>> bag[T];

int main()
{
    cin >> m >> n;
    for (int i = 1, a, b, c; i <= n; ++i) {
        cin >> a >> b >> c;
        t = max(t, c);
        bag[c].push_back({a, b});
    }
    for (int i = 1; i <= t; ++i) {
        for (int j = 1; j <= m; ++j) dp[i][j] = dp[i-1][j];
        for (int j = 1; j <= m; ++j) {
            for (auto p : bag[i]) {
                if (p.first <= j)
                    dp[i][j] = max(dp[i][j], dp[i-1][j-p.first]+p.second);
            }
        }
    }
    cout << dp[t][m] << endl;
    return 0;
}
