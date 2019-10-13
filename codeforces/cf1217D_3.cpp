#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;

int n, m, k = 1;
int vis[N], col[N];
vector<pair<int, int>> e[N];

void dfs(int cur)
{
    vis[cur] = 1;
    for (auto p : e[cur]) {
        int v = p.first, id = p.second;
        if (vis[v] == 0) {
            dfs(v);
            col[id] = 1;
        } else if (vis[v] == 2) {
            col[id] = 1;
        } else {
            col[id] = 2;
            k = 2;
        }
    }
    vis[cur] = 2;
}

int main()
{
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[u].push_back({v, i});
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i);
    }
    cout << k << endl;
    for (int i = 1; i <= m; ++i) {
        cout << col[i] << " \n"[i==m];
    }
    return 0;
}
