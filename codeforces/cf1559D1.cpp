/*
 * @Author: Kaizyn
 * @Date: 2021-08-15 22:42:59
 * @LastEditTime: 2021-08-15 23:00:08
 */
#include <bits/stdc++.h>

// #define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
const double eps = 1e-7;
const double PI = acos(-1);
const int MOD = 998244353; // 1e9+7;
const int INF = 0x3f3f3f3f;
// const ll INF = 1e18;
const int N = 1e3+7;

struct DSU {
  vector<int> fa;
  void init(int n) { fa = vector<int>(n+1); iota(fa.begin(), fa.end(), 0); }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    x = get(x); y = get(y);
    return x == y ? false : (fa[x] = y, true);
  }
};

int n, m[2];
DSU dsu[2];
vector<pii> res;

inline void solve() {
  cin >> n >> m[0] >> m[1];
  res.clear();
  for (int i : {0, 1}) {
    dsu[i].init(n);
    for (int j = 1, u, v; j <= m[i]; ++j) {
      cin >> u >> v;
      dsu[i].merge(u, v);
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = i+1; j <= n; ++j) {
      if (dsu[0][i] != dsu[0][j] && dsu[1][i] != dsu[1][j]) {
        dsu[0].merge(i, j);
        dsu[1].merge(i, j);
        res.emplace_back(i, j);
      }
    }
  }
  cout << res.size() << '\n';
  for (auto i : res) cout << i.first << ' ' << i.second << '\n';
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