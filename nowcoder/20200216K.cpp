#include <bits/stdc++.h>

using namespace std;

const int N = 20;

int T, n, m;
int col[N], vis[N], dfn[N];
vector<int> e[N];

bool check(int u, int fa)
{
    vis[u] = 1;
    if (dfn[u]) return (dfn[fa]-dfn[u])&1;
    dfn[u] = dfn[fa]+1;
    for (int v : e[u]) if (v != fa && col[v]) {
        if (!check(v, u)) return false;
    }
    dfn[u] = 0;
    return true;
}

int main()
{
    cin >> T;
    for (int t = 1; t <= T; ++t) {
        cin >> n >> m;
        for (int i = 1; i <= n; ++i)
            vector<int>().swap(e[i]);
        for (int i = 1, u, v; i <= m; ++i) {
            cin >> u >> v;
            e[u].emplace_back(v);
            e[v].emplace_back(u);
        }
        int res = 0;
        for (int i = 0, cnt; i < (1<<n); ++i) {
            cnt = 0;
            for (int j = 0; j < n; ++j) {
                col[j+1] = (i>>j)&1;
                vis[j+1] = 0;
                cnt += col[j+1];
            }
            int flag = 1;
            for (int j = 1; j <= n; ++j)
                if (col[j] && !vis[j] && !check(j, 0)) {
                    flag = 0;
                    break;
                }
            if (flag) res = max(res, cnt);
        }
        cout << "Case #" << t << ": " << res << endl;
    }
    return 0;
}
