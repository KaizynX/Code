#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;

int n, m, k, q;
int col[N], vis[N];
vector<int> e[N];

inline bool bfs(int s)
{
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    while (q.size()) {
        int u = q.front();
        q.pop();
        for (int v : e[u]) {
            if (vis[v]) continue;
            if (col[u] == col[v]) return false;
            q.push(v);
            vis[v] = 1;
        }
    }
    return true;
}

inline bool check()
{
    static vector<int> tmp;
    vector<int>(col+1, col+n+1).swap(tmp);
    sort(tmp.begin(), tmp.end());
    if (unique(tmp.begin(), tmp.end())-tmp.begin() != k) return false;
    memset(vis, 0, sizeof vis);
    for (int i = 1; i <= n; ++i) {
        if (vis[i]) continue;
        if (!bfs(i)) return false;
    }
    return true;
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    cin >> q;
    while (q--) {
        for (int i = 1; i <= n; ++i) cin >> col[i];
        cout << (check() ? "Yes" : "No") << endl;
    }
    return 0;
}
