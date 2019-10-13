#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;
const int M = 2e3+7;

int n, m, k, tot;
int vis[N], dfn[N], st[N];
vector<int> e[N];

void dfs(int u, int flag)
{
    if (dfn[u]) {
        return;
    }
    vis[u] = 1;
    st[++tot] = u;
    dfn[u] = tot;
    for (int v : e[u]) {
        if (vis[v]) {
            if (dfn[v]) {
                int num = tot+1-dfn[v];
                if (!flag) k = min(k, num);
                else if (flag == 1 && num == k) {
                    for (int i = 0; i < k; ++i)
                        cout << st[tot-i] << endl;
                    exit(0);
                }
            }
        } else {
            dfs(v, flag);
        }
    }
    --tot;
    dfn[u] = 0;
}

int main()
{
    cin >> n >> m;
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
    }
    k = n+1;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i, 0);
    }
    if (k == n+1) {
        cout << -1 << endl;
        return 0;
    }
    cout << k << endl;
    for (int i = 1; i <= n; ++i) vis[i] = 0;
    for (int i = 1; i <= n; ++i) {
        if (!vis[i]) dfs(i, 1);
    }
    return 0;
}
