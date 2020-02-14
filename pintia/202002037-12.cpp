#include <bits/stdc++.h>

using namespace std;

const int N = 1e4+7;

int n, m, q;

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
    cin >> m;
    dsu.init(10000);
    for (int i = 1, k, a, b; i <= m; ++i) {
        cin >> k;
        if (!k) continue;
        cin >> a;
        n = max(a, n);
        for (int j = 1; j < k; ++j) {
            cin >> b;
            n = max(b, n);
            dsu.merge(a, b);
        }
    }
    int cnt = 0;
    for (int i = 1; i <= n; ++i)
        if (dsu[i] == i) ++cnt;
    cout << n << " " << cnt << endl;

    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        cout << (dsu[x] == dsu[y] ? "Y" : "N") << endl;
    }
    return 0;
}
