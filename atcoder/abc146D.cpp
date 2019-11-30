#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, k;
int col[N];
vector<pair<int, int>> e[N];
map<int, int> vis[N];

void dfs(int u)
{
    int c = 1;
    for (auto p : e[u]) {
        if (col[p.second]) continue;
        while (vis[u].count(c)) ++c;
        col[p.second] = c;
        vis[u].insert({c, 1});
        vis[p.first].insert({c, 1});
        k = max(k, c);
        dfs(p.first);
    }
}

int main()
{
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
    }
    dfs(1);
    cout << k << endl;
    for (int i = 1; i < n; ++i)
        cout << col[i] << endl;
    return 0;
}
