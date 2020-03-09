#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e5+7;
const double err = 1e-9;
typedef pair<int, int> pii;

int n, q;
int d[N], f[N][20], lg2[N];
vector<int> e[N];

void build_tree(int u, int fa)
{
    d[u] = d[fa]+1;
    f[u][0] = fa;
    for (int i = 1; (1<<i) <= d[u]; ++i)
        f[u][i] = f[f[u][i-1]][i-1];
    for (int v : e[u]) if (v != fa)
        build_tree(v, u);
}

inline int lca(int x, int y)
{
    if (d[x] < d[y]) swap(x, y);
    while (d[x] > d[y])
        x = f[x][lg2[d[x]-d[y]]];
    if (x == y) return x;
    for (int i = lg2[d[x]]; i >= 0; --i)
        if(f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    return f[x][0];
}


inline int dis(int x, int y)
{
    int fa = lca(x, y);
    return d[x]-d[fa]+d[y]-d[fa];
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 2; i < N; ++i) lg2[i] = lg2[i>>1]+1;
    cin >> n;
    for (int i = 1, u, v; i < n; ++i) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    build_tree(1, 0);
    cin >> q;
    for (int i = 1, x, y, a, b, k; i <= q; ++i) {
        cin >> x >> y >> a >> b >> k;
        int dab = dis(a, b), dax = dis(a, x), dby = dis(b, y), day = dis(a, y), dbx = dis(b, x);
#ifdef DEBUG
        cout << dab << " " << dax << " " << dby << endl;
#endif
        if ((k >= dax+dby+1 && (dax+dby+1)%2 == k%2) ||
            (k >= day+dbx+1 && (day+dbx+1)%2 == k%2) ||
            (k >= dab && dab%2 == k%2)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
