#include <bits/stdc++.h>

using namespace std;

const int N = 5e5+7;

int n, head, tail;
int l[N], r[N];
vector<int> e[N];

void dfs(int u, int fa) {
    l[u] = head++;
    for (int v : e[u]) {
        if (v == fa) continue;
        dfs(v, u);
    }
    r[u] = tail--;
}

int main()
{
    scanf("%d", &n);
    head = 1; tail = n*2;
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
    dfs(root, 0);
    for (int i = 1; i <= n; ++i) {
        printf("%d %d\n", l[i], r[i]);
    }
    return 0;
}
