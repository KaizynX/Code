/*
 * @Author: Kaizyn
 * @Date: 2020-03-22 19:13:31
 * @LastEditTime: 2020-03-22 19:34:21
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

template <typename T>
struct Dinic
{
    struct Edge
    {
        int v, nex;
        T w, c; // edge wight and cost
        Edge(const int &_v, const int &_nex, const T &_w, const T &_c) \
        : v(_v), nex(_nex), w(_w), c(_c) {}
    };
    vector<Edge> e;
    int n, s, t;
    int fir[N], vis[N];
    T maxflow, mincost;
    T dis[N];
    void init(const int &_n) {
        n = _n;
        e.clear();
        e.reserve(N<<4);
        maxflow = mincost = 0;
        memset(vis, 0, sizeof(int)*(n+3));
        memset(fir, -1, sizeof(int)*(n+3));
    }
    void add_edge(const int &u, const int &v, const T &w, const T &c) {
        e.emplace_back(v, fir[u], w, c); fir[u] = e.size()-1;
        e.emplace_back(u, fir[v], 0, -c); fir[v] = e.size()-1;
    }
    pair<T, T> work(const int &_s, const int &_t) {
        s = _s; t = _t;
        T flow;
        while (spfa())
            while ((flow = dfs(s, INF)))
                maxflow += flow;
        return {maxflow, mincost};
    }
    bool spfa() {
        queue<int> q;
        memset(dis, 0x3f, sizeof(int)*(n+3));
        q.push(s);
        dis[s] = 0;
        vis[s] = 1;
        while (q.size()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for (int i = fir[u], v; i != -1; i = e[i].nex) {
                v = e[i].v;
                if (!e[i].w || dis[v] <= dis[u]+e[i].c) continue;
                dis[v] = dis[u]+e[i].c;
                if (vis[v]) continue;
                q.push(v);
                vis[v] = 1;
            }
        }
        return dis[t] != INF;
    }
    T dfs(const int &u, const T &flow) {
        if (!flow || u == t) return flow;
        T res = 0 , now;
        vis[u] = 1;
        for (int i = fir[u], v; i != -1 && res < flow; i = e[i].nex) {
            v = e[i].v;
            if (vis[v] || !e[i].w || dis[v] != dis[u]+e[i].c) continue;
            now = dfs(v, min(flow-res, e[i].w));
            if (!now) continue;
            mincost += now*e[i].c;
            e[i].w -= now;
            e[i^1].w += now;
            res += now;
        }
        vis[u] = 0;
        return res;
    }
};

Dinic<int> mcmf;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    mcmf.init(n);
    for (int i = 1, u, v, w, f; i <= m; ++i) {
        cin >> u >> v >> w >> f;
        mcmf.add_edge(u, v, w, f);
    }
    pair<int, int> res = mcmf.work(s, t);
    cout << res.first << " " << res.second << endl;
    return 0;
}