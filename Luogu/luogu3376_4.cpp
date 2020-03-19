/*
 * @Author: Kaizyn
 * @Date: 2020-03-19 21:05:03
 * @LastEditTime: 2020-03-19 21:08:22
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e4+7;
const int M = 1e5+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
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
    int fir[N], dep[N];
    T work(const int &s, const int &t) {
        T maxflow = 0;
        while (bfs(s, t)) {
            maxflow += dfs(s, t, INF);
        }
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
                q.push(v);
            }
        }
        return dep[t];
    }
    T dfs(const int &u, const int &t, const T &flow) {
        if (!flow || u == t) return flow;
        T rest = flow, now;
        for (int i = fir[u], v; i != -1; i = e[i].nex) {
            v = e[i].v;
            if (dep[v] != dep[u]+1 || !e[i].w) continue;
            now = dfs(v, t, min(rest, e[i].w));
            if (!now) continue;
            e[i].w -= now;
            e[i^1].w += now;
            rest -= now;
            if (!rest) break;
        }
        return flow-rest;
    }
};
Dinic<int> dinic;

int n, m, s, t;

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> s >> t;
    dinic.init(n);
    for (int i = 1, u, v, w; i <= m; ++i) {
        cin >> u >> v >> w;
        dinic.add_edge(u, v, w);
    }
    cout << dinic.work(s, t) << endl;
    return 0;
}