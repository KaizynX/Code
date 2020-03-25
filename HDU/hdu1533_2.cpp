/*
 * @Author: Kaizyn
 * @Date: 2020-03-22 19:37:53
 * @LastEditTime: 2020-03-22 23:30:43
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 2e2+7;
const int M = 1e4+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;
const int dir[] = {0,-1,0,1,0};

template <typename T>
struct MCMF
{
    struct Edge
    {
        int v, nex;
        T w, c; // edge wight and cost
        Edge(const int &_v, const int &_nex, const T &_w, const T &_c) \
        : v(_v), nex(_nex), w(_w), c(_c) {}
    };
    vector<Edge> e;
    int n, s, t;
    int fir[N], vis[N], pre[N];
    T incf[N], dis[N];
    void init(const int &_n) {
        n = _n;
        e.clear();
        e.reserve(M<<1);
        memset(fir, -1, sizeof(int)*(n+3));
    }
    void add_edge(const int &u, const int &v, const T &w, const T &c) {
        e.emplace_back(v, fir[u], w, c); fir[u] = e.size()-1;
        e.emplace_back(u, fir[v], 0, -c); fir[v] = e.size()-1;
    }
    pair<T, T> work(const int &_s, const int &_t) {
        s = _s; t = _t;
        T maxflow = 0, mincost = 0;
        while (spfa()) {
            for (int u = t, id; u != s; u = e[id^1].v) {
                id = pre[u];
                e[id].w -= incf[t];
                e[id^1].w += incf[t];
                mincost += incf[t]*e[id].c;
            }
            maxflow += incf[t];
        }
        return {maxflow, mincost};
    }
    bool spfa() {
        queue<int> q;
        memset(dis, 0x3f, sizeof(T)*(n+3));
        memset(vis, 0, sizeof(int)*(n+3));
        q.push(s);
        dis[s] = 0;
        incf[s] = INF;
        incf[t] = 0;
        while (q.size()) {
            int u = q.front();
            q.pop();
            vis[u] = 0;
            for (int i = fir[u], v; i != -1; i = e[i].nex) {
                v = e[i].v;
                if (!e[i].w || dis[v] <= dis[u]+e[i].c) continue;
                dis[v] = dis[u]+e[i].c;
                incf[v] = min(incf[u], e[i].w);
                pre[v] = i;
                if (vis[v]) continue;
                q.push(v);
                vis[v] = 1;
            }
        }
        return incf[t];
    }
};

int n, m;
char a[N][N];
vector<pii> man, hse;
MCMF<int> mcmf;

inline int dis(const int &i, const int &j)
{
    return abs(man[i-1].first-hse[j-1].first)+abs(man[i-1].second-hse[j-1].second);
}

inline int solve()
{
    int s = 201, t = 202;
    man.clear();
    hse.clear();
    mcmf.init(202);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (a[i][j] == 'H') {
                hse.emplace_back(i, j);
            } else if (a[i][j] == 'm') {
                man.emplace_back(i, j);
            }
        }
    }
    for (int i = 1; i <= (int)man.size(); ++i)
        mcmf.add_edge(s, i, 1, 0);
    for (int i = 1; i <= (int)hse.size(); ++i)
        mcmf.add_edge(i+100, t, 1, 0);
    for (int i = 1; i <= (int)man.size(); ++i) {
        for (int j = 1; j <= (int)hse.size(); ++j) {
            mcmf.add_edge(i, j+100, 1, dis(i, j));
        }
    }
    return mcmf.work(s, t).second;
}

signed main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while (cin >> n >> m && n|m) {
        for (int i = 1; i <= n; ++i) cin >> (a[i]+1);
        cout << solve() << endl;
    }
    return 0;
}