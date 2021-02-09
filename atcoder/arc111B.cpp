/*
 * @Author: Kaizyn
 * @Date: 2021-01-09 21:50:11
 * @LastEditTime: 2021-01-10 10:22:49
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
const int N = 4e5+7;

int n;
int a[N][2], vc[N], ve[N], deg[N];
vector<int> e[N];
set<pii> q;

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i][0] >> a[i][1];
    ++deg[a[i][0]];
    ++deg[a[i][1]];
    e[a[i][0]].emplace_back(i);
    e[a[i][1]].emplace_back(i);
  }
  for (int i = 1; i <= 4e5; ++i) {
    if (deg[i]) q.insert({deg[i], i});
  }
  int res = 0;
  while (q.size()) {
    int u = q.begin()->second;
    q.erase(q.begin());
    if (vc[u]) continue;
    vc[u] = 1;
    while (e[u].size() && ve[e[u].back()]) e[u].pop_back();
    for (int &v : e[u]) {
      if (ve[v]) continue;
      int k = a[v][a[v][0] == u];
      if (vc[k]) continue;
      q.erase(q.find({deg[k], k}));
      if (--deg[k] > 0) q.insert({deg[k], k});
    }
    if (e[u].size()) {
      ++res;
      ve[e[u].back()] = 1;
    }
  }
  cout << res << endl;
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#endif
  int T = 1;
  // cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}