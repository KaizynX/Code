#include <bits/stdc++.h>

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
} dsu;

inline long long calc(int x, int y)
{
    long long res = 0;
    dsu.init(n);
    for (int i = 1; i <= m; ++i) {
        if (u[i] == x || u[i] == y || v[i] == x || v[i] == y) continue;
        dsu.merge(u[i], v[i]);
    }
    for (int i = 1; i <= n; ++i) {
        if (i == x || i == y || dsu[i] != i) continue;
        res += 1ll*dsu.num[i]*(dsu.num[i]-1)/2;
    }
    return res;
}

int main()
{
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d", &n, &m, &a, &b);
        for (int i = 1; i <= m; ++i)
            scanf("%d %d", u+i, v+i);
        // cout << 1ll*n*(n-1)/2-(calc(a, a)+calc(b, b)-calc(a, b)) << endl;
        cout << calc(a, b) << endl;
    }
    return 0;
}
