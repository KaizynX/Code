#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+7;

int n, t, res;
int dp[N][N];

struct Node
{
    int a, b;
    friend bool operator < (const Node &x, const Node &y) {
        return x.a < y.a;
    }
} c[N];

int main()
{
    cin >> n >> t;
    for (int i = 1; i <= n; ++i)
        cin >> c[i].a >> c[i].b;
    sort(c+1, c+n+1);
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j < t; ++j) {
            dp[i][j] = dp[i-1][j];
        }
        for (int j = c[i].a; j < t; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-c[i].a]+c[i].b);
        }
        dp[i][t] = max(dp[i-1][t], dp[i-1][t-1]+c[i].b);
    }
    cout << dp[n][t] << endl;
    return 0;
}
