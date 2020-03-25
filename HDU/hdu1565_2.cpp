/*
 * @Author: Kaizyn
 * @Date: 2020-03-21 19:19:58
 * @LastEditTime: 2020-03-21 19:40:04
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 4e2+7;
const int M = 2e3+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int dir[] = {0, -1, 0, 1, 0};

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

int n;
int a[25][25];
ISAP<int> isap;

inline void solve()
{
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> a[i][j];
            sum += a[i][j];
        }
    }
    int s = n*n+1, t = n*n+2;
    isap.init(t);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if ((i+j)&1) {
                isap.add_edge(s, i*n+j+1, a[i][j]);
                for (int k = 0, nx, ny; k < 4; ++k) {
                    nx = i+dir[k];
                    ny = j+dir[k+1];
                    if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
                    isap.add_edge(i*n+j+1, nx*n+ny+1, INF);
                }
            } else {
                isap.add_edge(i*n+j+1, t, a[i][j]);
            }
        }
    }
    cout << sum-isap.work(s, t) << endl;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n) solve();
    return 0;
}