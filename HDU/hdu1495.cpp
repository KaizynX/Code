#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;
const int INF = 1e9;

int res, a[3], vis[N][N];

void dfs(int s, int n, int m, int t)
{
    if (vis[n][m]) return;
    vis[n][m] = 1;
    if (s == a[0]/2 || n == a[0]/2 || m == a[0]/2) {
        res = min(res, t);
        return;
    }
    // s -> n
    int d = min(s, a[1]-n);
    dfs(s-d, n+d, m, t+1);
    // s -> m
    d = min(s, a[2]-m);
    dfs(s-d, n, m+d, t+1);
    // n -> s
    dfs(s+n, 0, m, t+1);
    // m -> s
    dfs(s+m, n, 0, t+1);
    // n -> m
    d = min(n, a[2]-m);
    dfs(s, n-d, m+d, t+1);
    // m -> n
    d = min(a[1]-n, m);
    dfs(s, n+d, m-d, t+1);
}

int main()
{
    while (cin >> a[0] >> a[1] >> a[2] && a[0]|a[1]|a[2]) {
        if (a[0]&1) {
            cout << "NO" << endl;
            continue;
        }
        memset(vis, 0, sizeof vis);
        res = INF;
        dfs(a[0], 0, 0, 0);
        if (res == INF) cout << "NO" << endl;
        else cout << res << endl;
    }
    return 0;
}
