#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;
const int M = 1e5+7;

int n, m, _dfn, _col, top, head, tail, ans;
int w[N], w_col[N], dfn[N], low[N], sta[N], col[N], vis[N], du[N], que[N], dp[N];
vector<int> e[N], e_col[N];

void tarjan(int u)
{
    dfn[u] = low[u] = ++_dfn;
    vis[u] = 1;
    sta[++top] = u;
    for (int v : e[u]) {
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if (dfn[u] == low[u]) {
        w_col[++_col] = 0;
        do {
            col[sta[top]] = _col;
            vis[sta[top]] = 0;
            w_col[_col] += w[sta[top]];
        } while (sta[top--] != u);
    }
}

inline void suodian()
{
    for (int i = 1; i <= n; ++i) {
        if (!dfn[i]) tarjan(i);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j : e[i]) {
            if (col[i] == col[j]) continue;
            e_col[col[i]].push_back(col[j]);
        }
    }
}

inline void DAGdp()
{
    for (int i = 1; i <= _col; ++i) {
        for (int j : e_col[i]) {
            ++du[j];
        }
    }
    for (int i = 1; i <= _col; ++i) {
        if (du[i]) continue;
        que[++tail] = i;
        dp[i] = w_col[i];
        ans = max(ans, dp[i]);
    }
    while (head < tail) {
        int u = que[++head];
        for (int v : e_col[u]) {
            if (--du[v] == 0) {
                que[++tail] = v;
                dp[v] = max(dp[v], dp[u]+w_col[v]);
                ans = max(ans, dp[v]);
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[u].push_back(v);
    }
    suodian();
    DAGdp();
    cout << ans << endl;
    return 0;
}
