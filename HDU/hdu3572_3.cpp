/*
 * @Author: Kaizyn
 * @Date: 2020-03-19 20:48:36
 * @LastEditTime: 2020-03-19 20:57:40
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int M = 2e5+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

template <typename T>
struct ISAP
{
    struct EDGE
    {
        int v, nex;
        T w;
    } e[M<<1];
    int tot, n, s, t;
    T maxflow;
    int fir[N], gap[N], dep[N];
    T work(const int &_s, const int &_t) {
        s = _s; t = _t;
        maxflow = 0;
        bfs();
        while (dep[s] < n) dfs(s, INF);
        return maxflow;
    }
    void init(const int &sz) {
        n = sz;
        tot = 0;
        memset(fir, -1, sizeof(int)*(n+3));
    }
    void add_edge(const int &u, const int &v, const T &w) {
        e[tot] = {v, fir[u], w}; fir[u] = tot++;
        e[tot] = {u, fir[v], 0}; fir[v] = tot++;
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
ISAP<int> isap;

inline bool solve()
{
    int n, m;
    static int vis[N];
    scanf("%d %d", &n ,&m);
    int src = 0, dst = 500+n+1;
    memset(vis, 0, sizeof(int)*(500+n+3));
    isap.init(500+n+1);
    int sum = 0;
    for (int i = 1, p, s, e; i <= n; ++i) {
        scanf("%d %d %d", &p, &s, &e);
        isap.add_edge(src, 500+i, p);
        sum += p;
        for (int j = s; j <= e; ++j) {
            isap.add_edge(500+i, j, 1);
            vis[j] = 1;
        }
    }
    for (int i = 1; i <= 500; ++i) if (vis[i]) {
        isap.add_edge(i, dst, m);
    }
    return isap.work(0, dst) == sum;
}

int main()
{
    // ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int T = 1;
    scanf("%d", &T);
    for (int i = 1; i <= T; ++i) {
        printf("Case %d: %s\n\n", i, solve() ? "Yes" : "No");
        // cout << "Case " << i << ": " << (solve() ? "Yes" : "No") << "\n\n";
    }
    return 0;
}