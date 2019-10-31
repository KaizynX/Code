#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;

int n, k;
int a[N], dp[N][N];
vector<int> e[N];

void treedp(int u, int last)
{
    dp[u][0] = a[u];
    for (int v : e[u]) {
        if (v == last) continue;
        treedp(v, u);
        dp[u][0] += dp[v][k];
        for (int d = 1; d <= k; ++d)
            dp[u][d] = max(dp[u][d], dp[v][d-1]);
    }

    /*
    for (int d = 1; d-1 <= k-d; ++d) {
        int sum = 0;
        for (int v : e[u]) if (v != last)
            sum += dp[v][k-d];
        for (int v : e[u]) if (v != last)
            dp[u][d] = max(dp[u][d], dp[v][d-1]+sum-dp[v][k-d]);
    }
    */
    for (int d = 1; d <= k; ++d) {
        int sum = 0;
        for (int v : e[u]) if (v != last)
            sum += dp[v][max(d-1, k-d)];
        for (int v : e[u]) if (v != last)
            dp[u][d] = max(dp[u][d], dp[v][d-1]+sum-dp[v][max(d-1, k-d)]);
    }
    for (int i = k-1; i >= 0; --i) {
        dp[u][i] = max(dp[u][i], dp[u][i+1]);
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
    }
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    treedp(1, 0);
    cout << dp[1][0] << endl;
    return 0;
}
