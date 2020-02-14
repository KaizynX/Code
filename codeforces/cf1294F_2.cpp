#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n;
int vis[N], dis[N];
vector<int> e[N], choose;
int q[N], head, tail;

void dfs(int u, int fa, int d)
{
    dis[u] = d;
    for (int v : e[u]) {
        if (v == fa) continue;
        dfs(v, u, d+1);
    }
}

bool dfs2(int u, int fa)
{
    vis[u] = 1;
    if (u == choose.front()) return true;
    for (int v : e[u]) {
        if (v == fa) continue;
        if (dfs2(v, u)) return true;
    }
    vis[u] = 0;
    return false;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; ++i) {
        scanf("%d%d", &u, &v);
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    dfs(1, 0, 0);
    int maxi = 1;
    for (int i = 1; i <= n; ++i)
        if (dis[i] > dis[maxi])
            maxi = i;
    choose.emplace_back(maxi);
    dfs(maxi, 0, 0);
    for (int i = 1; i <= n; ++i)
        if (dis[i] > dis[maxi])
            maxi = i;
    int res = dis[maxi];
    choose.emplace_back(maxi);

    dfs2(maxi, 0);
    /*
    typedef pair<int, int> pii;
    queue<pii> q;
    for (int i = 1; i <= n; ++i) {
        dis[i] = 0;
        if (vis[i]) q.push({i, 0});
        if (i != choose[0] && i != choose[1]) maxi = i;
    }
    while (q.size()) {
        pii u = q.front();
        q.pop();
        if (u.second < dis[u.first]) continue;
        if (dis[u.first] > dis[maxi]) maxi = u.first;
        for (int v : e[u.first]) {
            if (vis[v] || u.second+1 <= dis[v]) continue;
            dis[v] = u.second+1;
            q.push({v, dis[v]});
        }
    }
    */
    for (int i = 1; i <= n; ++i) {
        dis[i] = 0;
        if (vis[i]) q[++tail] = i;
        if (i != choose[0] && i != choose[1]) maxi = i;
    }
    while (head < tail) {
        int u = q[++head];
        if (dis[u] > dis[maxi]) maxi = u;
        for (int v : e[u]) {
            if (vis[v]) continue;
            dis[v] = dis[u]+1;
            q[++tail] = v;
        }
    }
    res += dis[maxi];
    choose.emplace_back(maxi);
    printf("%d\n", res);
    for (int i : choose) printf("%d ", i);
    return 0;
}
