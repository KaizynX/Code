#include <bits/stdc++.h>

using namespace std;

const int N = 5e2+7;
const int M = 1e3+7;

struct Node
{
    int u, v, w;
    friend bool operator < (const Node &n1, const Node &n2) {
        return n1.w < n2.w;
    }
    friend istream& operator >> (istream &is, Node &node) {
        return is >> node.u >> node.v >> node.w;
    }
} e[M];

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

int n, m;

int main()
{
    cin >> n >> m;
    dsu.init(n);
    for (int i = 1; i <= m; ++i) {
        cin >> e[i];
    }
    sort(e+1, e+m+1);
    int res = 0;
    for (int i = 1, tot = 0; i <= m; ++i) {
        if (dsu.merge(e[i].u, e[i].v)) {
            res += e[i].w;
            if (++tot == n-1) break;
        }
    }
    cout << res << endl;
    return 0;
}
