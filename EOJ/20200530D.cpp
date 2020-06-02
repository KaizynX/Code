/*
 * @Author: Kaizyn
 * @Date: 2020-05-30 12:52:52
 * @LastEditTime: 2020-05-30 12:57:13
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

struct DSU
{
    int fa[N];
    void init(int sz) { for (int i = 0; i <= sz; ++i) fa[i] = i; }
    int get(int s) { return s == fa[s] ? s : fa[s] = get(fa[s]); }
    int& operator [] (int i) { return fa[get(i)]; }
    bool merge(int x, int y) {
        int fx = get(x), fy = get(y);
        if (fx == fy) return false;
        fa[fx] = fy; return true;
    }
};

struct Node {
  int x, y;
  friend bool operator <(const Node &lhs, const Node &rhs) {
    return make_pair(lhs.x, lhs.y) < make_pair(rhs.x, rhs.y);
  }
};

int n, m;
int deg[N];
Node e[N];
DSU dsu;

inline void solve() {
  cin >> n >> m;
  for (int i = 1; i <= m; ++i) {
    cin >> e[i].x >> e[i].y;
    if (e[i].x < e[i].y) swap(e[i].x, e[i].y);
  }
  sort(e+1, e+m+1);
  dsu.init(n);
  for (int i = 1; i <= m; ++i) {
    if (dsu[e[i].x] == dsu[e[i].y]) continue;
    dsu.merge(e[i].x, e[i].y);
    ++deg[e[i].x]; ++deg[e[i].y];
  }
  int res = 0;
  for (int i = 1; i <= n; ++i) res = max(res, deg[i]);
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