#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;

int n, m, k;
int a[N], vis[N], res[N];
vector<int> e[N];

struct DSU
{
    int fa[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        fa[fx] = fy; return true;
    }
} dsu;

int main()
{
    cin >> n >> m;
    dsu.init(n);
    for (int i = 1, u, v; i <= m; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    cin >> k;
    for (int i = 1; i <= k; ++i) cin >> a[i];
    for (int i = k, u, cnt; i; --i) {
        u = a[i];
        cnt = 0;
        for (int v : e[u]) {
            if (!vis[v]) continue;
            cnt += dsu.merge(v, u);
        }
        vis[u] = 1;
        res[i] = cnt > 1;
    }
    for (int i = 1; i <= k; ++i) {
        if (res[i]) cout << "Red Alert: ";
        cout << "City " << a[i] << " is lost";
        cout << (res[i] ? "!" : ".") << endl;
    }
    if (k == n) cout << "Game Over." << endl;
    return 0;
}
