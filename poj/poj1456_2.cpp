#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4+7;

struct Node
{
    int p, d;
    friend bool operator < (const Node &x, const Node &y) { return x.p > y.p; }
} a[N];

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
    int n;
    while(scanf("%d", &n) != EOF) {
        dsu.init(10000);
        for (int i = 1; i <= n; ++i)
            scanf("%d %d", &a[i].p, &a[i].d);
        sort(a+1, a+n+1);
        int res = 0;
        for (int i = 1; i <= n; ++i) {
            if (!dsu[a[i].d]) continue;
            res += a[i].p;
            dsu.merge(dsu[a[i].d], dsu[a[i].d]-1);
        }
        printf("%d\n", res);
    }
	return 0;
}
