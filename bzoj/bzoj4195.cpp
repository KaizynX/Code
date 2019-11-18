#include <bits/stdc++.h>

using namespace std;

const int N = 1e5+7;

int t, n, m;
int d[N<<1];

struct Node
{
    int a, b, e;
    friend bool operator < (const Node &x, const Node &y) { return x.e > y.e; }
} c[N];

struct DSU
{
    int fa[N<<1], num[N<<1];
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

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d %d %d", &c[i].a, &c[i].b, &c[i].e);
            d[i*2] = c[i].a;
            d[i*2+1] = c[i].b;
        }
        sort(d, d+n*2);
        m = unique(d, d+n*2)-d;
        for (int i = 0; i < n; ++i) {
            c[i].a = lower_bound(d, d+m, c[i].a)-d;
            c[i].b = lower_bound(d, d+m, c[i].b)-d;
        }
        sort(c, c+n);
        dsu.init(n*2);
        int flag = 1;
        for (int i = 0; i < n; ++i) {
            if (c[i].e) dsu.merge(c[i].a, c[i].b);
            else if (dsu[c[i].a] == dsu[c[i].b]) { flag = 0; break; }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}
