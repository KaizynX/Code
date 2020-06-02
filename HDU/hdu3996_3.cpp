/*
 * @Author: Kaizyn
 * @Date: 2020-05-31 11:17:50
 * @LastEditTime: 2020-06-01 22:18:19
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const long long INF = 1e10;
const int N = 3e3+7;

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

int n, m;
Dinic<long long> dinic;

inline long long solve() {
  cin >> n;
  dinic.init(n*25+2);
  int st = n*25+1, ed = n*25+2;
  long long sum = 0, cost, val;
  for (int i = 0; i < n; ++i) {
    cin >> m;
    for (int j = 1, cnt, x, y; j <= m; ++j) {
      cin >> cost >> val >> cnt;
      val -= cost;
      if (val > 0) {
        sum += val;
        dinic.add_edge(st, i*25+j, val);
      } else {
        dinic.add_edge(i*25+j, ed, -val);
      }
      while (cnt--) {
        cin >> x >> y;
        dinic.add_edge(i*25+j, (x-1)*25+y, INF);
      }
    }
  }
  return max(0ll, sum-dinic.work(st, ed));
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << "Case #" << t << ": " << solve() << endl;
  }
  return 0;
}