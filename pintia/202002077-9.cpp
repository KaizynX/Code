#include <bits/stdc++.h>

using namespace std;

const int N = 1e2+7;

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

int n, m, k;
int en[N][N];

int main()
{
    cin >> n >> m >> k;
    dsu.init(n);
    for (int i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        if (w == 1) {
            dsu.merge(u, v);
            continue;
        }
        en[u][v] = en[v][u] = 1;
    }
    for (int i = 1, u, v, f1, f2; i <= k; ++i) {
        cin >> u >> v;
        f1 = dsu[u] == dsu[v];
        f2 = en[u][v] || en[v][u];
        if (f1 && f2) cout << "OK but...\n";
        else if (f1) cout << "No problem\n";
        else if (f2) cout << "No way\n";
        else cout << "OK\n";
    }
    return 0;
}
