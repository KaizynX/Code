#include <bits/stdc++.h>

using namespace std;

const int N = 3e3+7;

int n, m;
int k[N], p[N];
int dp[N][N], vis[N][N];
vector<int> a[N], c[N];

int tree_dp(int u)
{
    if (u > n-m) {
        vis[u][1] = 1;
        dp[u][1] = p[u];
        return 1;
    }
    int son = 0;
    for (int i = 0, v, now; i < k[u]; ++i) {
        v = a[u][i];
        now = tree_dp(v);
        son += now;
        for (int j = son; j; --j) {
            for (int l = 1; l <= now && l <= j; ++l) {
                if (vis[u][j-l] && vis[v][l]) {
                    dp[u][j] = max(dp[u][j], dp[u][j-l]+dp[v][l]-c[u][i]);
                    vis[u][j] = 1;
                }
            }
        }
    }
    return son;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n-m; ++i) {
        cin >> k[i];
        a[i].resize(k[i], 0);
        c[i].resize(k[i], 0);
        for (int j = 0; j < k[i]; ++j)
            cin >> a[i][j] >> c[i][j];
    }
    for (int i = n-m+1; i <= n; ++i)
        cin >> p[i];

    memset(dp, 0xef, sizeof dp);
    for (int i = 1; i <= n; ++i)
        vis[i][0] = 1, dp[i][0] = 0;
    tree_dp(1);
    int res = 0;
    for (int i = m; i; --i) if (dp[1][i] >= 0) {
        res = i;
        break;
    }
    cout << res << endl;
    return 0;
}
