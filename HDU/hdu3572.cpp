#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e3+7;
const int M = 5e3+7;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9+7;
const double eps = 1e-11;
typedef pair<int, int> pii;

template <typename T>
struct Dinic
{
    struct EDGE
    {
        int v, nex;
        T w;
    } e[M<<1];
    int tot, n;
    int fir[N], vis[N], dep[N];
    T work(const int &s, const int &t) {
        T maxflow = 0, flow;
        while (bfs(s, t))
            while (flow = dfs(s, t, INF))
                maxflow += flow;
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
    bool bfs(const int &s, const int &t) {
        queue<int> q;
        memset(dep, 0, sizeof(int)*(n+3));
        q.push(s);
        dep[s] = 1;
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
    T dfs(const int &u, const int &t, const T &flow) {
        if (!flow || u == t) return flow;
        T rest = flow, now;
        for (int i = fir[u], v; i != -1; i = e[i].nex) {
            v = e[i].v;
            if (dep[v] != dep[u]+1 || !e[i].w) continue;
            now = dfs(v, t, min(rest, e[i].w));
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
Dinic<int> dinic;

inline bool solve()
{
    int n, m;
    // cin >> n >> m;
    scanf("%d %d", &n ,&m);
    dinic.init(500+n+1);
    for (int i = 1; i <= 500; ++i) {
        dinic.add_edge(0, i, m);
    }
    int sum = 0;
    for (int i = 1, p, s, e; i <= n; ++i) {
        // cin >> p >> s >> e;
        scanf("%d %d %d", &p, &s, &e);
        sum += p;
        dinic.add_edge(500+i, 500+n+1, p);
        for (int j = s; j <= e; ++j) {
            dinic.add_edge(j, 500+i, 1);
        }
    }
    return dinic.work(0, 500+n+1) == sum;
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