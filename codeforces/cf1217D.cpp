#include <bits/stdc++.h>

using namespace std;

const int N = 5e3+7;

int n, m, k = 1;
int vis[N], col[N];
vector<int> edge[N];

inline void dfs(int cur, int dep)
{
    if (vis[cur]) {
        k = max(k, dep-vis[cur]);
        return;
    }
    vis[cur] = dep;
    for (int i : edge[cur]) {
        dfs(i, dep+1);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) {
            dfs(i, 1);
        }
    }
    cout << k << endl;
    return 0;
}
