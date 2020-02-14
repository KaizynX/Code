#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int n, m, k;
int u[N], v[N], vis[N];

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
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; ++i) {
        cin >> u[i] >> v[i];
    }
    cin >> k;
    for (int i = 1, np, p, flag; i <= k; ++i) {
        dsu.init(n);
        memset(vis, 0, sizeof vis);
        flag = 1;

        cin >> np;
        for (int j = 1; j <= np; ++j) {
            cin >> p;
            vis[p] = 1;
        }
        for (int j = 1; j <= m; ++j) {
            if (vis[u[j]] || vis[v[j]]) continue;
            dsu.merge(u[j], v[j]);
        }
        for (int j = 1; j <= n; ++j) {
            flag &= dsu[j] == j;
        }
        cout << (flag ? "YES" : "NO") << endl;
    }
    return 0;
}
