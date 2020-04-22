/*
 * @Author: Kaizyn
 * @Date: 2020-04-13 19:00:58
 * @LastEditTime: 2020-04-13 19:51:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 5e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <typename T>
struct ZKW_SPFA
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
    ZKW_SPFA() { e.reserve(N<<4); }
    void init(const int &_n) {
        n = _n;
        maxflow = mincost = 0;
        e.clear();
        memset(fir, -1, sizeof(int)*(n+3));
    }
    void add_edge(const int &u, const int &v, const T &w, const T &c) {
        e.emplace_back(v, fir[u], w, c); fir[u] = e.size()-1;
        e.emplace_back(u, fir[v], 0, -c); fir[v] = e.size()-1;
    }
    pair<T, T> work(const int &_s, const int &_t) {
        s = _s; t = _t;
        while (spfa()) {
            vis[t] = 1;
            while (vis[t]) {
                memset(vis, 0, sizeof(int)*(n+3));
                maxflow += dfs(s, INF);
            }
        }
        return {maxflow, mincost};
    }
  private:
    bool spfa() {
        memset(dis, 0x3f, sizeof(T)*(n+3));
        memset(vis, 0, sizeof(int)*(n+3));
        deque<int> q;
        q.push_back(t);
        dis[t] = 0;
        vis[t] = 1;
        while (q.size()) {
            int u = q.front(); q.pop_front();
            for (int i = fir[u], v; ~i; i = e[i].nex) {
                v = e[i].v;
                if (!e[i^1].w || dis[v] <= dis[u]+e[i^1].c) continue;
                dis[v] = dis[u]+e[i^1].c;
                if (vis[v]) continue;
                vis[v] = 1;
                if (q.size() && dis[v] < dis[q.front()]) q.push_front(v);
                else q.push_back(v);
            }
            vis[u] = 0;
        }
        return dis[s] < INF;
    }
    T dfs(const int &u, const T &flow) {
        vis[u] = 1;
        if (u == t || flow <= 0) return flow;
        T res, used = 0;
        for (int i = fir[u], v; ~i; i = e[i].nex) {
            v = e[i].v;
            if (vis[v] || !e[i].w || dis[u] != dis[v]+e[i].c) continue;
            res = dfs(v, min(e[i].w, flow-used));
            if (!res) continue;
            mincost += res*e[i].c;
            e[i].w -= res;
            e[i^1].w += res;
            used += res;
            if (used == flow) break;
        }
        return used;
    }
};

ZKW_SPFA<int> zkw;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    zkw.init(n);
    for (int i = 1, u, v, w, f; i <= m; ++i) {
        cin >> u >> v >> w >> f;
        zkw.add_edge(u, v, w, f);
    }
    pair<int, int> res = zkw.work(s, t);
    cout << res.first << " " << res.second << endl;
    return 0;
}