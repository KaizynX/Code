#include <bits/stdc++.h>

using namespace std;

const int N = 1e3+7;

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

int n, m, q;

int main()
{
    cin >> n >> m >> q;
    dsu.init(n);
    for (int i = 1, a, b; i <= m; ++i) {
        cin >> a >> b;
        dsu.merge(a, b);
    }
    for (int i = 1, a, b; i <= q; ++i) {
        cin >> a >> b;
        cout << (dsu[a] == dsu[b] ? "Y" : "N") << endl;
    }
    return 0;
}
