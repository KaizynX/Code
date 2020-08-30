/*
 * @Author: Kaizyn
 * @Date: 2020-08-29 20:53:14
 * @LastEditTime: 2020-08-29 20:54:41
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

struct DSU {
  int fa[N], num[N];
  void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i, num[i] = 1; }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) {
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    if (num[fx] >= num[fy]) num[fx] += num[fy], fa[fy] = fx;
    else num[fy] += num[fx], fa[fx] = fy;
    return true;
  }
} dsu;

int n, m;

inline void solve() {
  cin >> n >> m;
  dsu.init(n);
  for (int i = 1, x, y; i <= m; ++i) {
    cin >> x >> y;
    dsu.merge(x, y);
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) {
    res = max(res, dsu.num[i]);
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