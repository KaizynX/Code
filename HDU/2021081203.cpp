/*
 * @Author: Kaizyn
 * @Date: 2021-08-12 12:12:44
 * @LastEditTime: 2021-08-12 12:16:14
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
const int N = 5e3+7;


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

struct Node {
  int x, y;
  ll d;
  bool operator <(const Node &b) const {
    return d < b.d;
  }
};

int n, m;
ll x[N], y[N];
Node e[N*N];
DSU dsu;

inline void solve() {
  cin >> n;
  m = 0;
  dsu.init(n);
  for (int i = 1; i <= n; ++i) {
    cin >> x[i] >> y[i];
    for (int j = 1; j < i; ++j) {
      e[++m] = Node{i, j, (x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])};
    }
  }
  sort(e+1, e+m+1);
  for (int i = 1, t = 0; i <= m; ++i) {
    if ((t += dsu.merge(e[i].x, e[i].y)) >= n-1) {
      cout << e[i].d << '\n';
      return;
    }
  }
}

signed main() {
#ifdef ONLINE_JUDGE
  ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#endif
  int T = 1;
  cin >> T; // scanf("%d", &T);
  for (int t = 1; t <= T; ++t) {
    solve();
  }
  return 0;
}