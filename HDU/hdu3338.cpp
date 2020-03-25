/*
 * @Author: Kaizyn
 * @Date: 2020-03-24 17:57:22
 * @LastEditTime: 2020-03-24 21:36:14
 */
#include <bits/stdc++.h>

#define DEBUG

using namespace std;

const int N = 1e4+7;
const int M = 3e4+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
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
    T get_val(const int &x) {
        // T res = e[fir[x]].w;
        // return res >= 0 ? 8-res : -res;
        return 8-e[fir[x]].w;
    }
};

int n, m;
int a[107][107][2];
string str[107][107];
ISAP<int> isap;

inline void solve()
{
    int s = n*m+1, t = n*m+2;
    isap.init(n*m+2);
    stringstream ss;
    string sss[2];
    function<int(int, int)> mp = [&](int x, int y) { return x*m+y+1; };
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (str[i][j] == ".......") {
                a[i][j][0] = a[i][j][1] = -1;
            } else {
                sss[0] = str[i][j].substr(0, 3);
                sss[1] = str[i][j].substr(4, 3);
                for (int k = 0; k < 2; ++k) {
                    if (sss[k] == "XXX") a[i][j][k] = -2;
                    else {
                        ss.clear();
                        ss << sss[k];
                        ss >> a[i][j][k];
                    }
                }
            }
        }
    }
    #ifdef DEBUG
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "(" << a[i][j][0] << "," << a[i][j][1] << ")" << " \n"[j==m-1];
        }
    }
    #endif
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j][0] >= 0) {
                for (int k = i+1; k < n && a[k][j][0] == -1; ++k) {
                    isap.add_edge(mp(i, j), mp(k, j), 8);
                    --a[i][j][0];
                }
                isap.add_edge(s, mp(i, j), a[i][j][0]);
            }
            if (a[i][j][1] >= 0) {
                for (int k = j+1; k < m && a[i][k][0] == -1; ++k) {
                    isap.add_edge(mp(i, k), mp(i, j), 8);
                    --a[i][j][1];
                }
                isap.add_edge(mp(i, j), t, a[i][j][1]);
            }
        }
    }
    #ifdef DEBUG
    cout << isap.work(s, t) << endl;
    #else
    isap.work(s, t);
    #endif
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j][0] == -1) {
                cout << isap.get_val(mp(i, j))+1;
            } else {
                cout << "_";
            }
            cout << " \n"[j == m-1];
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> m) {
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> str[i][j];
        solve();
    }
    return 0;
}