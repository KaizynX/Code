/*
 * @Author: Kaizyn
 * @Date: 2020-08-15 19:04:14
 * @LastEditTime: 2020-08-15 19:09:22
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 1e6+7;

int n, m, p;
int dn[N], dm[N];
queue<int> q;

void bfs(const int &s, int dp[]) {
  for (int i = 0; i < p; ++i) dp[i] = -1;
  dp[s] = 0;
  q.push(s);
  while (q.size()) {
    int u = q.front(), v;
    q.pop();
    v = u*2%p;
    if (dp[v] == -1) {
      dp[v] = dp[u]+1;
      q.push(v);
    }
    v = (u+1)%p;
    if (dp[v] == -1) {
      dp[v] = dp[u]+1;
      q.push(v);
    }
  }
}

inline void solve() {
  cin >> n >> m >> p;
  bfs(n, dn);
  bfs(m, dm);
  int res = dn[m];
  for (int i = 0; i < p; ++i) {
    res = min(res, dn[i]+dm[i]);
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