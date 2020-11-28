/*
 * @Author: Kaizyn
 * @Date: 2020-10-25 15:46:29
 * @LastEditTime: 2020-10-25 15:59:27
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

int n;
int a[N], b[N], pb[N], vis[N];
vector<int> e[N];
DSU dsu;

void print(int u, int fa) {
  for (int &v : e[u]) if (v != fa && v != u) {
    if (u && v) cout << u << " " << v << endl;
    print(v, u);
  }
}

void add_edge(int u, int v) {
  e[u].emplace_back(v);
  e[v].emplace_back(u);
}

inline void solve() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i) {
    cin >> b[i];
    pb[b[i]] = i;
  }
  dsu.init(n+1);
  for (int i = 1, last = 0; i <= n; ++i) {
    if (vis[a[i]]) continue;
    add_edge(last, a[i]);
    last = a[i];
    for (int j = pb[a[i]]; j <= n && !vis[b[j]]; j = dsu[j]) {
      vis[b[j]] = 1;
      dsu.merge(j, j+1);
      add_edge(a[i], b[j]);
    }
  }
  cout << "YES" << endl;
  print(0, 0);
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