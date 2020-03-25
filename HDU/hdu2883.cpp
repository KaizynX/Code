/*
 * @Author: Kaizyn
 * @Date: 2020-03-22 15:08:06
 * @LastEditTime: 2020-03-22 16:32:48
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
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
        e.reserve(N<<4);
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

struct Node
{
    int s, n, e, t;
    friend istream& operator >> (istream &is, Node &nd) {
        return is >> nd.s >> nd.n >> nd.e >> nd.t;
    }
};

int n, m;
Node a[N];
vector<int> d;
ISAP<int> isap;

inline bool solve()
{
    d.clear();
    for (int i = 1; i <= n; ++i) {
        d.emplace_back(a[i].s);
        d.emplace_back(a[i].e);
    }
    sort(d.begin(), d.end());
    d.erase(unique(d.begin(), d.end()), d.end());
    int tm = d.size()-1, s = tm+n+1, t = tm+n+2;
    // time zone[i] =  [d[i-1], d[i]], i [1, tm]
    // custom [tm+1, tm+n]
    isap.init(tm+n+2);
    int sum = 0;
    for (int i = 1; i <= tm; ++i)
        isap.add_edge(s, i, (d[i]-d[i-1])*m);
    for (int i = 1; i <= n; ++i) {
        a[i].s = lower_bound(d.begin(), d.end(), a[i].s)-d.begin();
        a[i].e = lower_bound(d.begin(), d.end(), a[i].e)-d.begin();
        for (int j = a[i].s+1; j <= a[i].e; ++j)
            isap.add_edge(j, tm+i, INF);
            // isap.add_edge(j, tm+i, (d[j]-d[j-1])*min(m, a[i].n));
        isap.add_edge(tm+i, t, a[i].n*a[i].t);
        sum += a[i].n*a[i].t;
    }
    return isap.work(s, t) == sum;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    d.reserve(N);
    while (cin >> n >> m) {
        for (int i = 1; i <= n; ++i) cin >> a[i];
        cout << (solve() ? "Yes" : "No") << endl;
    }
    return 0;
}