/*
 * @Author: Kaizyn
 * @Date: 2020-04-16 20:16:59
 * @LastEditTime: 2020-04-17 13:48:10
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 3e4+7;
const int MOD = 998244353;
const long long INF = 1e18;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <typename T>
struct ISAP
{
    struct EDGE
    {
        int v, nex;
        T w;
        EDGE(const int &_v, const int &_nex, const T &_w) : v(_v), nex(_nex), w(_w) {}
    };
    vector<EDGE> e;
    int n, s, t;
    T maxflow;
    int fir[N], gap[N], dep[N];
    T work(const int &_s, const int &_t) {
        s = _s; t = _t;
        maxflow = 0;
        bfs();
        while (dep[s] < n) dfs(s, INF);
        return maxflow;
    }
    void init(const int &_n) {
        n = _n;
        e.clear();
        e.reserve(N<<2);
        memset(fir, -1, sizeof(int)*(n+3));
    }
    void add_edge(const int &u, const int &v, const T &w) {
        e.emplace_back(v, fir[u], w); fir[u] = e.size()-1;
        e.emplace_back(u, fir[v], 0); fir[v] = e.size()-1;
    }
    void bfs() {
        queue<int> q;
        memset(dep, -1, sizeof(int)*(n+3));
        memset(gap, 0, sizeof(int)*(n+3));
        dep[t] = 0;
        gap[0] = 1;
        q.push(t);
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = fir[u], v; i != -1; i = e[i].nex) {
                v = e[i].v;
                if (dep[v] != -1) continue;
                q.push(v);
                dep[v] = dep[u]+1;
                ++gap[dep[v]];
            }
        }
    }
    T dfs(const int &u, const T &flow) {
        if (u == t) {
            maxflow += flow;
            return flow;
        }
        T used = 0;
        for (int i = fir[u], v; i != -1; i = e[i].nex) {
            v = e[i].v;
            if (!e[i].w || dep[v]+1 != dep[u]) continue;
            T minf = dfs(v, min(e[i].w, flow-used));
            if (minf) {
                e[i].w -= minf;
                e[i^1].w += minf;
                used += minf;
            }
            if (used == flow) return used;
        }
        if (--gap[dep[u]] == 0) dep[s] = n+1;
        ++gap[++dep[u]];
        return used;
    }
};

const int LIM = 1e6;

struct F {
    int a, b, c, l, r;
    int calc(const int &x) const {
        return LIM-(a*x*x+b*x+c);
    }
};

int n, m;
int sum[55];
F f[55];
ISAP<long long> isap;

inline int id(const int &i, const int &j) { return sum[i-1]+j-f[i].l; }

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) {
        cin >> f[i].a >> f[i].b >> f[i].c;
    }
    for (int i = 1; i <= n; ++i) {
        cin >> f[i].l >> f[i].r;
        sum[i] = sum[i-1]+(f[i].r-f[i].l+2);
    }
    int s = sum[n], t = sum[n]+1;
    isap.init(t+1); // start from 0
    for(int i = 1; i <= n; ++i) {
        isap.add_edge(s, id(i, f[i].l), INF);
        for (int j = f[i].l; j <= f[i].r; ++j) {
            isap.add_edge(id(i, j), id(i, j+1), f[i].calc(j));
        }
        isap.add_edge(id(i, f[i].r+1), t, INF);
    }
    // xu <= xv+d
    for (int i = 1, u, v, d; i <= m; ++i) {
        cin >> u >> v >> d;
        for (int j = f[u].l; j <= f[u].r; ++j) {
            if (j-d >= f[v].l && j-d <= f[v].r+1) {
                isap.add_edge(id(u, j), id(v, j-d), INF);
            }
        }
    }
    cout << (LIM*n-isap.work(s, t)) << endl;
    return 0;
}