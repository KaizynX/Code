#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int t, n, m, _dfn, _col, top, res_col;
int dfn[N], low[N], col[N], vis[N], sta[N], du[N];
vector<int> e[N], e_col[N];

inline void clear(vector<int> &vec)
{
    vector<int> tmp;
    swap(tmp, vec);
}

inline void init()
{
    _dfn = _col = top = res_col = 0;
    for (int i = 1; i <= n; ++i) {
        // e[i].clear();
        // e_col[i].clear();
        clear(e[i]);
        clear(e_col[i]);
        dfn[i] = low[i] = col[i] = du[i] = 0;
    }
}

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
        ++_col;
        do {
            col[sta[top]] = _col;
            vis[sta[top]] = 0;
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

inline void tuopu()
{
    for (int i = 1; i <= _col; ++i) {
        for (int j : e_col[i])
            ++du[j];
    }
    for (int i = 1; i <= _col; ++i) {
        if (du[i]) continue;
        res_col = i;
        break;
    }
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d", &n, &m);
        init();
        for (int i = 1, a, b; i <= m; ++i) {
            scanf("%d %d", &a, &b);
            if (a == b) continue;
            e[a].push_back(b);
        }
        suodian();
        tuopu();
        int tot = 0;
        for (int i = 1; i <= n; ++i)
            if (col[i] == res_col)
                ++tot;
        if (tot == n) {
            puts("No");
        } else {
            puts("Yes");
            printf("%d %d\n", n-tot, tot);
            for (int i = 1; i <= n; ++i)
                if (col[i] != res_col)
                    printf("%d ", i);
            putchar('\n');
            for (int i = 1; i <= n; ++i)
                if (col[i] == res_col)
                    printf("%d ", i);
            putchar('\n');
        }
    }
    return 0;
}
