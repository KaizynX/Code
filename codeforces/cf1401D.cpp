/*
 * @Author: Kaizyn
 * @Date: 2020-08-28 14:19:16
 * @LastEditTime: 2020-08-28 14:40:17
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;
const int N = 1e5+7;

int n, m;
int sum[N];
vector<long long> cnt;
vector<int> e[N], p;

void dfs(const int &u, const int &fa) {
  sum[u] = 1;
  for (const int &v : e[u]) if (v != fa) {
    dfs(v, u);
    cnt.emplace_back(1ll*sum[v]*(n-sum[v]));
    sum[u] += sum[v];
  }
}

inline void solve() {
  cin >> n;
  for (int i = 1, u, v; i < n; ++i) {
    cin >> u >> v;
    e[u].emplace_back(v);
    e[v].emplace_back(u);
  }
  cin >> m;
  p.resize(m);
  for (int i = 0; i < m; ++i) cin >> p[i];
  dfs(1, 0);
  long long res = 0;
  sort(cnt.begin(), cnt.end());
  reverse(cnt.begin(), cnt.end());
  sort(p.begin(), p.end());
  reverse(p.begin(), p.end());
  while (cnt.size() > p.size()) {
    (res += cnt.back()) %= MOD;
    cnt.pop_back();
  }
  while (cnt.size() > 1) {
    (res += cnt.back()*p.back()) %= MOD;
    cnt.pop_back();
    p.pop_back();
  }
  long long t = 1;
  for (auto &i : p) t = t*i%MOD;
  (res += cnt[0]*t) %= MOD;
  cout << res << endl;
}

signed main() {
  ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int T = 1;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    solve();
    cnt.clear();
    for (int i = 1; i <= n; ++i) {
      e[i].clear();
    }
  }
  return 0;
}