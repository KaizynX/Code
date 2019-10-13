#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;

int n, m, k = 1;
int vis[N], col[N], mp[N][N], dfn[N];
vector<int> edge[N];

inline void dfs(int cur, int last)
{
    vis[cur] = 1;
    if (dfn[cur]) {
        k = max(k, 2);
        return;
    }
    dfn[cur] = 1;
    if (col[cur] == -1) col[cur] = last^1;
    for (int i : edge[cur]) {
        dfs(i, (col[i] == 0 ? 1 : 0));
    }
    dfn[cur] = 0;
}

int main()
{
    cin >> n >> m;
    memset(col, -1, sizeof(int)*(n+3));
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        mp[u][v] = 1;
        edge[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        for (int j : edge[i]) {
            if (mp[j][i]) {
                k = max(k, 2);
                if (col[i] == -1 && col[j] == -1) {
                    col[i] = 0;
                    col[j] = 1;
                } else if (col[i] == -1 && col[j] != -1) {
                    col[i] = (col[j] == 0 ? 1 : 0);
                } else if (col[i] != -1 && col[j] == -1) {
                    col[j] = (col[i] == 0 ? 1 : 0);
                } else if (col[i] == col[j]) {
                    col[i] = 2;
                    k = 3;
                }
            }
        }
    }
    cout << k << endl;
    memset(vis, 0, sizeof(int)*(n+3));
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i, 1);
    }
    for (int i = 1; i <= n; ++i) {
        cout << (k == 1 ? 1 : col[i]+1) << " ";
    }
    cout << endl;
    return 0;
}
