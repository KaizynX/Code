#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, m, s;
int w[N], vis[N];
long long res;
vector<int> e[N];
map<pair<int, int>, int> mp;

void dfs(int u, long long val)
{
    res = max(res, val);
    for (int v : e[u]) {
        if (mp[{min(u, v), max(u, v)}]) continue;
        mp[{min(u, v), max(u, v)}] = 1;
        ++vis[v];
        dfs(v, val+(vis[v]==1)*w[v]);
        --vis[v];
        mp[{min(u, v), max(u, v)}] = 0;
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i) {
        scanf("%d", w+i);
    }
    for (int i = 1, u, v; i <= m; ++i) {
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
        mp.insert({{min(u, v), max(u, v)}, 0});
    }
    scanf("%d", &s);

    vis[s] = 1;
    dfs(s, w[s]);
    cout << res << endl;
    return 0;
}
