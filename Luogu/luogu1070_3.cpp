#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e3+7;

int n, m, p;
int c[N], a[N][N], dp[N];
int head[N], tail[N], add[N], pos[N];
pair<int, int> q[N][N];

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> p;
    for (int i = 0; i < n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        cin >> c[i];

    memset(dp, 0xef, sizeof dp);
    dp[0] = 0;
    for (int i = 0; i < n; ++i) pos[i] = i;
    for (int t = 1; t <= m; ++t) {
        for (int i = 0; i < n; ++i) {
            (++pos[i]) %= n;
            int now = dp[t-1]-c[pos[i]]-add[i];
            add[i] += a[pos[i]][t];
            while (head[i] < tail[i] && q[i][head[i]+1].second+p < t) ++head[i];
            while (head[i] < tail[i] && q[i][tail[i]].first <= now) --tail[i];
            q[i][++tail[i]] = {now, t-1};
            dp[t] = max(dp[t], q[i][head[i]+1].first+add[i]);
        }
    }
    cout << dp[m] << endl;
    return 0;
}
