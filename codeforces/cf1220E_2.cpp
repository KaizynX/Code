#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, m, s;
long long res, mx;
int w[N], vis[N], add[N];
vector<int> e[N];

pair<long long, int> dfs(int u, int last)
{
    if (vis[u]) return { 0, 1 };
    vis[u] = 1;
    long long mv = 0;
    int flag = 0;
    for (int v : e[u]) {
        if (v == last) continue;
        auto p = dfs(v, u);
        if (p.second) {
            flag = 1;
            if (!add[u]) {
                res += w[u];
                add[u] = 1;
            }
        } else {
            mv = max(mv, p.first);
            mx = max(mx, mv);
        }
    }
    // vis[u] = 0;
    return { mv+(flag ? 0 : w[u]), flag };
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
    }
    cin >> s;
    mx = max(mx, dfs(s, 0).first);
    cout << res+mx << endl;
    return 0;
}
