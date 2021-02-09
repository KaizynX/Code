/*
 * @Author: Kaizyn
 * @Date: 2021-02-03 10:36:08
 * @LastEditTime: 2021-02-03 10:51:20
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e3+7;

struct TWO_SAT { // node stkrt from 0
  int top, _dfn, _scc;
  int dfn[N<<1], low[N<<1], stk[N<<1], scc[N<<1], res[N];
  vector<int> e[N<<1];
  void init(const int &n) {
    top = 0;
    memset(dfn, 0, sizeof(int)*n*2);
    memset(low, 0, sizeof(int)*n*2);
    memset(scc, 0, sizeof(int)*n*2);
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

int n;
int a[N][N];
TWO_SAT two_sat;

inline bool solve() {
  string str;
  cin >> n;
  // row [0, n) col [n, 2n)
  two_sat.init(n*2);
  for (int i = 0; i < n; ++i) {
    cin >> str;
    for (int j = 0; j < n; ++j) {
      a[i][j] = str[j]-'0';
    }
  }
  for (int i = 0; i < n; ++i) {
    cin >> str;
    for (int j = 0, b; j < n; ++j) {
      b = str[j]-'0';
      if (a[i][j]^b) {
        two_sat.add_edge(i, 0, n+j, 1);
        two_sat.add_edge(i, 1, n+j, 0);
        two_sat.add_edge(n+j, 0, i, 1);
        two_sat.add_edge(n+j, 1, i, 0);
      } else {
        two_sat.add_edge(i, 0, n+j, 0);
        two_sat.add_edge(i, 1, n+j, 1);
        two_sat.add_edge(n+j, 0, i, 0);
        two_sat.add_edge(n+j, 1, i, 1);
      }
    }
  }
  return two_sat.work(n*2);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cout << (solve() ? "YES" : "NO") << endl;
  }
  return 0;
}