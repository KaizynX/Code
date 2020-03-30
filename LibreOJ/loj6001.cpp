/*
 * @Author: Kaizyn
 * @Date: 2020-03-26 12:54:33
 * @LastEditTime: 2020-03-26 14:00:30
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e2+7;
const int M = 1e4+7;
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
        T maxflow = 0, flow;
        while (bfs(s, t))
            while ((flow = dfs(s, t, INF)))
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
string str;
stringstream ss;
Dinic<int> dinic;

inline void solve()
{
    getline(cin, str);
    ss.clear();
    ss << str;
    ss >> n >> m;
    int s = 0, t = n+m+1;
    dinic.init(t);
    int sum = 0;
    for (int i = 1, j, w; i <= n; ++i) {
        getline(cin, str);
        ss.clear();
        ss << str;
        ss >> w;
        sum += w;
        dinic.add_edge(s, i, w);
        while (ss >> j)
            dinic.add_edge(i, j+n, INF);
    }
    for (int i = 1, w; i <= m; ++i) {
        cin >> w;
        dinic.add_edge(i+n, t, w);
    }
    int res = sum-dinic.work(s, t);
    #ifdef DEBUG
    for (int i = 1; i <= t; ++i) cout << dinic.dep[i] << " \n"[i==t];
    #endif
    vector<int> choose;
    for (int i = 1; i <= n; ++i)
        if (dinic.dep[i]) choose.emplace_back(i);
    for (int i = 0, sz = choose.size(); i < sz; ++i)
        cout << choose[i] << " \n"[i==sz-1];
    choose.clear();
    for (int i = 1; i <= m; ++i)
        if (dinic.dep[i+n]) choose.emplace_back(i);
    for (int i = 0, sz = choose.size(); i < sz; ++i)
        cout << choose[i] << " \n"[i==sz-1];
    cout << res << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}