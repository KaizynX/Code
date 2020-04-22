/*
 * @Author: Kaizyn
 * @Date: 2020-04-18 13:51:56
 * @LastEditTime: 2020-04-18 14:04:48
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e3+57;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;

template <typename T>
struct ISAP
{
    struct EDGE
    {
        int v, nex;
        T w;
        EDGE(const int &_v, const int &_nex, const T &_w) : v(_v), nex(_nex), w(_w) {}
    };
    vector<EDGE> e;
    int n, s, t;
    T maxflow;
    int fir[N], gap[N], dep[N];
    T work(const int &_s, const int &_t) {
        s = _s; t = _t;
        maxflow = 0;
        bfs();
        while (dep[s] < n) dfs(s, INF);
        return maxflow;
    }
    void init(const int &_n) {
        n = _n;
        e.clear();
        e.reserve(N<<2);
        memset(fir, -1, sizeof(int)*(n+3));
    }
    void add_edge(const int &u, const int &v, const T &w) {
        e.emplace_back(v, fir[u], w); fir[u] = e.size()-1;
        e.emplace_back(u, fir[v], 0); fir[v] = e.size()-1;
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

int n, e, sum;
int c[N], m[N];
int a[N][10];
ISAP<long long> isap;

inline bool check(const int &x) {
    int s = n+8, t = n+9;
    isap.init(n+9);
    for (int i = 1; i <= 7; ++i) {
        long long val = 1ll*e*(x/7+(x%7 >= i));
        isap.add_edge(s, n+i, val);
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m[i]; ++j) {
            isap.add_edge(n+a[i][j], i, c[i]);
        }
        isap.add_edge(i, t, c[i]);
    }
    return isap.work(s, t) == sum;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> e;
    for (int i = 1; i <= n; ++i) {
        cin >> c[i] >> m[i];
        for (int j = 1; j <= m[i]; ++j) cin >> a[i][j];
        sum += c[i];
    }
    int l = 1, r = 1e9;
    while (l < r) {
        int mid = (l+r)>>1;
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    cout << l << endl;
    return 0;
}