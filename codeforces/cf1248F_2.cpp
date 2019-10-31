#include <bits/stdc++.h>

using namespace std;

const int N = 1e6+7;

int t, n, m, _dfn, top, tot, flag;
int dfn[N], low[N], vis[N], sta[N], res[N];
vector<int> e[N];

inline void clear(vector<int> &vec)
{
    vector<int> tmp;
    swap(tmp, vec);
}

inline void init()
{
    _dfn = top = tot = flag = 0;
    for (int i = 1; i <= n; ++i) {
        clear(e[i]);
        dfn[i] = low[i] = vis[i] = res[i] = 0;
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
            if (flag) return;
            low[u] = min(low[u], low[v]);
        } else if (vis[v]) {
            low[u] = min(low[u], low[v]);
        }
    }
    if (dfn[u] == low[u]) {
        do {
            res[sta[top]] = 1;
            vis[sta[top]] = 0;
            ++tot;
        } while (sta[top--] != u);
        flag = 1;
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
        tarjan(1);

        if (tot == n) {
            puts("No");
        } else {
            puts("Yes");
            printf("%d %d\n", tot, n-tot);
            for (int i = 1; i <= n; ++i)
                if (res[i])
                    printf("%d ", i);
            putchar('\n');
            for (int i = 1; i <= n; ++i)
                if (!res[i])
                    printf("%d ", i);
            putchar('\n');
        }
    }
    return 0;
}
