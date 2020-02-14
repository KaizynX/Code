#include <bits/stdc++.h>

using namespace std;

const int N = 2e3+7;
const int M = 5e5+7;

int T, n, m;

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
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d", &n, &m);
        dsu.init(n);
        for (int i = 1, u, v; i <= m; ++i) {
            scanf("%d %d", &u, &v);
            dsu.merge(u, v);
        }
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (dsu[i] != i) ++res;
        }
        printf("%d\n", m-res);
    }
    return 0;
}
