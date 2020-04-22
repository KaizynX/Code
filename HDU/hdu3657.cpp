/*
 * @Author: Kaizyn
 * @Date: 2020-04-13 12:48:48
 * @LastEditTime: 2020-04-13 13:06:27
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 3e3+7;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int dir[] = {0,-1,0,1,0};

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

int n, m, k;
int a[N][N], c[N][N];
Dinic<int> dinic;

inline int mp(const int &x, const int &y) { return (x-1)*m+y; }

inline void solve()
{
    int sum = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            cin >> a[i][j];
            sum += a[i][j];
            c[i][j] = a[i][j];
        }
    }
    for (int i = 1, x, y; i <= k; ++i) {
        cin >> x >> y;
        c[x][y] = INF;
    }
    int s = n*m+1, t = n*m+2;
    dinic.init(n*m+2);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if ((i+j)&1) {
                dinic.add_edge(s, mp(i, j), c[i][j]);
                for (int k = 0, x, y; k < 4; ++k) {
                    x = i+dir[k];
                    y = j+dir[k+1];
                    if (x < 1 || y < 1 || x > n || y > m) continue;
                    dinic.add_edge(mp(i, j), mp(x, y), 2*(a[i][j]&a[x][y]));
                }
            } else {
                dinic.add_edge(mp(i, j), t, c[i][j]);
            }
        }
    }
    cout << sum-dinic.work(s, t) << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> m >> k) {
        solve();
    }
    return 0;
}