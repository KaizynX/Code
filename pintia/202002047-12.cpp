#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n;
int dp[N];
vector<int> d[N];

int dfs(int u)
{
    if (dp[u]) return dp[u];
    for (int v : d[u]) {
        dp[u] = max(dp[u], dfs(v)+1);
    }
    return dp[u];
}

int main()
{
    cin >> n;
    for (int i = 1, k, a; i <= n; ++i) {
        cin >> k;
        for (int j = 1; j <= k; ++j) {
            cin >> a;
            d[a].emplace_back(i);
        }
    }
    int res = 1;
    for (int i = 1; i <= n; ++i) {
        if (!dp[i]) dfs(i);
        if (dp[i] > dp[res]) res = i;
    }
    cout << res << endl;
    return 0;
}
