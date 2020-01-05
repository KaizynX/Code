#include <bits/stdc++.h>

using namespace std;

const int N = 3e2+7;

int n, m;
int k[N], s[N], du[N];
int dp[N][N];
vector<int> e[N];
queue<int> q;

int main()
{
    memset(dp, -1, sizeof dp);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> k[i] >> s[i];
        ++du[k[i]];
        e[k[i]].emplace_back(i);
    }
    for (int i = 0; i <= n; ++i) {
        if (!du[i]) q.push(i);
        dp[i][0] = 0;
        dp[i][1] = s[i];
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : e[u]) {
            for (int i = m+1; i >= 1; --i) {
                for (int j = 1; i-j >= 1; ++j) {
                    if (dp[u][i-j] == -1) continue;
                    if (dp[v][j] == -1) continue;
                    dp[u][i] = max(dp[u][i], dp[u][i-j]+dp[v][j]);
                }
            }
            /*
            for (int i = 1; i <= m+1; ++i) {
                if (dp[v][i] == -1) continue;
                for (int j = m+1; j-i >= 1; --j) {
                    if (dp[u][j-i] != -1)
                        dp[u][j] = max(dp[u][j], dp[u][j-i]+dp[v][i]);
                }
            }
            */
        }
        if (--du[k[u]] == 0) q.push(k[u]);
    }
    cout << dp[0][m+1] << endl;
    return 0;
}
