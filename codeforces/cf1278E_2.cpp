#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

int n, t;
int l[N], r[N];
vector<int> e[N];

void dfs(int u, int fa) {
    for (auto v = e[u].begin(); v != e[u].end(); ++v) {
        if (*v == fa) continue;
        l[*v] = ++t;
    }
    r[u] = ++t;
    for (auto v = e[u].rbegin(); v != e[u].rend(); ++v) {
        if (*v == fa) continue;
        dfs(*v, u);
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, x, y; i < n; ++i) {
        scanf("%d %d", &x, &y);
        e[x].emplace_back(y);
        e[y].emplace_back(x);
    }
    int root = 1;
    for (int i = 1; i <= n; ++i) {
        if (e[i].size() == 1) {
            root = i;
            break;
        }
    }
    l[root] = ++t;
    dfs(root, 0);
    for (int i = 1; i <= n; ++i) {
        printf("%d %d\n", l[i], r[i]);
    }
    return 0;
}

