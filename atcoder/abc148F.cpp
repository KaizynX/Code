#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, s, t;
vector<int> e[N];
int ds[N], dt[N];

inline void dfs(int x, int dis[]) {
    dis[x] = 0;
    queue<int> q;
    q.push(x);
    while (q.size()) {
        int cur = q.front();
        q.pop();
        for (int nex : e[cur]) {
            if (dis[nex] != -1 || nex == t) continue;
            dis[nex] = dis[cur]+1;
            q.push(nex);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s >> t;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    memset(ds, -1, sizeof ds);
    memset(dt, -1, sizeof dt);
    dfs(s, ds);
    dfs(t, dt);
    int res = 0;
    for (int i = 1; i <= n; ++i) {
        if (ds[i] == -1 || dt[i] == -1 || ds[i] >= dt[i]) continue;
        res = max(res, ds[i]+dt[i]-ds[i]-1);
    }
    cout << res << endl;
    return 0;
}

