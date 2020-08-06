/*
 * @Author: Kaizyn
 * @Date: 2020-07-23 21:56:56
 * @LastEditTime: 2020-07-23 22:11:40
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
vector<int> e[N];

void dfs(const int &u, const int &fa) {
  int d1 = 0, d2 = 0;
  for (const int &v : e[u]) if (v != fa) {
    dfs(v, u);
    if (dp[v]+1 > d1) {
      d2 = d1;
      d1 = dp[v]+1;
    } else if (dp[v]+1 > d2) {
      d2 = dp[v]+1;
    }
  }
  dp[u] = d1;
  res = max(res, d1+d2);
}

inline void solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
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