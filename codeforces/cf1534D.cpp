/*
 * @Author: Kaizyn
 * @Date: 2021-07-04 13:46:53
 * @LastEditTime: 2021-07-04 13:54:14
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

const double eps = 1e-7;
const double PI = acos(-1);
typedef pair<int, int> pii;
typedef long long ll;
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 2e3+7;

int n;
int d[N];
set<int> e[N];

void query(int x) {
  cout << "? " << x << endl;
  for (int i = 1; i <= n; ++i) cin >> d[i];
}

void dfs(int u, int fa = 0) {
  for (auto &v : e[u]) if (v != fa) {
    cout << u << ' ' << v << endl;
    dfs(v, u);
  }
}

inline void solve() {
  cin >> n;
  query(1);
  vector<int> v[2];
  for (int i = 2; i <= n; ++i) {
    v[d[i]&1].emplace_back(i);
    if (d[i] == 1) {
      e[1].insert(i);
      e[i].insert(1);
    }
  }
  int c = v[1].size() <= v[0].size();
  for (int &p : v[c]) {
    query(p);
    for (int i = 1; i <= n; ++i) {
      if (d[i] == 1) {
        e[p].insert(i);
        e[i].insert(p);
      }
    }
  }
  cout << "!\n";
  dfs(1);
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  // cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}