#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, m;
int dp[N];
vector<int> pre[N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1, a, b; i <= m; ++i) {
        cin >> a >> b;
        pre[b].emplace_back(a);
    }
    int last = n+1;
    for (int i = n; i; --i) {
        if (pre[i].empty()) continue;
        for (int j = i+1; j < last; ++j)
            pre[j].emplace_back(j);
        for (int j : pre[i])
            last = min(last, j);
    }
    for (int i = 1; i < last; ++i)
        pre[i].emplace_back(i);
    for (int i = 1; i <= n; ++i) {
        if (pre[i].empty()) {
            dp[i] = dp[i-1];
            continue;
        }
        for (int j : pre[i])
            dp[i] = max(dp[i], dp[j-1]+1);
        if (dp[i] < dp[i-1]) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << dp[n] << endl;
    return 0;
}
