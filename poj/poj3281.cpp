/*
 * @Author: Kaizyn
 * @Date: 2020-04-12 17:11:22
 * @LastEditTime: 2020-04-12 17:51:47
 */
#include <queue>
#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

// #define DEBUG

using namespace std;

const int N = 1e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
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

int cow, food, drink;
Dinic<int> dinic;
inline int fid(const int &x) { return 2*cow+1+x; }
inline int did(const int &x) { return 2*cow+1+food+x; }

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    // cow (2*i, 2*i+1)  i = [1, cow]
    // food [cow*2+1+1, cow*2+1+food]
    // drind [2c+f+2, 2c+f+d+1]
    while (cin >> cow >> food >> drink) {
        dinic.init(2*cow+food+drink+2);
        int s = 0, t = 1;
        for (int i = 1; i <= cow; ++i) dinic.add_edge(i*2, i*2+1, 1);
        for (int i = 1; i <= food; ++i) dinic.add_edge(s, fid(i), 1);
        for (int i = 1; i <= drink; ++i) dinic.add_edge(did(i), t, 1);
        for (int i = 1, n, m; i <= cow; ++i) {
            cin >> n >> m;
            for (int j = 1, f; j <= n; ++j) {
                cin >> f;
                dinic.add_edge(fid(f), i*2, 1);
            }
            for (int j = 1, d; j <= m; ++j) {
                cin >> d;
                dinic.add_edge(i*2+1, did(d), 1);
            }
        }
        cout << dinic.work(s, t) << endl;
    }
    return 0;
}