/*
 * @Author: Kaizyn
 * @Date: 2020-03-26 17:23:27
 * @LastEditTime: 2020-08-09 14:01:03
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const int N = 1e6+7;
const int MOD = 1e9+7;
const double eps = 1e-7;
const int INF = 0x3f3f3f3f;
typedef pair<int, int> pii;

struct TWO_SAT { // node stkrt from 0
  int top, _dfn, _scc;
  int dfn[N<<1], low[N<<1], stk[N<<1], scc[N<<1], res[N];
  vector<int> e[N<<1];
  void init(const int &n) {
    top = 0;
    memset(dfn, 0, sizeof(int)*n*2);
    memset(low, 0, sizeof(int)*n*2);
    for (int i = 0; i < n<<1; ++i) vector<int>().swap(e[i]);
  }
  // if u then v
  void add_edge(const int &u, const int &v) {
    e[u].emplace_back(v);
  }
  void add_edge(const int &u, const int &uv, const int &v, const int &vv) {
    e[u<<1^uv].emplace_back(v<<1^vv);
  }
  // pt i ==> i<<1 && i<<1|1 ==> 0 && 1
  inline bool work(const int &n) {
    for (int i = 0; i <= n<<1; ++i)
      if (!dfn[i]) tarjan(i);
    for (int i = 0; i < n; ++i) {
      if (scc[i<<1] == scc[i<<1|1]) return false;
      res[i] = scc[i<<1] > scc[i<<1|1];
    }
    return true;
  }
  void tarjan(const int &u) {
    dfn[u] = low[u] = ++_dfn;
    stk[++top] = u;
    for (int &v : e[u]) {
      if (!dfn[v]) {
        tarjan(v);
        low[u] = min(low[u], low[v]);
      } else if (!scc[v]) {
        low[u] = min(low[u], dfn[v]);
      }
    }
    if (dfn[u] == low[u]) {
      ++_scc;
      do {
        scc[stk[top]] = _scc;
      } while (stk[top--] != u);
    }
  }
};

int n, m;
TWO_SAT sat;

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

  cin >> n >> m;
  sat.init(n);
  for (int k = 1, i, j, a, b; k <= m; ++k) {
    cin >> i >> a >> j >> b;
    --i; --j;
    sat.add_edge(i, a^1, j, b);
    sat.add_edge(j, b^1, i, a);
  }
  if (!sat.work(n)) return cout << "IMPOSSIBLE\n", 0;
  cout << "POSSIBLE\n";
  for (int i = 0; i < n; ++i) cout << sat.res[i] << " \n"[i==n-1];
  return 0;
}