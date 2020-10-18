/*
 * @Author: Kaizyn
 * @Date: 2020-10-02 10:10:20
 * @LastEditTime: 2020-10-02 10:22:11
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

struct Node {
  int u, v, w;
  bool operator <(const Node &nex) const {
    return w > nex.w;
  }
};

struct DSU {
  int fa[N];
  void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
  int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
  int& operator [] (int i) { return fa[get(i)]; }
  bool merge(int x, int y) { // merge x to y
    int fx = get(x), fy = get(y);
    if (fx == fy) return false;
    fa[fx] = fy; return true;
  }
};

int n, m, tot;
int a[N], b[N];
Node e[N];
DSU dsu;

inline void solve() {
  cin >> m >> n;
  for (int i = 1; i <= m; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) cin >> b[i];
  long long res = 0;
  for (int i = 1, j, s; i <= m; ++i) {
    cin >> s;
    while (s--) {
      cin >> j;
      e[++tot] = Node{i, m+j, a[i]+b[j]};
      res += e[tot].w;
    }
  }
  dsu.init(n+m);
  sort(e+1, e+tot+1);
  for (int i = 1; i <= tot; ++i) {
    if (dsu.merge(e[i].u, e[i].v)) {
      res -= e[i].w;
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