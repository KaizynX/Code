#include <bits/stdc++.h>

using namespace std;

const int N = 2e2+7;
const int INF = 0x3f3f3f3f;

int n;
int m[N][N], vis[N], dis[N][N];

bool check(int cur, int dep)
{
    if (vis[cur] > 0) return (dep-vis[cur])%2 == 0;
    vis[cur] = dep;
    for (int i = 1; i <= n; ++i) {
        if (cur == i || !m[cur][i]) continue;
        if (!check(i, dep+1)) return false;
    }
    vis[cur] = -1;
    return true;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            char c;
            cin >> c;
            m[i][j] = c-'0';
            dis[i][j] = m[i][j] ? 1 : INF;
            if (i == j) dis[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        if (!check(i, 1)) {
            cout << -1 << endl;
            return 0;
        }
    }
    
    for (int k = 1; k <= n; ++k) {
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= n; ++j) {
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            res = max(res, dis[i][j]);
        }
    }
    cout << res+1 << endl;
    return 0;
}
