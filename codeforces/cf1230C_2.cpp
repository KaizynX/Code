#include <bits/stdc++.h>

using namespace std;

const int N = 10;
const int M = 50;

int n, m, res;
int p[N], vis[N][N], a[M], b[M];

inline void clear()
{
    for (int i = 1; i <= 6; ++i) {
        for (int j = 1; j <= 6; ++j) {
            vis[i][j] = 0;
        }
    }
}

void dfs(int cur)
{
    if (cur > n) {
        clear();
        int now = 0;
        for (int i = 1, pa, pb; i <= m; ++i) {
            pa = p[a[i]]; pb = p[b[i]];
            if (!vis[pa][pb]) ++now;
            vis[pa][pb] = vis[pb][pa] = 1;
            // if (!vis[p[a[i]]][p[b[i]]]) ++now;
            // vis[p[a[i]]][p[b[i]]] = vis[p[b[i]]][p[a[i]]] = 1;
        }
        res = max(res, now);
        return;
    }
    for (int i = 1; i <= 6; ++i) {
        p[cur] = i;
        dfs(cur+1);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> a[i] >> b[i];
    }
    dfs(1);
    cout << res << endl;
    return 0;
}
