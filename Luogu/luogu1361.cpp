/*
 * @Author: Kaizyn
 * @Date: 2020-04-13 16:18:03
 * @LastEditTime: 2020-04-13 16:25:31
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 3e3+7;
const int MOD = 998244353;
const int INF = 2e9+7;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <typename T>
struct Dinic
{
    struct EDGE
    {
        int v, nex;
        T w;
        EDGE(const int &_v, const int &_nex, const T &_w) : v(_v), nex(_nex), w(_w) {}
    };
    vector<EDGE> e;
    int n, s, t;
    int fir[N], dep[N], cur[N];
    Dinic() { e.reserve(N<<2); }
    T work(const int &_s, const int &_t) {
        s = _s; t = _t;
        T maxflow = 0, flow;
        while (bfs())
            while ((flow = dfs(s, INF)))
                maxflow += flow;
        return maxflow;
    }
    void init(const int &_n) {
        n = _n;
        e.clear();
        memset(fir, -1, sizeof(int)*(n+3));
    }
    void add_edge(const int &u, const int &v, const T &w) {
        e.emplace_back(v, fir[u], w); fir[u] = e.size()-1;
        e.emplace_back(u, fir[v], 0); fir[v] = e.size()-1;
    }
    bool bfs() {
        queue<int> q;
        memset(dep, 0, sizeof(int)*(n+3));
        q.push(s);
        dep[s] = 1;
        for (int i = 0; i <= n; ++i) cur[i] = fir[i];
        while (q.size()) {
            int u = q.front();
            q.pop();
            for (int i = fir[u], v; i != -1; i = e[i].nex) {
                v = e[i].v;
                if (dep[v] || !e[i].w) continue;
                dep[v] = dep[u]+1;
                if (v == t) return true;
                q.push(v);
            }
        }
        return false;
    }
    T dfs(const int &u, const T &flow) {
        if (!flow || u == t) return flow;
        T rest = flow, now;
        for (int &i = cur[u], v; i != -1; i = e[i].nex) {
            v = e[i].v;
            if (dep[v] != dep[u]+1 || !e[i].w) continue;
            now = dfs(v, min(rest, e[i].w));
            if (!now) {
                dep[v] = 0;
            } else {
                e[i].w -= now;
                e[i^1].w += now;
                rest -= now;
                if (rest == flow) break;
            }
        }
        return flow-rest;
    }
};

int n, m;
int a[N], b[N];
Dinic<int> dinic;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    cin >> m;
    // plant [1, n] combination n+i*2-1, n+i*2
    dinic.init(n+m*2+2);
    int s = n+m*2+1, t = n+m*2+2, sum = 0;
    for (int i = 1, k, c1, c2; i <= m; ++i) {
        cin >> k >> c1 >> c2;
        dinic.add_edge(s, n+i*2-1, c1);
        dinic.add_edge(n+i*2, t, c2);
        sum += c1+c2;
        for (int j = 1, x; j <= k; ++j) {
            cin >> x;
            dinic.add_edge(n+i*2-1, x, INF);
            dinic.add_edge(x, n+i*2, INF);
        }
    }
    for (int i = 1; i <= n; ++i) {
        sum += a[i]+b[i];
        dinic.add_edge(s, i, a[i]);
        dinic.add_edge(i, t, b[i]);
    }
    cout << sum-dinic.work(s, t) << endl;
    return 0;
}