/*
 * @Author: Kaizyn
 * @Date: 2020-07-23 21:56:56
 * @LastEditTime: 2020-07-23 22:03:59
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e4+7;

int n, res;
int dp[N];
vector<pii> e[N];

void dfs(const int &u, const int &fa) {
  set<int> st;
  dp[u] = 0;
  for (const pii &ee : e[u]) {
    int v = ee.first, w = ee.second;
    if (v == fa) continue; 
    dfs(v, u);
    st.insert(dp[v]+w);
    if (st.size() > 2) st.erase(st.begin());
  }
  if (st.size()) {
    dp[u] = *st.rbegin();
    if (st.size() >= 2) res = max(res, dp[u]+*st.begin());
  }
  res = max(res, dp[u]);
}

inline void solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v, 1);
    e[v].emplace_back(u, 1);
  }
  dfs(1, 0);
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}