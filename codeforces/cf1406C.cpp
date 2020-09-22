/*
 * @Author: Kaizyn
 * @Date: 2020-09-12 22:57:43
 * @LastEditTime: 2020-09-12 23:13:19
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n;
int num[N], mxv[N];
vector<int> e[N], res;

void dfs1(int u, int fa) {
  num[u] = 1;
  mxv[u] = 0;
  for (int &v : e[u]) if (v != fa) {
    dfs1(v, u);
    num[u] += num[v];
    mxv[u] = max(mxv[u], num[v]);
  }
}

void dfs2(int u, int fa, int val) {
  mxv[u] = max(mxv[u], val);
  for (int &v : e[u]) if (v != fa) {
    dfs2(v, u, n-num[v]);
  }
  if (res.size() && mxv[u] < mxv[res[0]]) res.clear();
  if (res.empty() || mxv[u] == mxv[res[0]]) res.emplace_back(u);
}

inline void solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  dfs1(1, 0);
  dfs2(1, 0, 0);
  if (n == 2 || res.size() == 1) {
    cout << 1 << " " << e[1][0] << endl;
    cout << 1 << " " << e[1][0] << endl;
  } else {
    int son = 0;
    for (int &v : e[res[0]]) if (v != res[1]) son = v;
    cout << res[0] << " " << son << endl;
    cout << res[1] << " " << son << endl;
  }
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    res.clear();
    for (int i = 1; i <= n; ++i) {
      e[i].clear();
    }
  }
  return 0;
}