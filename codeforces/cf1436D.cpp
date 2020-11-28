/*
 * @Author: Kaizyn
 * @Date: 2020-10-24 22:02:47
 * @LastEditTime: 2020-10-24 22:25:19
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 998244353;
const int INF = 0x3f3f3f3f;
const int N = 2e5+7;

int n;
int a[N], p[N], num[N];
long long sum[N];
vector<int> e[N];

long long dfs(int u) {
  long long mx = 0;
  sum[u] = a[u];
  num[u] = !e[u].size();
  for (int i = 0, v; i < (int)e[u].size(); ++i) {
    v = e[u][i];
    mx = max(mx, dfs(v));
    num[u] += num[v];
    sum[u] += sum[v];
  }
  if (sum[u] <= mx*num[u]) return mx;
  return (sum[u]+num[u]-1)/num[u];
}

inline void solve() {
  cin >> n;
  for (int i = 2; i <= n; ++i) {
    cin >> p[i];
    e[p[i]].emplace_back(i);
  }
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cout << dfs(1) << endl;
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
/*
2
1
2 1
*/