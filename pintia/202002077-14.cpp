#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int n, m, k;
int dis[N];
vector<int> e[N];

void bfs(int s)
{
    memset(dis, 0, sizeof dis);
    queue<pair<int, int>> q;
    q.push({1, s});
    dis[s] = 1;
    while (q.size()) {
        auto u = q.front();
        q.pop();
        if (dis[u.second] < u.first) continue;
        for (int v : e[u.second]) {
            int tmp = u.first+1;
            if (dis[v] && dis[v] <= tmp) continue;
            dis[v] = tmp;
            q.push({tmp, v});
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    for (int i = 1, x; i <= k; ++i) {
        cin >> x;
        bfs(x);
        int res = 0;
        for (int i = 1; i <= n; ++i)
            if (dis[i] > dis[res])
                res = i;
        if (res == x) res = 0;
        cout << res << endl;
    }
    return 0;
}
