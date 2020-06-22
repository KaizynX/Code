/*
 * @Author: Kaizyn
 * @Date: 2020-06-13 15:23:49
 * @LastEditTime: 2020-06-13 15:29:38
 */ 
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 4e4+7;

int n, m;
int dp[N], lazy[N];
vector<int> e[N];

inline void solve() {
  cin >> n >> m;
  for (int i = 1, u, v; i <= m; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
  }
  dp[1] = 1;
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    if (dp[i]) lazy[i] ^= 1;
    if (lazy[i]) for (const int &j : e[i]) {
      dp[j] ^= 1;
      lazy[j] ^= 1;
    }
  }
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