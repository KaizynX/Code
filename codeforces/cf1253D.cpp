#include <bits/stdc++.h>

using namespace std;

const int N = 2e5+7;

int n, m;

struct DSU
{
    int fa[N], l[N], r[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = l[i] = r[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        fa[fx] = fy;
        l[fy] = min(l[fy], l[fx]);
        r[fy] = max(r[fy], r[fx]);
        return true;
    }
} dsu;

struct Node
{
    int l, r;
    Node(){}
    Node(int _l, int _r) : l(_l), r(_r) {}
    friend bool operator < (const Node &x, const Node &y) {
        return x.l < y.l;
    }
};

vector<Node> e;

int main()
{
    cin >> n >> m;
    dsu.init(n);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        dsu.merge(u, v);
    }
    for (int i = 1; i <= n; ++i) {
        if (dsu[i] == i)
            e.push_back(Node(dsu.l[i], dsu.r[i]));
    }
    sort(e.begin(), e.end());
    int res = 0, last = 0;
    for (Node p : e) {
        if (p.l < last) ++res;
        last = max(last, p.r);
    }
    cout << res << endl;
    return 0;
}

