#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e5+7;
const int M = 5e5+7;

int T, n, m, a, b;
int u[M], v[M];

struct DSU
{
    int fa[N], num[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i, num[i] = 1; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        if (num[fx] >= num[fy]) num[fx] += num[fy], fa[fy] = fx;
        else num[fy] += num[fx], fa[fx] = fy;
        return true;
    }
} dsu, coa, cob;

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &a, &b);
        for (int i = 1; i <= m; ++i)
            scanf("%d %d", u+i, v+i);
        dsu.init(n);
        coa.init(n);
        cob.init(n);
        for (int i = 1; i <= m; ++i) {
            if (u[i] == a || v[i] == a || u[i] == b || v[i] == b) continue;
            dsu.merge(u[i], v[i]);
        }
        for (int i = 1; i <= m; ++i) {
            if (u[i] == a || v[i] == a)
                coa.merge(dsu[u[i]], dsu[v[i]]);
            if (u[i] == b || v[i] == b)
                cob.merge(dsu[u[i]], dsu[v[i]]);
        }
        int cnta = 0, cntb = 0;
        for (int i = 1; i <= n; ++i) {
            if (dsu[i] != i || i == a || i == b) continue;
            if (coa[i] == coa[a] && cob[i] != cob[b]) cnta += dsu.num[i];
            if (coa[i] != coa[a] && cob[i] == cob[b]) cntb += dsu.num[i];
        }
        cout << 1ll*cnta*cntb << endl;
    }
    return 0;
}
